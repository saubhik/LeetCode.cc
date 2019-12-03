//
// Created by saubhik on 2019/12/03.
//
#include <cstdio>

class Solution {
public:
  // 50% run-time, 75% memory
  // O(1) time, O(1) space
  static bool canWinNim(int n) { return n % 4 != 0; }
};

int main() { printf("%d", Solution::canWinNim(4)); }
