//
// Created by saubhik on 2019/12/08.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 90.42% run-time, 100% memory.
  // O(nlogn) time, O(1) space.
  static int twoCitySchedCost(vector<vector<int>> &costs) {
    int ans = 0, n = costs.size();
    sort(costs.begin(), costs.end(), [](const auto &a, const auto &b) {
      return (a[0] - a[1]) < (b[0] - b[1]);
    });
    for (int i = 0; i < n / 2; ++i)
      ans += costs[i][0] + costs[n - i - 1][1];
    return ans;
  }
};

class Solution2 {
public:
  // 90.42% run-time, 100% memory
  // courtesy: votrubac
  // we just need the biggest savings to be in the first half of the array.
  // So we use the quick select algorithm (`nth element`) and use the middle
  // of the array as the pivot.
  static int twoCitySchedCost(vector<vector<int>> &costs, int res = 0) {
    nth_element(begin(costs), begin(costs) + costs.size() / 2, end(costs),
                [](const auto &a, const auto &b) {
                  return (a[0] - a[1] < b[0] - b[1]);
                });
    for (auto i = 0; i < costs.size() / 2; ++i)
      res += costs[i][0] + costs[costs.size() - i - 1][1];
    return res;
  }
};

int main() {
  vector<vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
  printf("%d\n", Solution::twoCitySchedCost(costs));
  printf("%d", Solution2::twoCitySchedCost(costs));
}
