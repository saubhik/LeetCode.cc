//
// Created by saubhik on 2019/11/10.
//
#include <vector>
using namespace std;
class Solution {
public:
  static vector<vector<int>> reconstructMatrix(int upper, int lower,
                                               vector<int> &colsum) {
    int n = colsum.size();
    vector<vector<int>> grid(2, vector<int>(n));
    vector<int> cols;

    for (int col = 0; col < n; ++col) {
      if (colsum[col] == 0) {
        grid[0][col] = grid[1][col] = 0;
      } else if (colsum[col] == 2) {
        grid[0][col] = grid[1][col] = 1;
        upper--;
        lower--;
      } else {
        // colsum is 1
        cols.push_back(col);
      }
    }

    for (int col : cols) {
      if (upper) {
        grid[0][col] = 1;
        grid[1][col] = 0;
        upper--;
      } else {
        grid[0][col] = 0;
        grid[1][col] = 1;
        lower--;
      }
    }

    if (lower != 0 || upper != 0)
      return {};

    return grid;
  }
};

int main() {
  vector<int> colsum = {1, 1, 1};
  vector<vector<int>> ans;
  ans = Solution::reconstructMatrix(2, 1, colsum);
  for (const auto &row : ans) {
    for (int elem : row)
      printf("%d ", elem);
    printf("\n");
  }

  colsum = {2, 2, 1, 1};
  ans = Solution::reconstructMatrix(2, 3, colsum);
  for (const auto &row : ans) {
    for (int elem : row)
      printf("%d ", elem);
    printf("\n");
  }

  colsum = {2, 1, 2, 0, 1, 0, 1, 2, 0, 1};
  ans = Solution::reconstructMatrix(5, 5, colsum);
  for (const auto &row : ans) {
    for (int elem : row)
      printf("%d ", elem);
    printf("\n");
  }

  colsum = {1, 0, 2, 2, 1};
  ans = Solution::reconstructMatrix(3, 0, colsum);
  for (const auto &row : ans) {
    for (int elem : row)
      printf("%d ", elem);
    printf("\n");
  }

  colsum = {2, 1, 2, 0, 0, 2};
  ans = Solution::reconstructMatrix(1, 4, colsum);
  for (const auto &row : ans) {
    for (int elem : row)
      printf("%d ", elem);
    printf("\n");
  }

  colsum = {2, 1, 2, 2, 1, 1, 1};
  ans = Solution::reconstructMatrix(4, 7, colsum);
  for (const auto &row : ans) {
    for (int elem : row)
      printf("%d ", elem);
    printf("\n");
  }
}
