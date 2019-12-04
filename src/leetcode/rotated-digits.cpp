//
// Created by saubhik on 2019/12/04.
//
#include <cstdio>

class Solution {
public:
  // 100% run-time, 100% memory
  // O(NlogN) time. O(1) space.
  static int rotatedDigits(int N) {
    int ans = 0;
    bool good;
    for (int i = 1; i <= N; ++i) {
      int tmp = i;
      good = false;
      while (tmp) {
        if (tmp % 10 == 3 || tmp % 10 == 4 || tmp % 10 == 7) {
          good = false;
          break;
        }
        if (tmp % 10 == 2 || tmp % 10 == 5 || tmp % 10 == 6 || tmp % 10 == 9)
          good = true;
        tmp /= 10;
      }
      if (good)
        ++ans;
    }
    return ans;
  }
};

int main() {
  printf("%d\n", Solution::rotatedDigits(10));
  printf("%d\n", Solution::rotatedDigits(23));
  printf("%d\n", Solution::rotatedDigits(857));
}
