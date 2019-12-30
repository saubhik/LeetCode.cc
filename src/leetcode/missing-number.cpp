//
// Created by saubhik on 2019/12/30.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 24ms, 82.45% run-time; 9.8MB, 90.20% memory.
  // O(n) time, O(1) space.
  // textbook xor trick
  // using associativity property.
  static int missingNumber(vector<int> &nums) {
    int n = nums.size(), ans = n;
    for (int i = 0; i < n; ++i)
      ans ^= nums[i], ans ^= i;
    return ans;
  }
};

int main() {
  vector<int> nums = {3, 0, 1};
  printf("%d\n", Solution::missingNumber(nums));

  nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  printf("%d", Solution::missingNumber(nums));
}
