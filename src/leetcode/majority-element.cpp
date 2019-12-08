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

class Solution5 {
public:
  // Moore Voting Algorithm
  // O(n) time, O(1) space.
  // add +1 whenever we find candidate, and -1 whenever we find something else.
  // set element as candidate, whenever our count becomes 0.
  // it is as if we are starting afresh, forgetting our previous experience.
  // in our previous experience (the prefix that we throw away), we ensure that
  // there is no majority element.
  // this is like recursively solving a problem.
  // finally we will have a situation where we are running with a candidate
  // and our count does not end up with 0. that is our solution.
  // this is pure madness.
  static int majorityElement(vector<int> &nums) {
    int count = 0, candidate = 0;
    for (int num : nums) {
      if (!count)
        candidate = num;
      count += num == candidate ? 1 : -1;
    }
    return candidate;
  }
};

class Solution6 {
public:
  // 46.22% run-time, 96.97% memory.
  // Courtesy: jianchao-li
  // Bit Manipulation
  // the bits in the majority are just the majority bits of all the numbers.
  // we traverse all the numbers 32 times, and check which bits are set, by
  // checking if a bit is set for more than half of the numbers. If a bit is set
  // for more than half the size of the array, that bit must belong to the
  // majority.
  // O(n) time, O(1) space.
  static int majorityElement(vector<int> &nums) {
    int bitCount, ans = 0;
    for (unsigned int i = 0, mask = 1; i < 32; ++i, mask <<= 1) {
      bitCount = 0;
      for (int num : nums)
        if (num & mask)
          ++bitCount;
      if (bitCount > nums.size() / 2)
        ans |= mask;
    }
    return ans;
  }
};

int main() {
  vector<int> nums;

  nums = {3, 2, 3};
  printf("%d %d %d %d %d %d\n", Solution::majorityElement(nums),
         Solution2::majorityElement(nums), Solution3::majorityElement(nums),
         Solution4::majorityElement(nums), Solution5::majorityElement(nums),
         Solution6::majorityElement(nums));

  nums = {2, 2, 1, 1, 1, 2, 2};
  printf("%d %d %d %d %d %d", Solution::majorityElement(nums),
         Solution2::majorityElement(nums), Solution3::majorityElement(nums),
         Solution4::majorityElement(nums), Solution5::majorityElement(nums),
         Solution6::majorityElement(nums));
};
