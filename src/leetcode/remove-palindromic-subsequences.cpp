//
// Created by saubhik on 2020/02/04.
//
#include <string>
using namespace std;

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove
  // Palindromic Subsequences. Memory Usage: 8.6 MB, less than 100.00% of C++
  // online submissions for Remove Palindromic Subsequences.
  //
  // O(n) time, O(1) space
  static int removePalindromeSub(string s) {
    int n = s.length(), i, j;
    for (i = 0, j = n - 1; i < j; ++i, --j)
      if (s[i] != s[j])
        break;
    return s.empty() ? 0 : (i >= j) ? 1 : 2;
  }
};

int main() {
  printf("%d\n", Solution::removePalindromeSub("ababa"));
  printf("%d\n", Solution::removePalindromeSub("abb"));
  printf("%d\n", Solution::removePalindromeSub("baabb"));
  printf("%d\n", Solution::removePalindromeSub("babababbababab"));
  printf("%d", Solution::removePalindromeSub(""));
}
