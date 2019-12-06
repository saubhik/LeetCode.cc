//
// Created by saubhik on 2019/12/05.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 96.96% run-time, 100% memory
  // O(n) time, O(1) additional space.
  static void moveZeroes(vector<int> &nums) {
    int n = nums.size(), z = 0, nz = 0;
    while (z < n && nums[z] != 0)
      ++z;
    nz = z + 1;
    for (;;) {
      while (nz < n && nums[nz] == 0)
        ++nz;
      if (nz >= n)
        break;
      swap(nums[z++], nums[nz]);
    }
  }
};

class Solution2 {
public:
  // 96.96% run-time, 88.89% memory
  // a bit cleaner
  static void moveZeroes(vector<int> &nums) {
    int n = nums.size(), j = 0;
    for (int i = 0; i < n; ++i)
      if (nums[i] != 0)
        swap(nums[i], nums[j++]);
  }
};

int main() {
  vector<int> nums = {0, 1, 0, 3, 12};
  Solution2::moveZeroes(nums);
  for (auto num : nums)
    printf("%d ", num);

  printf("\n");

  nums = {0};
  Solution2::moveZeroes(nums);
  for (auto num : nums)
    printf("%d ", num);

  printf("\n");

  nums = {1, 0, 1};
  Solution2::moveZeroes(nums);
  for (auto num : nums)
    printf("%d ", num);
}
