//
// Created by saubhik on 2020/01/01.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 148 ms, faster than 81.59% of C++ online submissions for Image
  // Smoother. Memory Usage: 17.5 MB, less than 100.00% of C++ online
  // submissions for Image Smoother.
  // O(mn) time, O(1) space.
  static vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
    int m = M.size(), n = M[0].size(), count;
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        ans[i][j] = M[i][j], count = 1;
        if (0 <= i - 1 && i - 1 < m && 0 <= j - 1 && j - 1 < n)
          ans[i][j] += M[i - 1][j - 1], ++count;
        if (0 <= i - 1 && i - 1 < m && 0 <= j && j < n)
          ans[i][j] += M[i - 1][j], ++count;
        if (0 <= i - 1 && i - 1 < m && 0 <= j + 1 && j + 1 < n)
          ans[i][j] += M[i - 1][j + 1], ++count;
        if (0 <= i && i < m && 0 <= j - 1 && j - 1 < n)
          ans[i][j] += M[i][j - 1], ++count;
        if (0 <= i && i < m && 0 <= j + 1 && j + 1 < n)
          ans[i][j] += M[i][j + 1], ++count;
        if (0 <= i + 1 && i + 1 < m && 0 <= j - 1 && j - 1 < n)
          ans[i][j] += M[i + 1][j - 1], ++count;
        if (0 <= i + 1 && i + 1 < m && 0 <= j && j < n)
          ans[i][j] += M[i + 1][j], ++count;
        if (0 <= i + 1 && i + 1 < m && 0 <= j + 1 && j + 1 < n)
          ans[i][j] += M[i + 1][j + 1], ++count;
        ans[i][j] /= count;
      }
    return ans;
  }
};

int main() {
  vector<vector<int>> M, ans;
  M = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  ans = Solution::imageSmoother(M);
  for (auto row : ans) {
    for (auto num : row)
      printf("%d ", num);
    printf("\n");
  }
}
