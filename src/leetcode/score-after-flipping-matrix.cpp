//
// Created by saubhik on 2020/06/02.
//
#include <vector>

using namespace std;

class Solution {
public:
  // 0,0,1,1
  // 1,0,1,0
  // 1,1,0,0
  //
  // 1,1,0,0
  // 1,0,1,0
  // 1,1,0,0
  // ----------
  // 0, 0, 0, 1
  // 0, 1, 1, 1
  // 0, 0, 1, 0
  //
  // 1, 1, 0, 1
  // 1, 0, 1, 1
  // 1, 1, 1, 0
  //
  // 1, 1, 0, 1
  // 1, 0, 1, 1
  // 1, 1, 1, 0
  // ----------
  // 1, 0, 1, 1
  // 0, 1, 1, 0
  // 0, 1, 1, 1
  //
  // 1, 1, 0, 1
  // 1, 1, 1, 1
  // 1, 1, 1, 0
  //
  // 1, 1, 0, 1
  // 1, 1, 1, 1
  // 1, 1, 1, 0
  // ----------
  //
  // want to get lot of 1s in the beginnings.
  // change all first column to all 1s using only row ops.
  // it does not matter whether we use row ops or col ops.
  // then only use column ops.
  // flip columns for which #0s > #1s.
  //
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Score
  // After Flipping Matrix. Memory Usage: 8.3 MB, less than 100.00% of C++
  // online submissions for Score After Flipping Matrix.
  //
  // O(mn) time, O(1) additional space.
  static int matrixScore(vector<vector<int>> &A) {
    int m = A.size(), n = A[0].size();
    for (int i = 0; i < m; ++i) {
      if (A[i][0] == 0) {
        for (int j = 0; j < n; ++j) {
          A[i][j] = !A[i][j];
        }
      }
    }
    int ans = 0, twoPow = 1, count = 0;
    for (int j = n - 1; j >= 0; --j, twoPow *= 2, count = 0) {
      for (int i = 0; i < m; ++i) {
        if (A[i][j] == 1) {
          ++count;
        }
      }
      ans += twoPow * max(count, m - count);
    }
    return ans;
  }
};

class Solution2 {
public:
  // one-pass algorithm
  // 1 ^ 1 = 0
  // 0 ^ 0 = 0
  // 1 ^ 0 = 1
  // 0 ^ 1 = 1
  // xor-ing by 0 keeps everything same
  // xor-ing by 1 flips everything
  // So, applying a xor of a column to every column is valid.
  // xor-ing every column by first column, makes first column 0.
  static int matrixScore(vector<vector<int>> &A) {
    unsigned m = A.size(), n = A[0].size(), count, ans = 0;
    for (int j = 0; j < n; ++j) {
      count = 0;
      for (int i = 0; i < m; ++i) {
        count += (unsigned)A[i][j] ^ (unsigned)A[i][0];
      }
      ans += max(count, m - count) * ((unsigned)1 << (n - j - 1));
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> A;

  A = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
  assert(Solution::matrixScore(A) == 39);
  assert(Solution2::matrixScore(A) == 39);
}