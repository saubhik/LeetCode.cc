//
// Created by saubhik on 2019/11/10.
//
#include <vector>
using namespace std;
class Solution {
public:
  static int oddCells(int n, int m, vector<vector<int>> &indices) {
    int grid[n][m];
    memset(grid, 0, sizeof(grid));
    for (auto elem : indices) {
      for (int j = 0; j < m; ++j)
        grid[elem[0]][j] = ((grid[elem[0]][j] + 1) % 2);
      for (int i = 0; i < n; ++i)
        grid[i][elem[1]] = ((grid[i][elem[1]] + 1) % 2);
    }

    int count = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (grid[i][j])
          count++;

    return count;
  }
};

int main() {
  vector<vector<int>> indices = {{0, 1}, {1, 1}};
  printf("%d\n", Solution::oddCells(2, 3, indices));
  indices = {{1, 1}, {0, 0}};
  printf("%d", Solution::oddCells(2, 2, indices));
}