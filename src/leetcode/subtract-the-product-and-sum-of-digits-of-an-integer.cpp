//
// Created by saubhik on 2019/12/19.
//
#include <iostream>

class Solution {
public:
  // 100%, 0ms run-time; 100%, 8.2MB memory.
  // O(log_{10}n) time, O(1) space.
  static int subtractProductAndSum(int n) {
    int prod = 1, sum = 0;
    while (n) {
      prod *= n % 10;
      sum += n % 10;
      n /= 10;
    }
    return prod - sum;
  }
};

int main() { printf("%d", Solution::subtractProductAndSum(4421)); }
