//
// Created by saubhik on 2019/11/04.
//
#include <iostream>
using namespace std;

class Solution {
public:
  // using memoization, O(N) space, O(N) time.
  static int fib(int N) {
    int dp[31] = {-1};
    return helper(N, dp);
  }
  static int helper(int N, int dp[]) {
    if (N == 0)
      return 0;
    if (N == 1)
      return 1;
    if (dp[N] != 0)
      return dp[N];
    return dp[N] = helper(N - 1, dp) + helper(N - 2, dp);
  }

  // without dp
  // 100% runtime, 100% memory usage
  static int fib2(int N) {
    int prePrev = 0, prev = 1, ans = 0;
    if (N == 0)
      return prePrev;
    if (N == 1)
      return prev;
    for (int i = 2; i < N; ++i) {
      int tmp = prev;
      prev = prev + prePrev;
      prePrev = tmp;
    }
    return prev + prePrev;
  }
};

int main() {
  printf("%d\n", Solution::fib(2));
  printf("%d\n", Solution::fib(3));
  printf("%d\n", Solution::fib(4));

  printf("%d\n", Solution::fib2(2));
  printf("%d\n", Solution::fib2(3));
  printf("%d\n", Solution::fib2(4));
}