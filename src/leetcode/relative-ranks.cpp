//
// Created by saubhik on 2020/01/08.
//
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 16 ms, faster than 85.38% of C++ online submissions for Relative
  // Ranks. Memory Usage: 12.1 MB, less than 33.33% of C++ online submissions
  // for Relative Ranks.
  //
  // O(nlgn) time, O(n) space.
  static vector<string> findRelativeRanks(vector<int> &nums) {
    unordered_map<int, int> ump;
    vector<int> numscp(nums);

    sort(numscp.begin(), numscp.end(), greater<int>());
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

class Solution2 {
public:
  // Runtime: 16 ms, faster than 85.38% of C++ online submissions for Relative
  // Ranks. Memory Usage: 11.1 MB, less than 33.33% of C++ online submissions
  // for Relative Ranks.
  //
  // O(nlgn) time, O(n) space.
  // using priority queue
  static vector<string> findRelativeRanks(vector<int> &nums) {
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < nums.size(); ++i)
      pq.emplace(nums[i], i);

    vector<string> ans(nums.size(), "");

    for (int i = 0; i < nums.size(); ++i) {
      auto pr = pq.top();
      pq.pop();
      if (i == 0)
        ans[pr.second] = "Gold Medal";
      else if (i == 1)
        ans[pr.second] = "Silver Medal";
      else if (i == 2)
        ans[pr.second] = "Bronze Medal";
      else
        ans[pr.second] = to_string(i + 1);
    }

    return ans;
  }
};

class Solution3 {
public:
  // Runtime: 12 ms, faster than 98.34% of C++ online submissions for Relative
  // Ranks. Memory Usage: 11.1 MB, less than 33.33% of C++ online submissions
  // for Relative Ranks.
  static vector<string> findRelativeRanks(vector<int> &nums,
                                          vector<pair<int, int>> v = {}) {
    for (int i = 0; i < nums.size(); ++i)
      v.push_back({nums[i], i});
    sort(begin(v), end(v), greater<pair<int, int>>());
    vector<string> res(v.size());
    for (int i = 0; i < v.size(); ++i)
      res[v[i].second] =
          i == 0 ? "Gold Medal"
                 : i == 1 ? "Silver Medal"
                          : i == 2 ? "Bronze Medal" : to_string(i + 1);
    return res;
  }
};

int main() {
  vector<int> nums;
  vector<string> ans1, ans2;

  nums = {5, 4, 3, 2, 1};
  ans1 = Solution::findRelativeRanks(nums);
  ans2 = Solution2::findRelativeRanks(nums);
  for (string s : ans1)
    printf("%s ", s.c_str());

  printf("\n");

  for (string s : ans2)
    printf("%s ", s.c_str());

  printf("\n");

  nums = {10, 3, 8, 9, 4};
  ans1 = Solution::findRelativeRanks(nums);
  ans2 = Solution2::findRelativeRanks(nums);
  for (string s : ans1)
    printf("%s ", s.c_str());

  printf("\n");

  for (string s : ans2)
    printf("%s ", s.c_str());
}
