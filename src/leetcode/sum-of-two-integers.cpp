//
// Created by saubhik on 2019/12/19.
//
#include <iostream>

class Solution {
public:
  // O(n) time, O(1) space.
  // 100%, 0ms, run-time; 100%, 8.1MB, memory.
  static int getSum(int a, int b) {
    int sum, carry;
    while (b) {
      sum = a ^ b;
      carry = (unsigned int)(a & b) << 1;
      a = sum, b = carry;
    }
    return a;
  }
};

int main() {
  printf("%d\n", Solution::getSum(1, 2));
  printf("%d", Solution::getSum(-2, -3));
}
