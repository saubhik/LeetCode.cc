//
// Created by saubhik on 2019/11/16.
//
#include <iostream>
using namespace std;

class Solution {
public:
  // 61.30% run-time, 100% memory
  static bool divisorGame(int N) {
    int win[N + 1];
    memset(win, -1, sizeof(win));
    return helper(win, N);
  }
  static bool helper(int win[], int n) {
    if (n == 1)
      return false;
    if (win[n] != -1)
      return win[n];
    bool ans = false;
    for (int i = 1; i < n; ++i)
      if (n % i == 0) {
        ans |= !helper(win, n - i);
      }
    return win[n] = ans;
  }
};

class Solution2 {
public:
  static bool divisorGame(int N) { return N % 2 == 0; }
};

int main() {
  printf("%d\n", Solution::divisorGame(2));
  printf("%d\n", Solution2::divisorGame(2));
  printf("%d\n", Solution::divisorGame(3));
  printf("%d\n", Solution2::divisorGame(3));
  printf("%d\n", Solution::divisorGame(6));
  printf("%d\n", Solution2::divisorGame(6));
}
