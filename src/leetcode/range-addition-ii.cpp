//
// Created by saubhik on 2020/01/08.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 4 ms, faster than 99.65% of C++ online submissions for Range
  // Addition II. Memory Usage: 11.4 MB, less than 100.00% of C++ online
  // submissions for Range Addition II.
  //
  // O(|ops|) time, O(1) space
  static int maxCount(int m, int n, vector<vector<int>> &ops) {
    if (ops.empty())
      return m * n;
    int minA = 40000, minB = 40000;
    for (auto &op : ops)
      minA = min(minA, op[0]), minB = min(minB, op[1]);
    return minA * minB;
  }
};

int main() {
  vector<vector<int>> ops = {{2, 2}, {3, 3}};
  printf("%d", Solution::maxCount(3, 3, ops));
}
