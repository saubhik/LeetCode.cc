//
// Created by saubhik on 2019/12/08.
//
#include <string>
using namespace std;

class Solution {
public:
  // 83.96% run-time, 100% memory.
  // O(n) time, O(1) space.
  static char findTheDifference(string s, string t) {
    int mp[26] = {};

    for (auto ch : s)
      ++mp[ch - 'a'];

    for (auto ch : t) {
      --mp[ch - 'a'];
      if (mp[ch - 'a'] < 0)
        return ch;
    }

    return '0';
  }
};

class Solution2 {
public:
  // 100% run-time, 88.89% memory.
  // O(n) time, O(1) space.
  // using XOR
  // xor of something with itself is 0.
  // 0 xor something is something.
  static char findTheDifference(string s, string t) {
    char ans = 0;
    for (char ch : s)
      ans ^= ch;
    for (char ch : t)
      ans ^= ch;
    return ans;
  }
};

int main() {
  printf("%c %c\n", Solution::findTheDifference("abcd", "abcde"),
         Solution2::findTheDifference("abcd", "abcde"));
  printf("%c %c", Solution::findTheDifference("a", "aa"),
         Solution::findTheDifference("a", "aa"));
}
