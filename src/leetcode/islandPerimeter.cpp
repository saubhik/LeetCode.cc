//
// Created by saubhik on 2019/11/19.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 94.96% run-time, 100% memory
  // time: O(mn), space: O(1) additional.
  static int islandPerimeter(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) {
          // up is 0 or none
          if (i == 0 || grid[i - 1][j] == 0)
            ++ans;
          // left is 0 or none
          if (j == 0 || grid[i][j - 1] == 0)
            ++ans;
          // right is 0 or none
          if (j == (n - 1) || grid[i][j + 1] == 0)
            ++ans;
          // down is 0 or none
          if (i == (m - 1) || grid[i + 1][j] == 0)
            ++ans;
        }
    return ans;
  }
};

int main() {
  vector<vector<int>> grid = {
      {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
  printf("%d", Solution::islandPerimeter(grid));
}
