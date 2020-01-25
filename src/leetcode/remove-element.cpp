//
// Created by saubhik on 2020/01/24.
//
#include <vector>

using namespace std;

class Solution {
public:
  // in-place erase:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove
  // Element. Memory Usage: 8.5 MB, less than 95.59% of C++ online submissions
  // for Remove Element.
  static int removeElement(vector<int> &nums, int val) {
    int len = 0;
    for (auto it = nums.begin(); it != nums.end();)
      if (*it == val)
        it = nums.erase(it);
      else
        ++len, ++it;
    return len;
  }
};

class Solution2 {
public:
  // Two pointer technique.
  // O(n) time, O(1) space.
  // Runtime: 4 ms, faster than 72.42% of C++ online submissions for Remove Element.
  // Memory Usage: 8.6 MB, less than 73.53% of C++ online submissions for Remove Element.
  static int removeElement(vector<int> &nums, int val) {
    int k = 0, n = nums.size();
    for (int i = 0; i < n; ++i)
      if (nums[i] != val)
        nums[k++] = nums[i];
    nums.resize(k);
    return k;
  }
};

int main() {
  vector<int> nums = {3, 2, 2, 3};
  printf("%d\n", Solution::removeElement(nums, 3));
  // check if nums has changed
  for (int num : nums)
    printf("%d ", num);
  printf("\n");

  nums = {0, 1, 2, 2, 3, 0, 4, 2};
  printf("%d\n", Solution::removeElement(nums, 2));
  // check if nums has changed
  for (int num : nums)
    printf("%d ", num);
  printf("\n");

  nums = {0, 1, 2, 2, 3, 0, 4, 2};
  printf("%d\n", Solution2::removeElement(nums, 2));
  // check if nums has changed
  for (int num : nums)
    printf("%d ", num);
}
