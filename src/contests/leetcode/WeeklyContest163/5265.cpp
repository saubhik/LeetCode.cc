//
// Created by saubhik on 2019/11/17.
//
#include <vector>
using namespace std;

class Solution {
public:
  static int maxSumDivThree(vector<int> &nums) {
    int n = nums.size();
    int dp[n];
    memset(dp, -1, sizeof(dp));
    return go(dp, nums, n - 1);
  }
  static int go(int dp[], vector<int> &nums, int i) {
    if (dp[i] != -1)
      return dp[i];

    if (i < 0)
      return 0;

    int ans = 0, cand[2];
    cand[0] = go(dp, nums, i - 1);
    cand[1] = cand[0] + nums[i];

    for (auto c : cand)
      if (c % 3 == 0)
        ans = max(ans, c);

    dp[i] = ans;
    return dp[i];
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 4};
  printf("%d\n", Solution::maxSumDivThree(nums));
}
