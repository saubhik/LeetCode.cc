//
// Created by saubhik on 2020/05/04.
//
#include "vector"

class Solution {
public:
  // Runtime: 16 ms, faster than 18.63% of C++ online submissions for Check If
  // It Is a Straight Line. Memory Usage: 9.9 MB, less than 100.00% of C++
  // online submissions for Check If It Is a Straight Line.
  //
  // O(n) time, O(1) space.
  static bool checkStraightLine(std::vector<std::vector<int>> &coordinates) {
    float slope = (float)(coordinates[1][1] - coordinates[0][1]) /
                  (float)(coordinates[1][0] - coordinates[0][0]);
    for (int i = 2; i < coordinates.size(); ++i)
      if ((float)(coordinates[i][1] - coordinates[i - 1][1]) /
              (float)(coordinates[i][0] - coordinates[i - 1][0]) !=
          slope)
        return false;

    return true;
  }
};

class Solution2 {
public:
  // doesn't improve speed without hack:
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
  static bool checkStraightLine(std::vector<std::vector<int>> &coordinates) {
    int x0 = coordinates[0][0], y0 = coordinates[0][1];
    int x1 = coordinates[1][0], y1 = coordinates[1][1];
    if (coordinates.size() == 2)
      return true;
    else if (x0 == x1) {
      for (int i = 2; i < coordinates.size(); ++i)
        if (coordinates[i][0] != x0)
          return false;
    } else if (y0 == y1) {
      for (int i = 2; i < coordinates.size(); ++i)
        if (coordinates[i][1] != y0)
          return false;
    } else {
      for (int i = 2; i < coordinates.size(); ++i)
        if ((float)(coordinates[i][1] - y0) / (float)(coordinates[i][0] - x0) !=
            (float)(y1 - y0) / (float)(x1 - x0))
          return false;
    }
    return true;
  }
};

int main() {
  // test case 1
  std::vector<std::vector<int>> coordinates = {{1, 2}, {2, 3}, {3, 4},
                                               {4, 5}, {5, 6}, {6, 7}};
  assert(Solution::checkStraightLine(coordinates));
  assert(Solution2::checkStraightLine(coordinates));

  // test case 2
  coordinates = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
  assert(!Solution::checkStraightLine(coordinates));
  assert(!Solution2::checkStraightLine(coordinates));

  // test case 3
  coordinates = {{-4, -3}, {1, 0}, {3, -1}, {0, -1}, {-5, 2}};
  assert(!Solution::checkStraightLine(coordinates));
  assert(!Solution2::checkStraightLine(coordinates));
}
