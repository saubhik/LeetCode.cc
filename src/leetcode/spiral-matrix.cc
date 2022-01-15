class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    dfs(0, 0, 0, matrix, ans);
    return ans;
  }

  void dfs(int i, int j, int d, vector<vector<int>>& matrix, vector<int>& ans) {
    ans.push_back(matrix[i][j]);
    matrix[i][j] = 101;
    for (int count = 0; count < 4; ++count) {
      int ni = i + dirs[d][0];
      int nj = j + dirs[d][1];
      if (0 <= ni && ni < matrix.size() && 0 <= nj && nj < matrix[0].size() &&
          matrix[ni][nj] != 101) {
        dfs(ni, nj, d, matrix, ans);
        return;
      }
      d = (d + 1) % 4;
    }
  }

 private:
  int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};
