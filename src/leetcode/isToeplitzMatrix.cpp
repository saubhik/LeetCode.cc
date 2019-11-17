//
// Created by saubhik on 2019/11/17.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 74.82% run-time, 100% memory
  // O(mn) time. O(1) additional space.
  static bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    for (int i = 0; i < rows; ++i)
      if (i == 0) {
        // check all diags including first row entries
        for (int j = 0; j < cols; ++j)
          for (int k = i + 1, col = j + 1; k < rows && col < cols; ++k, ++col)
            if (matrix[k][col] != matrix[k - 1][col - 1])
              return false;
      } else {
        // check only the first diag
        for (int k = i + 1, col = 1; k < rows && col < cols; ++k, ++col)
          if (matrix[k][col] != matrix[k - 1][col - 1])
            return false;
      }
    return true;
  }
};

class Solution2 {
public:
  // cleaner: Just check top left neighbor.
  // 100% run-time, 100% memory
  static bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (matrix[i - 1][j - 1] != matrix[i][j])
          return false;
    return true;
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
  printf("%d\n", Solution::isToeplitzMatrix(matrix));
  printf("%d\n", Solution2::isToeplitzMatrix(matrix));

  matrix = {{1, 2}, {2, 2}};
  printf("%d\n", Solution::isToeplitzMatrix(matrix));
  printf("%d\n", Solution2::isToeplitzMatrix(matrix));
}
