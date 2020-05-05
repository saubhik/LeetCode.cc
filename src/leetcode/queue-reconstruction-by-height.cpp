//
// Created by saubhik on 2020/05/05.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 272 ms, faster than 47.75% of C++ online submissions for Queue
  // Reconstruction by Height. Memory Usage: 12.2 MB, less than 95.24% of C++
  // online submissions for Queue Reconstruction by Height.
  //
  // O(nlgn + n^2) = O(n^2) time, O(n) space.
  static vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    sort(begin(people), end(people), [](const auto &a, const auto &b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });
    vector<vector<int>> res;
    for (auto &p : people) {
      res.insert(begin(res) + p[1], p);
    }
    return res;
  }
};

int main() {
  vector<vector<int>> ans,
      people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  ans = Solution::reconstructQueue(people);
  vector<vector<int>> expected = {{5, 0}, {7, 0}, {5, 2},
                                  {6, 1}, {4, 4}, {7, 1}};
  assert(ans == expected);
}
