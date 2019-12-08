//
// Created by saubhik on 2019/12/08.
//
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  // 77.92% run-time, 36.36% memory.
  // O(n) time, O(n) space.
  static int majorityElement(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> ump;
    for (int num : nums) {
      ++ump[num];
      if (ump[num] > n / 2)
        return num;
    }
    return -1;
  }
};

class Solution2 {
public:
  // 24.84% run-time, 98.48% memory
  // sorting
  // O(nlogn) time, O(1) space.
  static int majorityElement(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};

class Solution3 {
public:
  // 8.73% run-time, 96.97% memory.
  // Divide and conquer.
  // O(nlogn) time, O(logn) space.
  static int majorityElement(vector<int> &nums) {
    return majorityElementRec(nums, 0, nums.size() - 1);
  }

private:
  static int majorityElementRec(vector<int> &nums, int lo, int hi) {
    if (lo == hi)
      return nums[lo];

    int mid = lo + (hi - lo) / 2;
    int leftME = majorityElementRec(nums, lo, mid);
    int rightME = majorityElementRec(nums, mid + 1, hi);

    if (leftME == rightME)
      return leftME;

    int leftCount = count(nums.begin() + lo, nums.begin() + hi + 1, leftME);
    int rightCount = count(nums.begin() + lo, nums.begin() + hi + 1, rightME);
    return leftCount > rightCount ? leftME : rightME;
  }
};

class Solution4 {
public:
  // 77.92% run-time, 71.21% memory.
  // no need to do full sort, only partial sort required.
  // O(nlogn) time, O(1) space.
  static int majorityElement(vector<int> &nums) {
    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return nums[nums.size() / 2];
  }
};

int main() {
  vector<int> nums;

  nums = {3, 2, 3};
  printf("%d %d %d %d\n", Solution::majorityElement(nums),
         Solution2::majorityElement(nums), Solution3::majorityElement(nums),
         Solution4::majorityElement(nums));

  nums = {2, 2, 1, 1, 1, 2, 2};
  printf("%d %d %d %d", Solution::majorityElement(nums),
         Solution2::majorityElement(nums), Solution3::majorityElement(nums),
         Solution4::majorityElement(nums));
};
