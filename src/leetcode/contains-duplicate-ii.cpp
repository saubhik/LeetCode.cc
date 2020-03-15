//
// Created by saubhik on 2020/03/15.
//
#include <unordered_map>
#include <vector>

class Solution {
public:
  // Runtime: 28 ms, faster than 88.09% of C++ online submissions for Contains
  // Duplicate II. Memory Usage: 14 MB, less than 100.00% of C++ online
  // submissions for Contains Duplicate II.
  //
  // O(n) time, O(n) space
  static bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> mp;
    const int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if ((mp.find(nums[i]) != mp.end()) && abs(mp[nums[i]] - i) <= k)
        return true;
      else
        mp[nums[i]] = i;
    }
    return false;
  }
};

int main() {
  std::vector<int> nums = {1, 2, 3, 1};
  printf("%d\n", Solution::containsNearbyDuplicate(nums, 3));

  nums = {1, 0, 1, 1};
  printf("%d\n", Solution::containsNearbyDuplicate(nums, 1));

  nums = {1, 2, 3, 1, 2, 3};
  printf("%d\n", Solution::containsNearbyDuplicate(nums, 2));
}
