//
// Created by saubhik on 2020/05/05.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
  static bool isPalindrome(string &s, int i, int j) {
    for (; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }

public:
  // Runtime: 188 ms, faster than 8.26% of C++ online submissions for Valid
  // Palindrome II. Memory Usage: 19.8 MB, less than 100.00% of C++ online
  // submissions for Valid Palindrome II.
  //
  // O(n) time, O(1) space.
  static bool validPalindrome(string s) {
    int count = 0;
    for (int i = 0, j = (int)s.length() - 1; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
      }
    }
    return true;
  }
};

int main() {
  assert(Solution::validPalindrome("aba"));
  assert(Solution::validPalindrome("abca"));
  assert(!Solution::validPalindrome("abc"));
  assert(Solution::validPalindrome("abcdcba"));
  assert(Solution::validPalindrome("abcfdfba"));
  assert(Solution::validPalindrome("xdddbababeccebababddd"));
  assert(Solution::validPalindrome(
      "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdh"
      "ooxfuupuculmgmqfvnbgtapekouga"));
}
