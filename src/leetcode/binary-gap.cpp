//
// Created by saubhik on 2019/11/21.
//
#include <algorithm>
#include <cstdio>
using namespace std;

class Solution {
public:
  // 100% run-time, 100% memory
  // O(logN) time, O(1) additional space.
  static int binaryGap(int N) {
    int first = 0, ans = 0;
    for (int i = 1; N > 0; ++i, N >>= 1) {
      if (N & 1) {
        if (!first)
          first = i;
        else {
          ans = max(ans, i - first);
          // consider the next consecutive pair
          first = i;
        }
      }
    }
    return ans;
  }
};

int main() {
  printf("%d\n", Solution::binaryGap(22));
  printf("%d\n", Solution::binaryGap(5));
  printf("%d\n", Solution::binaryGap(6));
  printf("%d", Solution::binaryGap(8));
}
