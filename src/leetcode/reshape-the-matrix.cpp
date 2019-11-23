//
// Created by saubhik on 2019/11/23.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 62.68% run-time, 100% memory
  // O(mn) time, O(1) additional space.
  static vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r,
                                           int c) {
    int m = nums.size(), n = nums[0].size();

    if (m * n != r * c)
      return nums;

    vector<vector<int>> ans(r, vector<int>(c));
    int p = 0, q = 0;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        // will never get out of rows
        if (q == n)
          ++p, q = 0;
        ans[i][j] = nums[p][q++];
      }

    return ans;
  }
};

int main() {
  vector<vector<int>> nums = {{1, 2}, {3, 4}}, ans;
  ans = Solution::matrixReshape(nums, 1, 4);
  for (auto row : ans) {
    for (auto elem : row)
      printf("%d ", elem);
    printf("\n");
  }

  printf("\n");

  nums = {{1, 2}, {3, 4}};
  ans = Solution::matrixReshape(nums, 2, 4);
  for (auto row : ans) {
    for (auto elem : row)
      printf("%d ", elem);
    printf("\n");
  }
}
