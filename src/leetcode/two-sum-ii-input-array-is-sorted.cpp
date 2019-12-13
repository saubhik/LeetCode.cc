//
// Created by saubhik on 2019/12/13.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 96.77% (4ms) run-time, 84.31% (9.4MB) memory.
  // traditional two pointer technique
  // O(n) time, O(1) space
  static vector<int> twoSum(vector<int> &numbers, int target) {
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
      if (numbers[l] + numbers[r] == target)
        return {l + 1, r + 1};
      else if (numbers[l] + numbers[r] < target)
        ++l;
      else
        --r;
    }
    return {};
  }
};

int main() {
  vector<int> numbers = {2, 7, 11, 15}, ans;
  ans = Solution::twoSum(numbers, 9);
  printf("%d %d", ans[0], ans[1]);
}
