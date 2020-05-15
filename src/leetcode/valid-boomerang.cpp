//
// Created by saubhik on 2020/05/15.
//
#include <vector>

using namespace std;

class Solution {
public:
  // Runtime: 4 ms, faster than 31.24% of C++ online submissions for Valid
  // Boomerang. Memory Usage: 10 MB, less than 100.00% of C++ online submissions
  // for Valid Boomerang.
  //
  // O(1) time, O(1) space.
  static bool isBoomerang(vector<vector<int>> &points) {
    int x1 = points[0][0];
    int y1 = points[0][1];
    int x2 = points[1][0];
    int y2 = points[1][1];
    int x3 = points[2][0];
    int y3 = points[2][1];
    return (y3 - y2) * (x2 - x1) != (y2 - y1) * (x3 - x2);
  }
};

int main() {
  vector<vector<int>> points;

  points = {{1, 1}, {2, 3}, {3, 2}};
  assert(Solution::isBoomerang(points));

  points = {{1, 1}, {2, 2}, {3, 3}};
  assert(!Solution::isBoomerang(points));
}
