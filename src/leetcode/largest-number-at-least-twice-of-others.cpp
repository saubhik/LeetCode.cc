//
// Created by saubhik on 2020/04/04.
//
#include <vector>

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Largest
  // Number At Least Twice of Others. Memory Usage: 6.2 MB, less than 100.00% of
  // C++ online submissions for Largest Number At Least Twice of Others.
  //
  // O(n) time, O(1) space
  static int dominantIndex(std::vector<int> &nums) {
    int indMax1 = -1, indMax2 = -1, n = nums.size();
    for (int ind = 0; ind < n; ++ind) {
      if (indMax1 == -1 || nums[ind] > nums[indMax1]) {
        indMax2 = indMax1;
        indMax1 = ind;
      } else if (indMax2 == -1 || nums[ind] > nums[indMax2]) {
        indMax2 = ind;
      }
    }
    return indMax2 == -1 || nums[indMax1] >= 2 * nums[indMax2] ? indMax1 : -1;
  }
};

int main() {
  std::vector<int> nums = {3, 6, 1, 0};
  printf("%d\n", Solution::dominantIndex(nums));

  nums = {1, 2, 3, 4};
  printf("%d\n", Solution::dominantIndex(nums));

  nums = {1};
  printf("%d", Solution::dominantIndex(nums));
}
