//
// Created by saubhik on 2020/01/08.
//
#include <vector>
using namespace std;

class Solution {
public:
  // O(|ops|) time, O(1) space
  static int maxCount(int m, int n, vector<vector<int>> &ops) {
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
