//
// Created by saubhik on 2019/11/09.
//
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  // super slow, 5.30% runtime, 8.70% memory
  static string reverseWords(const string &s) {
    string ans, temp;
    for (char ch : s) {
      if (ch == ' ') {
        temp += " ";
        ans += temp;
        temp = "";
      } else {
        temp = ch + temp;
      }
    }
    ans += temp;
    return ans;
  }

  // use reverse, ~90% run-time, ~90% memory
  static string reverseWords2(string s) {
    size_t front = 0;
    for (size_t i = 0; i <= s.size(); ++i) {
      if (s[i] == ' ' || i == s.size()) {
        reverse(&s[front], &s[i]);
        front = i + 1;
      }
    }
    return s;
  }
};

int main() {
  printf("%s\n", Solution::reverseWords("Let's take LeetCode contest").c_str());
  printf("%s", Solution::reverseWords2("Let's take LeetCode contest").c_str());
}