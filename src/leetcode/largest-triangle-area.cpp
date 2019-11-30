//
// Created by saubhik on 2019/12/01.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 78.41% run-time, 100% memory
  // Formula can be derived easily from cross product definition of
  // area of a triangle.
  // O(n^3) time, O(1) additional space.
  static double largestTriangleArea(vector<vector<int>> &points) {
    int n = points.size();
    double ans = 0.0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        for (int k = j + 1; k < n; ++k)
          ans = max(ans, 0.5 * abs(points[i][0] * points[j][1] +
                                   points[j][0] * points[k][1] +
                                   points[k][0] * points[i][1] -
                                   points[i][0] * points[k][1] -
                                   points[j][0] * points[i][1] -
                                   points[k][0] * points[j][1]));
    return ans;
  }
};

int main() {
  vector<vector<int>> points = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
  printf("%f", Solution::largestTriangleArea(points));
}
