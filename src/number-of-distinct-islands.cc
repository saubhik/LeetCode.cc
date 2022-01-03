class Solution {
 public:
  /*
   * An island is same as another if one island can be
   * translated to equal the other.
   * Hash by Path Signature.
   */
  int numDistinctIslands(vector<vector<int>>& grid) {
    unordered_set<string> islands;
    string islandHash;

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          islandHash = "";
          findIsland(i, j, grid, islandHash);
          islands.insert(islandHash);
        }
      }
    }

    return islands.size();
  }

 private:
  void findIsland(int i, int j, vector<vector<int>>& grid, string& islandHash,
                  const char ch = 'S') {
    grid[i][j] = -1;  // mark visited

    islandHash.push_back(ch);

    if (0 <= i - 1 && i - 1 < grid.size() && grid[i - 1][j] == 1) {
      findIsland(i - 1, j, grid, islandHash, 'U');
      islandHash.push_back('D');
    }

    if (0 <= j - 1 && j - 1 < grid[0].size() && grid[i][j - 1] == 1) {
      findIsland(i, j - 1, grid, islandHash, 'L');
      islandHash.push_back('R');
    }

    if (0 <= i + 1 && i + 1 < grid.size() && grid[i + 1][j] == 1) {
      findIsland(i + 1, j, grid, islandHash, 'D');
      islandHash.push_back('U');
    }

    if (0 <= j + 1 && j + 1 < grid[0].size() && grid[i][j + 1] == 1) {
      findIsland(i, j + 1, grid, islandHash, 'R');
      islandHash.push_back('L');
    }
  }
};
