//
// Created by saubhik on 2019/12/08.
//
#include <cstdio>

class Solution {
public:
  // 100% run-time, 100% memory.
  static int addDigits(int num) {
    if (!num)
      return 0;
    return num % 9 == 0 ? 9 : num % 9;
  }
};

int main() {
  printf("%d\n", Solution::addDigits(38));
  printf("%d", Solution::addDigits(0));
}
