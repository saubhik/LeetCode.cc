//
// Created by saubhik on 2020/05/15.
//
#include <vector>

using namespace std;

class Solution {
public:
  // Runtime: 16 ms, faster than 50.96% of C++ online submissions for Single
  // Number III. Memory Usage: 10.1 MB, less than 25.00% of C++ online
  // submissions for Single Number III.
  //
  // O(n) time, O(1) space.
  // n & (-n) gives the least significant bit of n.
  // n & (n-1) removes the least significant bit of n.
  static vector<int> singleNumber(vector<int> &nums) {
    int mask = 0;
    for (int num : nums) {
      mask ^= num;
    }
    int filter = mask & (-mask);
    vector<int> ans(2, 0);
    for (int num : nums) {
      if (num & filter) {
        ans[0] ^= num;
      } else {
        ans[1] ^= num;
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums, expected;

  nums = {1, 2, 1, 3, 2, 5};
  expected = {3, 5};
  assert(Solution::singleNumber(nums) == expected);
}
