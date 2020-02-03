//
// Created by saubhik on 2020/02/03.
//
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 12 ms, faster than 83.32% of C++ online submissions for The K
  // Weakest Rows in a Matrix. Memory Usage: 10.1 MB, less than 100.00% of C++
  // online submissions for The K Weakest Rows in a Matrix.
  //
  // O(mnlogm) time, O(m) space.
  static vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    int m = mat.size(), n = mat[0].size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 0, j; i < m; ++i) {
      for (j = 0; j < n && mat[i][j] == 1;)
        ++j;
      pq.emplace(j, i);
    }

    vector<int> ans;
    for (int i = 0; i < k; ++i)
      ans.push_back(pq.top().second), pq.pop();

    return ans;
  }
};

class Solution2 {
public:
  // Runtime: 12 ms, faster than 83.32% of C++ online submissions for The K
  // Weakest Rows in a Matrix. Memory Usage: 10.2 MB, less than 100.00% of C++
  // online submissions for The K Weakest Rows in a Matrix.
  //
  // votrubac's solution
  static vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    set<pair<int, int>> s;
    for (auto i = 0; i < mat.size(); ++i) {
      auto j = accumulate(begin(mat[i]), end(mat[i]), 0);
      s.insert({j, i});
    }
    vector<int> ans;
    for (auto it = begin(s); k > 0; ++it, --k)
      ans.push_back(it->second);
    return ans;
  }
};

int main() {
  vector<vector<int>> mat = {{1, 1, 0, 0, 0},
                             {1, 1, 1, 1, 0},
                             {1, 0, 0, 0, 0},
                             {1, 1, 0, 0, 0},
                             {1, 1, 1, 1, 1}};
  vector<int> ans;
  ans = Solution::kWeakestRows(mat, 3);
  for (auto &elem : ans)
    printf("%d ", elem);

  printf("\n");

  mat = {{1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}};
  ans = Solution::kWeakestRows(mat, 2);
  for (auto &elem : ans)
    printf("%d ", elem);
}
