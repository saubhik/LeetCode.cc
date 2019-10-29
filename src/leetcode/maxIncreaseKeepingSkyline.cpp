//
// Created by saubhik on 2019/10/27.
//
#include<vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
        vector<int>::size_type rows = grid.size(), cols = grid[0].size();
        vector<int> maxRows(rows), maxCols(cols);

        unsigned long i, j;
        int ans = 0;

        for (i = 0; i < rows; i++)
            for (j = 0; j < cols; j++) {
                maxRows[i] = max(maxRows[i], grid[i][j]);
                maxCols[j] = max(maxCols[j], grid[i][j]);
            }

        for (i = 0; i < rows; i++)
            for (j = 0; j < cols; j++)
                ans += min(maxRows[i], maxCols[j]) - grid[i][j];

        return ans;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> grid = {{3, 0, 8, 4},
                                {2, 4, 5, 7},
                                {9, 2, 6, 3},
                                {0, 3, 1, 0}};
    // expected: 35
    cout << obj.maxIncreaseKeepingSkyline(grid);
}

