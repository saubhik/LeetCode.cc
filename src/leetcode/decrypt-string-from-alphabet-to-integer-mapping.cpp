//
// Created by saubhik on 2020/01/28.
//
#include <string>
using namespace std;

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decrypt
  // String from Alphabet to Integer Mapping. Memory Usage: 8.5 MB, less than
  // 100.00% of C++ online submissions for Decrypt String from Alphabet to
  // Integer Mapping.
  // O(n) time, O(1) space
  static string freqAlphabets(string s) {
    int n = s.length();
    string ans;
    for (int i = 0; i < n;)
      if (i + 2 < n && s[i + 2] == '#')
        ans.push_back('a' + stoi(s.substr(i, 2)) - 1), i += 3;
      else
        ans.push_back('a' + s[i] - '1'), ++i;
    return ans;
  }
};

int main() {
  printf("%s\n", Solution::freqAlphabets("10#11#12").c_str());
  printf("%s\n", Solution::freqAlphabets("1326#").c_str());
  printf("%s\n", Solution::freqAlphabets("25#").c_str());
  printf("%s",
         Solution::freqAlphabets(
             "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#")
             .c_str());
}
