//
// Created by saubhik on 2019/11/03.
//
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  static vector<string> subdomainVisits(vector<string> &cpdomains) {
    vector<string> ans;
    map<string, int> store;
    int count;
    string::size_type pos, curPos;
    string domain, tmp;

    for (const string &cpdomain : cpdomains) {
      pos = cpdomain.find(' ');
      count = stoi(cpdomain.substr(0, pos));
      domain = cpdomain.substr(pos + 1);

      // keep splitting domain based on '.'
      curPos = domain.find('.');
      tmp = domain;
      store[tmp] += count;

      while (curPos != string::npos) {
        tmp = tmp.substr(curPos + 1);
        // insert tmp into our map
        store[tmp] += count;
        curPos = tmp.find('.');
      }
    }

    ans.reserve(store.size());
    for (const auto &elem : store) {
      ans.push_back(to_string(elem.second) + ' ' + elem.first);
    }

    return ans;
  }
};

int main() {
  vector<string> res, cpdomains = {"9001 discuss.leetcode.com"};
  res = Solution::subdomainVisits(cpdomains);
  for (const string &elem : res)
    printf("%s ", elem.c_str());

  printf("\n");

  cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com",
               "5 wiki.org"};
  res = Solution::subdomainVisits(cpdomains);
  for (const string &elem : res)
    printf("%s ", elem.c_str());
}
