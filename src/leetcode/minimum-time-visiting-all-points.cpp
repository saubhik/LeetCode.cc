//
// Created by saubhik on 2020/01/03.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 4 ms, faster than 99.31% of C++ online submissions for Minimum
  // Time Visiting All Points. Memory Usage: 10.1 MB, less than 100.00% of C++
  // online submissions for Minimum Time Visiting All Points. O(n) time, O(1)
  // space.
  static int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int ans = 0, n = points.size(), h, v;
    for (int i = 1; i < n; ++i) {
      h = abs(points[i][0] - points[i - 1][0]),
      v = abs(points[i][1] - points[i - 1][1]);
      ans += min(h, v) + ((h > v) ? (h - v) : (v - h));
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
  printf("%d\n", Solution::minTimeToVisitAllPoints(points));

  points = {{3, 2}, {-2, 2}};
  printf("%d", Solution::minTimeToVisitAllPoints(points));
}
