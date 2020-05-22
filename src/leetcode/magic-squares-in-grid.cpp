//
// Created by saubhik on 2020/05/19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // Runtime: 4 ms, faster than 71.30% of C++ online submissions for Magic
  // Squares In Grid. Memory Usage: 8.3 MB, less than 100.00% of C++ online
  // submissions for Magic Squares In Grid.
  //
  // O(mn) time, O(1) space.
  static int numMagicSquaresInside(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int rowSum1, rowSum2, rowSum3;
    int colSum1, colSum2, colSum3;
    int diaSum1, diaSum2;
    int count = 0;
    bool a[16] = {false}, flag;
    for (int i = 0; i < m - 2; ++i) {
      for (int j = 0; j < n - 2; ++j) {
        memset(a, false, 16);
        rowSum1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        rowSum2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
        rowSum3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
        if (rowSum1 == rowSum2 && rowSum2 == rowSum3) {
          colSum1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
          colSum2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
          colSum3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];
          if (colSum1 == colSum2 && colSum2 == colSum3) {
            diaSum1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
            diaSum2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
            if (diaSum1 == diaSum2) {
              for (int row = i; row < i + 3; ++row) {
                for (int col = j; col < j + 3; ++col) {
                  a[grid[row][col]] = true;
                }
              }
              flag = false;
              for (int k = 1; k < 10; ++k) {
                if (!a[k]) {
                  flag = true;
                  break;
                }
              }
              if (!flag) {
                ++count;
              }
            }
          }
        }
      }
    }
    return count;
  }
};

int main() {
  vector<vector<int>> grid = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
  assert(Solution::numMagicSquaresInside(grid) == 1);
}