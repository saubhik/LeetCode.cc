//
// Created by saubhik on 2019/11/06.
//
#include <vector>
using namespace std;

class Solution {
public:
  static int projectionArea(vector<vector<int>> &grid) {
    int maxi, maxj, xy = 0, yz = 0, zx = 0, n = grid.size();
    for (int i = 0; i < n; ++i) {
      maxi = 0, maxj = 0;
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != 0)
          ++xy;
        if (grid[i][j] > maxi)
          maxi = grid[i][j];
        if (grid[j][i] > maxj)
          maxj = grid[j][i];
      }
      zx += maxi;
      yz += maxj;
    }
    return xy + yz + zx;
  }
};

int main() {
  vector<vector<int>> grid = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
  printf("%d ", Solution::projectionArea(grid));
  grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  printf("%d ", Solution::projectionArea(grid));
  grid = {{1, 0}, {0, 2}};
  printf("%d ", Solution::projectionArea(grid));
}
