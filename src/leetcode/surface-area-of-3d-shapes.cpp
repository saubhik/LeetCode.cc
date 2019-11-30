//
// Created by saubhik on 2019/11/30.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 99.31% run-time, 100% memory
  // O(mn) time, O(1) additional space
  static int surfaceArea(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0)
          continue;
        ans += 4 * grid[i][j] + 2;
        if (j > 0)
          ans -= min(grid[i][j], grid[i][j - 1]);
        if (j < n - 1)
          ans -= min(grid[i][j], grid[i][j + 1]);
        if (i > 0)
          ans -= min(grid[i][j], grid[i - 1][j]);
        if (i < m - 1)
          ans -= min(grid[i][j], grid[i + 1][j]);
      }
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> grid;

  grid = {{2}};
  printf("%d\n", Solution::surfaceArea(grid));

  grid = {{1, 2}, {3, 4}};
  printf("%d\n", Solution::surfaceArea(grid));

  grid = {{1, 0}, {0, 2}};
  printf("%d\n", Solution::surfaceArea(grid));

  grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  printf("%d\n", Solution::surfaceArea(grid));

  grid = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
  printf("%d", Solution::surfaceArea(grid));
}