//
// Created by saubhik on 2019/11/17.
//
#include <vector>
using namespace std;

class Solution {
public:
  static vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        ans[(i + (j + k) / m) % n][(j + k) % m] = grid[i][j];
    return ans;
  }
};

int main() {
  vector<vector<int>> grid = {{3, 8, 1, 9},
                              {19, 7, 2, 5},
                              {4, 6, 11, 10},
                              {12, 0, 21, 13}},
                      ans;
  ans = Solution::shiftGrid(grid, 4);
  for (const auto &row : ans) {
    for (const auto &elem : row)
      printf("%d ", elem);
    printf("\n");
  }

  printf("\n");

  grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  ans = Solution::shiftGrid(grid, 1);
  for (const auto &row : ans) {
    for (const auto &elem : row)
      printf("%d ", elem);
    printf("\n");
  }
}