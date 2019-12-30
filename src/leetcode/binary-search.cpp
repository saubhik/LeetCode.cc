//
// Created by saubhik on 2019/12/27.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 48ms, 93.98% run-time; 10.9MB, 88.89% memory.
  static int search(vector<int> &nums, int target) {
    int lo = 0, hi = nums.size() - 1, mid;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target)
        hi = mid - 1;
      else
        lo = mid + 1;
    }
    return -1;
  }
};

int main() {
  vector<int> nums;

  nums = {-1, 0, 3, 5, 9, 12};
  printf("%d\n", Solution::search(nums, 9));

  nums = {-1, 0, 3, 5, 9, 12};
  printf("%d\n", Solution::search(nums, 2));

  nums = {5};
  printf("%d", Solution::search(nums, 5));
}
