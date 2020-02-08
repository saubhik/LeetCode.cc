//
// Created by saubhik on 2020/02/07.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 32 ms, faster than 94.39% of C++ online submissions for Shortest
  // Unsorted Continuous Subarray. Memory Usage: 10.6 MB, less than 71.43% of
  // C++ online submissions for Shortest Unsorted Continuous Subarray.
  //
  // Two Pass, O(n) time, O(1) space.
  static int findUnsortedSubarray(vector<int> &nums) {
    int n = nums.size(), maxSoFar = INT_MIN, minSoFar = INT_MAX, left = -1,
        right = -1;
    for (int i = 0, j = n - 1; i < n && j >= 0; ++i, --j) {
      if (maxSoFar > nums[i])
        right = i;
      else
        maxSoFar = nums[i];
      if (minSoFar < nums[j])
        left = j;
      else
        minSoFar = nums[j];
    }
    return left == -1 ? 0 : right - left + 1;
  }
};

int main() {
  vector<int> nums = {2, 6, 4, 8, 17, 9, 15};
  printf("%d\n", Solution::findUnsortedSubarray(nums));

  nums = {1, 2, 3, 4};
  printf("%d\n", Solution::findUnsortedSubarray(nums));

  nums = {2, 3, 3, 2, 4};
  printf("%d", Solution::findUnsortedSubarray(nums));
}
