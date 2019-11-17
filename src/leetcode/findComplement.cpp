//
// Created by saubhik on 2019/11/18.
//
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
  // 100% run-time, 100% memory
  static int findComplement(int num) {
    int p = log2(num) + 1;
    return num ^ (int)(pow(2, p) - 1);
  }
};

class Solution2 {
public:
  // pure bit manipulation
  static int findComplement(int num) {
    unsigned mask = ~0;
    while (num & mask)
      mask <<= 1;
    return ~mask ^ num;
  }
};

int main() {
  printf("%d\n", Solution::findComplement(5));
  printf("%d\n", Solution2::findComplement(5));
  printf("%d\n", Solution::findComplement(1));
  printf("%d", Solution2::findComplement(1));
}