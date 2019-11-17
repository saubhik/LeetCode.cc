//
// Created by saubhik on 2019/11/17.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 85.71% run-time, 100% memory
  static int maxSumDivThree(vector<int> &nums) {
    vector<int> dp(3, 0), tmp(3);
    for (auto num : nums) {
      tmp = dp;
      for (auto i : tmp)
        dp[(num + i) % 3] = max(num + i, dp[(num + i) % 3]);
    }
    return dp[0];
  }
};

int main() {
  vector<int> nums = {3, 6, 5, 1, 8};
  printf("%d\n", Solution::maxSumDivThree(nums));

  nums = {4};
  printf("%d\n", Solution::maxSumDivThree(nums));

  nums = {1, 2, 3, 4, 4};
  printf("%d", Solution::maxSumDivThree(nums));
}
