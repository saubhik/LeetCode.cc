//
// Created by saubhik on 2019/10/28.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // O(n log n) time, where n is the number of cells
    static vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> cells;

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                int coords[] = {i, j};
                cells.emplace_back(coords, coords + sizeof(coords) / sizeof(int));
            }

        sort(cells.begin(), cells.end(), [&](auto &left, auto &right) {
            return (abs(left[0] - r0) + abs(left[1] - c0)) < (abs(right[0] - r0) + abs(right[1] - c0));
        });

        return cells;
    }

    // TODO: O(n) time
    static void allCellsDistOrderLinear(int R, int C, int r0, int c0) {
    }
};

int main() {
    vector<vector<int>> grid = Solution::allCellsDistOrder(1, 2, 0, 0);
    for (const vector<int> &v : grid) {
        for (int x : v) cout << x << ' ';
        cout << endl;
    }
}
