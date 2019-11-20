//
// Created by saubhik on 2019/11/20.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 100% run-time, 100% memory
  // O(mn) time, O(1) additional space.
  static int numRookCaptures(vector<vector<char>> &board) {
    int m = board.size(), n = board[0].size(), ans = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (board[i][j] == 'R') {

          // check up
          int tmp = i;
          while (tmp--) {
            if (board[tmp][j] == 'p') {
              ++ans;
              break;
            }
            if (board[tmp][j] == 'B')
              break;
          }

          // check down
          tmp = i;
          while (++tmp < m) {
            if (board[tmp][j] == 'p') {
              ++ans;
              break;
            }
            if (board[tmp][j] == 'B')
              break;
          }

          // check left
          tmp = j;
          while (tmp--) {
            if (board[i][tmp] == 'p') {
              ++ans;
              break;
            }
            if (board[i][tmp] == 'B')
              break;
          }

          // check right
          tmp = j;
          while (++tmp < n) {
            if (board[i][tmp] == 'p') {
              ++ans;
              break;
            }
            if (board[i][tmp] == 'B')
              break;
          }

          break;
        }

    return ans;
  }
};

int main() {
  vector<vector<char>> board = {{'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', 'p', '.', '.', '.', '.'},
                                {'.', '.', '.', 'R', '.', '.', '.', 'p'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', 'p', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'}};
  printf("%d\n", Solution::numRookCaptures(board));

  board = {{'.', '.', '.', '.', '.', '.', '.', '.'},
           {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
           {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
           {'.', 'p', 'B', 'R', 'B', 'p', '.', '.'},
           {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
           {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.'}};
  printf("%d\n", Solution::numRookCaptures(board));

  board = {{'.', '.', '.', '.', '.', '.', '.', '.'},
           {'.', '.', '.', 'p', '.', '.', '.', '.'},
           {'.', '.', '.', 'p', '.', '.', '.', '.'},
           {'p', 'p', '.', 'R', '.', 'p', 'B', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.'},
           {'.', '.', '.', 'B', '.', '.', '.', '.'},
           {'.', '.', '.', 'p', '.', '.', '.', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.'}};
  printf("%d", Solution::numRookCaptures(board));
}
