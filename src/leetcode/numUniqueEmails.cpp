//
// Created by saubhik on 2019/11/03.
//
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  static int numUniqueEmails(vector<string> &emails) {
    string local, domain;
    string::size_type pos;
    set<string> store;
    for (const string &email : emails) {
      pos = email.find('@');
      local = email.substr(0, pos);
      domain = email.substr(pos);
      local.erase(remove(local.begin(), local.end(), '.'), local.end());

      pos = local.find('+');
      if (pos != string::npos) {
        local.erase(pos);
      }

      store.insert(local + domain);
    }
    return store.size();
  }

  // much more cleaner
  static int numUniqueEmails2(vector<string> &emails) {
    unordered_set<string> st;
    for (string &email : emails) {
      string cleanEmail;
      for (char c : email) {
        if (c == '.')
          continue;
        if (c == '+' || c == '@')
          break;
        cleanEmail += c;
      }
      cleanEmail += email.substr(email.find('@'));
      st.insert(cleanEmail);
    }
    return st.size();
  }
};

int main() {
  vector<string> emails = {
      "test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
      "testemail+david@lee.tcode.com", "testemail@leetcode.com"};
  printf("%d\n", Solution::numUniqueEmails(emails));
  printf("%d\n", Solution::numUniqueEmails2(emails));
}
