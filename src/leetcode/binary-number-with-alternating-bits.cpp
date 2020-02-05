//
// Created by saubhik on 2020/02/05.
//
#include <printf.h>

class Solution {
private:
  static int isPowerOfTwo(long n, bool even = false) {
    unsigned int mask = 1;
    short pow = 0;
    while (mask < n)
      mask <<= (unsigned)1, ++pow;
    return even ? (mask == n && pow % 2 == 0) : (mask == n && pow % 2 == 1);
  }

public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary
  // Number with Alternating Bits. Memory Usage: 8.2 MB, less than 85.71% of C++
  // online submissions for Binary Number with Alternating Bits.
  //
  // O(lgn) time, O(1) space.
  static bool hasAlternatingBits(int n) {
    return isPowerOfTwo(3 * n + 1, true) || isPowerOfTwo(3 * n + 2, false);
  }
};

class Solution2 {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary
  // Number with Alternating Bits. Memory Usage: 8.1 MB, less than 100.00% of
  // C++ online submissions for Binary Number with Alternating Bits.
  //
  // courtesy: StefanPochmann
  static bool hasAlternatingBits(int n) { return !((n ^= n / 4) & n - 1); }
};

class Solution3 {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary
  // Number with Alternating Bits. Memory Usage: 8.1 MB, less than 92.86% of C++
  // online submissions for Binary Number with Alternating Bits.
  //
  // courtesy: StefanPochmann
  static bool hasAlternatingBits(int n) { return !((n ^= n / 2) & n + 1); }
};

int main() {
  printf("%d\n", Solution::hasAlternatingBits(5));
  printf("%d\n", Solution::hasAlternatingBits(7));
  printf("%d\n", Solution::hasAlternatingBits(11));
  printf("%d\n", Solution::hasAlternatingBits(715827882));
  printf("%d", Solution::hasAlternatingBits(10));
}
