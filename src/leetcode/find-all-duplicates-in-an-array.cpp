//
// Created by saubhik on 2020/05/04.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
  // Runtime: 112 ms, faster than 89.57% of C++ online submissions for Find All
  // Duplicates in an Array. Memory Usage: 33.6 MB, less than 5.00% of C++
  // online submissions for Find All Duplicates in an Array.
  //
  // O(n) time, O(1) space.
  //
  // In-place flipping to negative.
  static vector<int> findDuplicates(vector<int> &nums) {
    vector<int> ans;
    for (int num : nums) {
      if (nums[abs(num) - 1] > 0) {
        nums[abs(num) - 1] *= -1;
      } else {
        ans.push_back(abs(num));
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums, expected;

  nums = {4, 3, 2, 7, 8, 2, 3, 1};
  expected = {2, 3};
  assert(Solution::findDuplicates(nums) == expected);
}
