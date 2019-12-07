//
// Created by saubhik on 2019/12/07.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 95.81% run-time, 66.67% memory
  // O(n) time, O(1) additional space.
  // mark the visited indices with -1.
  // use the fact that indices and numbers are 1..n.
  static vector<int> findDisappearedNumbers(vector<int> &nums) {
    int tmp, n = nums.size();
    for (int i = 0; i < n; ++i) {
      bool chain = false;
      int j = i;
      while (nums[j] != -1) {
        tmp = nums[j];
        if (chain)
          nums[j] = -1;
        j = tmp - 1;
        chain = true;
      }
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i)
      if (nums[i] != -1)
        ans.push_back(i + 1);

    return ans;
  }
};

class Solution2 {
public:
  // 90.08% run-time, 93.33% memory
  // O(n) run-time, O(1) space.
  // mark it negative, and so do not lose value. Use abs().
  static vector<int> findDisappearedNumbers(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i)
      if (nums[abs(nums[i]) - 1] > 0)
        nums[abs(nums[i]) - 1] *= -1;

    vector<int> ans;
    for (int i = 0; i < n; ++i)
      if (nums[i] > 0)
        ans.push_back(i + 1);

    return ans;
  }
};

int main() {
  vector<int> nums, ans;

  nums = {4, 3, 2, 7, 8, 2, 3, 1};
  ans = Solution::findDisappearedNumbers(nums);
  for (int n : ans)
    printf("%d ", n);

  printf("\n");

  ans = Solution2::findDisappearedNumbers(nums);
  for (int n : ans)
    printf("%d ", n);

  printf("\n");

  nums = {1, 1};
  ans = Solution::findDisappearedNumbers(nums);
  for (int n : ans)
    printf("%d ", n);

  printf("\n");

  ans = Solution2::findDisappearedNumbers(nums);
  for (int n : ans)
    printf("%d ", n);
}
