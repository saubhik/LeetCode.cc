//
// Created by saubhik on 2020/03/15.
//
#include <cstdio>

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Power of
  // Two. Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for
  // Power of Two.
  //
  // O(1) time, O(1) space.
  // Idea: (n & (n - 1)) un-sets the least significant set bit.
  static bool isPowerOfTwo(unsigned long n) {
    return n != 0 && (n & (n - 1)) == 0;
  }
};

int main() {
  printf("%d\n", Solution::isPowerOfTwo(1));
  printf("%d\n", Solution::isPowerOfTwo(16));
  printf("%d\n", Solution::isPowerOfTwo(218));
  printf("%d\n", Solution::isPowerOfTwo(0));
  printf("%d\n", Solution::isPowerOfTwo(-2147483648));
}
