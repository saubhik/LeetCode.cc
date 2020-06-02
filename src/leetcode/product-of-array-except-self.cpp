//
// Created by saubhik on 2020/06/02.
//
#include <vector>

using namespace std;

class Solution {
public:
  // O(n) time, O(1) space.
  static vector<int> productExceptSelf(vector<int> &nums) {
    int prod = 1, zeroIndex = -1;
    vector<int> output(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        if (zeroIndex != -1) {
          return output;
        }
        zeroIndex = i;
        continue;
      }
      prod *= nums[i];
    }
    if (zeroIndex != -1) {
      output[zeroIndex] = prod;
      return output;
    }
    for (int i = 0; i < nums.size(); ++i) {
      output[i] = prod / nums[i];
    }
    return output;
  }
};

class Solution2 {
public:
  // Runtime: 12 ms, faster than 99.95% of C++ online submissions for Product of
  // Array Except Self. Memory Usage: 15.9 MB, less than 6.06% of C++ online
  // submissions for Product of Array Except Self.
  //
  // O(n) time, O(1) space without division.
  //     |*, 1, 2, 6| 24
  // 24, |24,  12, 4| *
  // Two pointer approach, one from left and another from right.
  static vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size(), i;
    vector<int> output(n, 1);
    for (i = 1; i < n; ++i) {
      output[i] = nums[i - 1] * output[i - 1];
    }
    int prod = 1;
    for (i = n - 2; i >= 0; --i) {
      prod *= nums[i + 1];
      output[i] *= prod;
    }
    return output;
  }
};

int main() {
  vector<int> nums, output;

  nums = {1, 2, 3, 4};
  output = {24, 12, 8, 6};
  assert(Solution::productExceptSelf(nums) == output);
  assert(Solution2::productExceptSelf(nums) == output);

  nums = {1, 0, 2};
  output = {0, 2, 0};
  assert(Solution::productExceptSelf(nums) == output);
  assert(Solution2::productExceptSelf(nums) == output);

  nums = {0, 1, 0};
  output = {0, 0, 0};
  assert(Solution::productExceptSelf(nums) == output);
  assert(Solution2::productExceptSelf(nums) == output);
}