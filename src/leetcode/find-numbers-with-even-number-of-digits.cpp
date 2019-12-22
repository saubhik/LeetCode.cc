//
// Created by saubhik on 2019/12/22.
//
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
  // 4ms, 100% run-time; 9.2MB, 100% memory.
  // O(n) time, O(1) space.
  static int findNumbers(vector<int> &nums) {
    int count = 0;
    for (int num : nums)
      count += (int)((log(num) / log(10)) + 1) % 2 ? 0 : 1;
    return count;
  }
};

int main() {
  vector<int> nums = {12, 345, 2, 6, 7896};
  printf("%d\n", Solution::findNumbers(nums));

  nums = {555, 901, 482, 1771};
  printf("%d", Solution::findNumbers(nums));
}
