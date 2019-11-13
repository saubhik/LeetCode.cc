//
// Created by saubhik on 2019/11/13.
//
#include <vector>
using namespace std;
class Solution {
public:
  // 97.85% runtime, 100% memory
  static vector<vector<int>> transpose(vector<vector<int>> &A) {
    int m = A.size(), n = A[0].size();
    vector<vector<int>> B(n, vector<int>(m, 0));
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < m; ++j)
        B[i][j] = A[j][i];
    return B;
  }
};

int main() {
  vector<vector<int>> inp = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, out;
  out = Solution::transpose(inp);
  for (const auto &elem : out) {
    printf("[");
    for (auto num : elem)
      printf("%d,", num);
    printf("],");
  }

  printf("\n");

  inp = {{1, 2, 3}, {4, 5, 6}};
  out = Solution::transpose(inp);
  for (const auto &elem : out) {
    printf("[");
    for (auto num : elem)
      printf("%d,", num);
    printf("],");
  }
}
