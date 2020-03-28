//
// Created by saubhik on 2020/03/28.
//
#include <vector>

class Solution {
public:
  // This got TLEd.
  // O(nk) time, O(1) space (in-place)
  static void rotate(std::vector<int> &nums, int k) {
    int n = nums.size(), tmp;
    while (k--) {
      tmp = nums[0];
      nums[0] = nums[n - 1];
      for (int i = 1; i < n; ++i)
        std::swap(nums[i], tmp);
    }
  }
};

class Solution2 {
public:
  // Runtime: 12 ms, faster than 99.38% of C++ online submissions for Rotate
  // Array. Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions
  // for Rotate Array.
  //
  // Cyclic Replacements.
  // O(n) time, O(1) space (in-place)
  static void rotate(std::vector<int> &nums, int k) {
    int n = nums.size(), currPos = 0, startPos, cnt = 0, tmp;
    while (cnt < n) {
      startPos = currPos;
      tmp = nums[(n + (currPos - k) % n) % n];
      do {
        std::swap(nums[currPos], tmp);
        currPos = (currPos + k) % n;
        ++cnt;
      } while (currPos != startPos);
      ++currPos;
    }
  }
};

int main() {
  std::vector<int> nums, ans;

  nums = {1, 2, 3, 4, 5, 6, 7};
  ans = {5, 6, 7, 1, 2, 3, 4};
  Solution::rotate(nums, 3);
  assert(nums == ans);

  nums = {1, 2, 3, 4, 5, 6, 7};
  ans = {5, 6, 7, 1, 2, 3, 4};
  Solution2::rotate(nums, 3);
  assert(nums == ans);

  nums = {-1, -100, 3, 99};
  ans = {3, 99, -1, -100};
  Solution::rotate(nums, 2);
  assert(nums == ans);

  nums = {-1, -100, 3, 99};
  ans = {3, 99, -1, -100};
  Solution2::rotate(nums, 2);
  assert(nums == ans);

  nums = {1};
  ans = {1};
  Solution2::rotate(nums, 1);
  assert(nums == ans);
}
