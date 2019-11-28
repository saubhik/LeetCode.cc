//
// Created by saubhik on 2019/11/28.
//
#include <cstdio>

class Solution {
public:
  // 49.10% run-time, 100% memory
  // O(n) time, O(1) space
  static int tribonacci(int n) {
    int pre1 = 1, pre2 = 1, pre3 = 0, tmp;
    if (n == 0)
      return pre3;
    if (n == 1)
      return pre2;
    if (n == 2)
      return pre1;
    for (int i = 3; i <= n; ++i) {
      tmp = pre1 + pre2 + pre3;
      pre3 = pre2;
      pre2 = pre1;
      pre1 = tmp;
    }
    return pre1;
  }
};

class Solution2 {
public:
  // 100% run-time, 100% memory
  static int tribonacci(int n) {
    int arr[38] = {0,         1,          1,         2,         4,
                   7,         13,         24,        44,        81,
                   149,       274,        504,       927,       1705,
                   3136,      5768,       10609,     19513,     35890,
                   66012,     121415,     223317,    410744,    755476,
                   1389537,   2555757,    4700770,   8646064,   15902591,
                   29249425,  53798080,   98950096,  181997601, 334745777,
                   615693474, 1132436852, 2082876103};
    return arr[n];
  }
};

int main() {
  printf("%d\n", Solution::tribonacci(4));
  printf("%d\n", Solution::tribonacci(25));
  printf("%d\n", Solution::tribonacci(37));
}
