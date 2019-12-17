//
// Created by saubhik on 2019/12/17.
//
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  // 81.46%. 40ms run-time; 45.45%, 14.3MB memory.
  // O(n) time, O(n) space.
  static int findShortestSubArray(vector<int> &nums) {
    int maxCount = 0;
    map<int, int> count, start, end;
    for (int i = 0; i < nums.size(); ++i) {
      maxCount = max(maxCount, ++count[nums[i]]);
      if (start.find(nums[i]) == start.end())
        start[nums[i]] = i;
      end[nums[i]] = i;
    }

    int ans = INT_MAX;
    for (auto it = count.begin(); it != count.end(); ++it)
      if (it->second == maxCount)
        ans = min(ans, end[it->first] - start[it->first] + 1);

    return ans;
  }
};

class Solution2 {
public:
  // 81.46%, 40ms run-time; 100%, 13MB memory.
  // courtesy: Lee
  // One pass.
  static int findShortestSubArray(vector<int> &nums) {
    int degree = 0, res = INT_MAX;
    unordered_map<int, int> count, first;
    for (int i = 0; i < nums.size(); ++i) {
      if (first.find(nums[i]) == first.end())
        first[nums[i]] = i;
      if (degree < ++count[nums[i]]) {
        degree = count[nums[i]];
        res = i - first[nums[i]] + 1;
      } else if (degree == count[nums[i]]) {
        res = min(res, i - first[nums[i]] + 1);
      }
    }
    return res;
  }
};

int main() {
  vector<int> nums;

  nums = {1, 2, 2, 3, 1};
  printf("%d %d\n", Solution::findShortestSubArray(nums),
         Solution2::findShortestSubArray(nums));

  nums = {1, 2, 2, 3, 1, 4, 2};
  printf("%d %d", Solution::findShortestSubArray(nums),
         Solution2::findShortestSubArray(nums));
}
