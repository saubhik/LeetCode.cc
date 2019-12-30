//
// Created by saubhik on 2019/12/30.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 52ms, 69.90% run-time; 11MB, 55.56% memory.
  // O(n) time, O(1) space.
  static int minMoves(vector<int> &nums) {
    long s = 0;
    int m = INT_MAX;
    for (int num : nums)
      s += num, m = min(m, num);
    return s - m * nums.size();
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  printf("%d", Solution::minMoves(nums));
}
