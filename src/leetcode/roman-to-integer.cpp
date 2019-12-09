//
// Created by saubhik on 2019/12/09.
//
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // 59.52% run-time, 100% memory
  // O(n) time, O(1) space.
  static int romanToInt(string s) {
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (i + 1 < s.length() &&
          ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
           (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
           (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))))
        ans += romanCharToInt(s[i + 1]) - romanCharToInt(s[i]), ++i;
      else
        ans += romanCharToInt(s[i]);
    }
    return ans;
  }

private:
  static int romanCharToInt(char c) {
    switch (c) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    default:
      return 0;
    }
  }
};

int main() {
  printf("%d\n", Solution::romanToInt("III"));
  printf("%d\n", Solution::romanToInt("IV"));
  printf("%d\n", Solution::romanToInt("IX"));
  printf("%d\n", Solution::romanToInt("LVIII"));
  printf("%d", Solution::romanToInt("MCMXCIV"));
}
