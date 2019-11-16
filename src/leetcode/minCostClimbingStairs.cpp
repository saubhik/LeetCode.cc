//
// Created by saubhik on 2019/11/16.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 98.23% run-time, 88.37% memory
  static int minCostClimbingStairs(vector<int> &cost, int tmp = 0) {
    int prev1 = cost[1], prev2 = cost[0];
    for (short i = 2; i < (short)cost.size(); ++i, prev2 = prev1, prev1 = tmp)
      tmp = cost[i] + min(prev1, prev2);
    return min(prev1, prev2);
  }
};

int main() {
  vector<int> cost = {10, 15, 20};
  printf("%d\n", Solution::minCostClimbingStairs(cost));
}
