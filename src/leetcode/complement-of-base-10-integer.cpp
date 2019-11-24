//
// Created by saubhik on 2019/11/24.
//
#include <cstdio>

class Solution {
public:
  // 100% run-time, 100% memory
  // O(logN) time
  static int bitwiseComplement(int N) {
    unsigned mask = ~0;
    do
      mask <<= 1;
    while (N & mask);
    return ~mask ^ N;
  }
};

int main() {
  printf("%d\n", Solution::bitwiseComplement(5));
  printf("%d\n", Solution::bitwiseComplement(7));
  printf("%d\n", Solution::bitwiseComplement(0));
  printf("%d", Solution::bitwiseComplement(10));
}
