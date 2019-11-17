//
// Created by saubhik on 2019/11/16.
//
#include <cmath>
#include <iostream>
using namespace std;
class Solution {
public:
  // 51.22% run-time, 100% memory
  static int climbStairs(int n, int tmp = 0) {
    int prev2 = 1, prev1 = 2;
    if (n == 1)
      return prev2;
    if (n == 2)
      return prev1;
    for (int i = 2; i < n; ++i, prev2 = prev1, prev1 = tmp)
      tmp = prev1 + prev2;
    return tmp;
  }
};

class Solution2 {
public:
  // O(logn) time due to pow method.
  static int climbStairs(int n) {
    double sqrt5 = sqrt(5);
    double ans = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
    return (int)(ans / sqrt5);
  }
};

int main() {
  printf("%d\n", Solution::climbStairs(2));
  printf("%d\n", Solution2::climbStairs(2));
  printf("%d\n", Solution::climbStairs(8));
  printf("%d\n", Solution2::climbStairs(8));
}
