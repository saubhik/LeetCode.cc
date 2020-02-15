//
// Created by saubhik on 2020/02/15.
//
#include <vector>

class Solution {
public:
  // Runtime: 24 ms, faster than 96.19% of C++ online submissions for Matrix
  // Block Sum. Memory Usage: 11.2 MB, less than 100.00% of C++ online
  // submissions for Matrix Block Sum.
  //
  // O(mn) time, O(1) space.
  static std::vector<std::vector<int>>
  matrixBlockSum(std::vector<std::vector<int>> &mat, int K) {
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (i - 1 >= 0)
          mat[i][j] += mat[i - 1][j];
        if (j - 1 >= 0)
          mat[i][j] += mat[i][j - 1];
        if (i - 1 >= 0 && j - 1 >= 0)
          mat[i][j] -= mat[i - 1][j - 1];
      }

    std::vector<std::vector<int>> answer(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        answer[i][j] += mat[std::min(i + K, m - 1)][std::min(j + K, n - 1)];
        if (i - K - 1 >= 0)
          answer[i][j] -= mat[i - K - 1][std::min(j + K, n - 1)];
        if (j - K - 1 >= 0)
          answer[i][j] -= mat[std::min(i + K, m - 1)][j - K - 1];
        if (i - K - 1 >= 0 && j - K - 1 >= 0)
          answer[i][j] += mat[i - K - 1][j - K - 1];
      }
    return answer;
  }
};

int main() {
  std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, ans;
  ans = Solution::matrixBlockSum(mat, 1);
  for (auto &row : ans) {
    for (auto &elem : row)
      printf("%d ", elem);
    printf("\n");
  }

  printf("\n");

  mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  ans = Solution::matrixBlockSum(mat, 2);
  for (auto &row : ans) {
    for (auto &elem : row)
      printf("%d ", elem);
    printf("\n");
  }
}
