//
// Created by saubhik on 2020/03/05.
//
#include <vector>

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for
  // Battleships in a Board. Memory Usage: 8.6 MB, less than 100.00% of C++
  // online submissions for Battleships in a Board.
  //
  // O(n) time, one-pass, O(1) memory, no modification to board
  static int countBattleships(std::vector<std::vector<char>> &board) {
    int m = board.size(), n = board[0].size(), count = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'X') {
          if ((i > 0 && board[i - 1][j] == 'X') ||
              (j > 0 && board[i][j - 1] == 'X'))
            continue;
          ++count;
        }
      }
    }
    return count;
  }
};

int main() {
  std::vector<std::vector<char>> board = {
      {'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
  printf("%d", Solution::countBattleships(board));
}
