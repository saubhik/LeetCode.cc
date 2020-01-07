//
// Created by saubhik on 2020/01/08.
//
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  // O(nlgn) time, O(n) space.
  static vector<string> findRelativeRanks(vector<int> &nums) {
    unordered_map<int, int> ump;
    vector<int> numscp = nums;
    sort(nums.begin(), nums.end(), [&](auto &l, auto &r) { return l > r; });
    for (int i = 0; i < numscp.size(); ++i)
      ump[numscp[i]] = i + 1;

    vector<string> ans(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      if (ump[nums[i]] == 1)
        ans[i] = "Gold Medal";
      else if (ump[nums[i]] == 2)
        ans[i] = "Silver Medal";
      else if (ump[nums[i]] == 3)
        ans[i] = "Bronze Medal";
      else
        ans[i] = to_string(ump[nums[i]]);
    }

    return ans;
  }
};

int main() {
  vector<int> nums = {5, 4, 3, 2, 1};
  vector<string> ans = Solution::findRelativeRanks(nums);
  for (string s : ans)
    printf("%s ", s.c_str());
}
