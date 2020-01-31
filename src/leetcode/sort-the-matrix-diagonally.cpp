//
// Created by saubhik on 2020/01/31.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 24 ms, faster than 98.94% of C++ online submissions for Sort the
  // Matrix Diagonally. Memory Usage: 10.7 MB, less than 100.00% of C++ online
  // submissions for Sort the Matrix Diagonally.
  //
  // O(m*n*lg(m)) time, O(m) space.
  static vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> diag;
    for (int k = m - 1; k >= (1 - n); --k) {
      diag.resize(0);
      for (int i = 0; i < m; ++i)
        if ((i - k) >= 0 && (i - k) < n)
          diag.emplace_back(mat[i][i - k]);
      sort(diag.begin(), diag.end());
      auto it = diag.begin();
      for (int i = 0; i < m; ++i)
        if ((i - k) >= 0 && (i - k) < n)
          mat[i][i - k] = *(it++);
    }
    return mat;
  }
};

int main() {
  vector<vector<int>> ans, mat = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
  ans = Solution::diagonalSort(mat);
  for (auto &row : mat) {
    for (int &elem : row)
      printf("%d ", elem);
    printf("\n");
  }
}
