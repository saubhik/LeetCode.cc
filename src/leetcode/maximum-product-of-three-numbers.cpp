//
// Created by saubhik on 2020/01/29.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 44 ms, faster than 95.28% of C++ online submissions for Maximum
  // Product of Three Numbers. Memory Usage: 10.9 MB, less than 100.00% of C++
  // online submissions for Maximum Product of Three Numbers.
  //
  // O(n) time, O(1) space.
  static int maximumProduct(vector<int> &nums, int max1 = -1000,
                            int max2 = -1000, int max3 = -1000, int min1 = 1000,
                            int min2 = 1000) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] > max1) {
        max3 = max2;
        max2 = max1;
        max1 = nums[i];
      } else if (nums[i] > max2) {
        max3 = max2;
        max2 = nums[i];
      } else if (nums[i] > max3)
        max3 = nums[i];

      if (nums[i] < min1) {
        min2 = min1;
        min1 = nums[i];
      } else if (nums[i] < min2)
        min2 = nums[i];
    }
    return max1 * max(max2 * max3, min1 * min2);
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  printf("%d\n", Solution::maximumProduct(nums));
  nums = {-4, 1, 2, 3, 4};
  printf("%d\n", Solution::maximumProduct(nums));
  nums = {-5, -4, 1, 2, 3, 4};
  printf("%d", Solution::maximumProduct(nums));
}
