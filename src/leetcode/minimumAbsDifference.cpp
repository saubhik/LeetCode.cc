//
// Created by saubhik on 2019/11/10.
//
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  // 83.33% run-time, 100% memory
  static vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int minAbsDiff = INT_MAX;

    for (size_t i = 1; i < arr.size(); ++i)
      minAbsDiff = min(minAbsDiff, arr[i] - arr[i - 1]);

    for (size_t i = 1; i < arr.size(); ++i)
      if (abs(arr[i] - arr[i - 1]) == minAbsDiff)
        ans.push_back({arr[i - 1], arr[i]});

    return ans;
  }
};

int main() {
  vector<vector<int>> ans;
  vector<int> arr = {3, 8, -10, 23, 19, -4, -14, 27};
  ans = Solution::minimumAbsDifference(arr);
  for (auto pr : ans)
    printf("[%d, %d] ", pr[0], pr[1]);

  printf("\n");

  arr = {1, 3, 6, 10, 15};
  ans = Solution::minimumAbsDifference(arr);
  for (auto pr : ans)
    printf("[%d, %d] ", pr[0], pr[1]);

  printf("\n");

  arr = {4, 2, 1, 3};
  ans = Solution::minimumAbsDifference(arr);
  for (auto pr : ans)
    printf("[%d, %d] ", pr[0], pr[1]);
}
