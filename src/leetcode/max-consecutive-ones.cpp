//
// Created by saubhik on 2019/12/04.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 94.23% run-time, 100% memory
  // O(n) time, O(1) space
  static int findMaxConsecutiveOnes(vector<int> &nums) {
    int count = 0, ans = 0;
    for (int num : nums) {
      if (num == 1)
        ans = max(++count, ans);
      else
        count = 0;
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 1, 0, 1, 1, 1};
  printf("%d", Solution::findMaxConsecutiveOnes(nums));
}
