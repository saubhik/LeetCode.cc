//
// Created by saubhik on 2020/01/08.
//
#include <string>
using namespace std;

class Solution {
public:
  // Runtime: 4 ms, faster than 83.85% of C++ online submissions for Longest
  // Palindrome. Memory Usage: 8.7 MB, less than 100.00% of C++ online
  // submissions for Longest Palindrome.
  //
  // O(n) time, O(1) space.
  static int longestPalindrome(string s) {
    int count[52] = {};
    for (auto &ch : s) {
      if (isupper(ch))
        ++count[ch - 'A' + 26];
      else
        ++count[ch - 'a'];
    }
    int ans = 0;
    bool oddFound = false;
    for (int i = 0; i < 52; ++i) {
      if (count[i] % 2)
        ans += count[i] - 1, oddFound = true;
      else
        ans += count[i];
    }
    return ans + (oddFound ? 1 : 0);
  }
};

int main() {
  printf("%d\n", Solution::longestPalindrome("abccccdd"));
  printf("%d", Solution::longestPalindrome("aaaAaaaa"));
}
