class Solution {
 public:
  // For each cell, store the area containing the cell.
  // 1,1,1
  // 1,0,0
  // 0,1,0
  //
  // 4,4,4
  // 4,0,0
  // 0,1,0
  //
  // But the left & up 4s belong to the same area.
  // So store the region index. Maybe hash it as:
  // "-regionIdx".
  int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int region = 1;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          dfs(grid, n, region, i, j);
          ++region;
        }
      }
    }

    int maxSize = 0;
    for (int r = 1; r < region; ++r) {
      maxSize = max(maxSize, regionSize[r]);
    }

    int newi, newj;
    unordered_set<int> surroundingRegions;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          surroundingRegions.clear();
          for (int k = 0; k < 4; ++k) {
            newi = i + dirs[k][0];
            newj = j + dirs[k][1];
            if (0 <= newi && newi < n && 0 <= newj && newj < n &&
                grid[newi][newj] < 0) {
              surroundingRegions.insert(-grid[newi][newj]);
            }
          }
          int size = 1;  // including grid[i][j] = 0.
          for (int region : surroundingRegions) size += regionSize[region];
          if (size > maxSize) maxSize = size;
        }
      }
    }

    return maxSize;
  }

 private:
  unordered_map<int, int> regionSize;
  int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int dfs(vector<vector<int>>& grid, int n, int region, int r, int c) {
    int size = 1;
    grid[r][c] = -region;  // visited
    int newr, newc;
    for (int i = 0; i < 4; ++i) {
      newr = r + dirs[i][0];
      newc = c + dirs[i][1];
      if (0 <= newr && newr < n && 0 <= newc && newc < n &&
          grid[newr][newc] == 1) {
        size += dfs(grid, n, region, newr, newc);
      }
    }
    regionSize[region] = size;
    return size;
  }
};
