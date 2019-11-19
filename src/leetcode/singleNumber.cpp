//
// Created by saubhik on 2019/11/19.
//
#include <vector>
using namespace std;
class Solution {
public:
  // 96.09% run-time, 98.77% memory
  static int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (int num : nums)
      ans ^= num;
    return ans;
  }
};

int main() {
  vector<int> nums = {4, 1, 2, 1, 2};
  printf("%d\n", Solution::singleNumber(nums));
  nums = {2, 2, 1};
  printf("%d", Solution::singleNumber(nums));
}
