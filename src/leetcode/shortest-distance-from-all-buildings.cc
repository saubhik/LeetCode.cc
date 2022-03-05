class Solution {
 public:
  // BFS from every cell with 1.
  // Store the distances in the grid.
  // Go through all 0s and sum the shortest distances.
  //
  // 0 2 1
  // 1 0 2
  // 0 1 0
  // Important: Might not be reachable from all houses.
  int shortestDistance(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans;

    vector<vector<int>> dist(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ans = bfs(grid, dist, m, n, i, j);
        }
      }
    }

    return ans;
  }

 private:
  int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
  int mark = 0;
  int bfs(vector<vector<int>>& grid, vector<vector<int>>& dist, const int m,
          const int n, int i, int j) {
    int level = 1;
    int ans = INT_MAX;
    vector<pair<int, int>> q, r;  // BFS using two vectors.
    q.push_back(make_pair(i, j));
    while (!q.empty()) {
      int ls = q.size();
      // Iterate over all cells in same level.
      for (int k = 0; k < ls; ++k) {
        pair<int, int>& p = q[k];
        for (int i = 0; i < 4; ++i) {
          int newi = p.first + dirs[i][0];
          int newj = p.second + dirs[i][1];
          if (0 <= newi && newi < m && 0 <= newj && newj < n &&
              grid[newi][newj] == mark) {
            grid[newi][newj]--;
            dist[newi][newj] += level;
            ans = min(ans, dist[newi][newj]);
            r.push_back(make_pair(newi, newj));
          }
        }
      }
      swap(q, r);
      r.clear();
      ++level;
    }
    --mark;
    return ans == INT_MAX ? -1 : ans;
  }
};
