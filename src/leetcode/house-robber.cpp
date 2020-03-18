//
// Created by saubhik on 2020/03/18.
//
#include <vector>

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for House
  // Robber. Memory Usage: 7.7 MB, less than 100.00% of C++ online submissions
  // for House Robber.
  //
  // O(n) time, O(1) space.
  // Dynamic Programming approach.
  // 1. We need solution to sub-problems ending at last, second last, and third
  // last index. From solutions to these sub-problems, we can construct the
  // solution to current sub-problem. This is optimal substructure.
  // 2. To solve the sub-problems, we need the solution to yet other
  // sub-problems. This is overlapping sub-problems.
  // We use 5 variables through out the entire iteration, so this is O(1) space.
  static int rob(std::vector<int> &nums) {
    int n = nums.size(), max1 = 0, max2 = 0, max3 = 0;
    int tmp1, tmp2;
    for (int i = 0; i < n; ++i) {
      if (i == 0)
        max1 = nums[i];
      else if (i == 1) {
        max2 = max1;
        max1 = nums[i];
      } else {
        tmp1 = max1;
        max1 = std::max(max2, max3) + nums[i];
        tmp2 = max2;
        max2 = tmp1;
        max3 = tmp2;
      }
    }
    return std::max(max1, max2);
  }
};

int main() {
  std::vector<int> nums = {1, 2, 3, 1};
  printf("%d\n", Solution::rob(nums));

  nums = {2, 7, 9, 3, 1};
  printf("%d\n", Solution::rob(nums));

  nums = {1, 3, 1, 1, 3};
  printf("%d\n", Solution::rob(nums));

  nums = {};
  printf("%d", Solution::rob(nums));
}
