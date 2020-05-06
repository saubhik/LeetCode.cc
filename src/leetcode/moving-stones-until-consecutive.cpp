//
// Created by saubhik on 2020/05/06.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Moving
  // Stones Until Consecutive. Memory Usage: 6.2 MB, less than 100.00% of C++
  // online submissions for Moving Stones Until Consecutive.
  //
  // O(1) time, O(1) space.
  static vector<int> numMovesStones(int a, int b, int c) {
    vector<int> res(2), positions = {a, b, c};
    sort(begin(positions), end(positions));

    // maximum moves
    res[1] =
        (positions[2] - positions[1] - 1) + (positions[1] - positions[0] - 1);

    // minimum moves
    if (positions[2] - positions[1] == 2 || positions[1] - positions[0] == 2) {
      // insert between two
      res[0] = 1;
    } else {
      res[0] = 0;
      if (positions[2] - positions[1] > 1) {
        ++res[0];
      }
      if (positions[1] - positions[0] > 1) {
        ++res[0];
      }
    }

    return res;
  }
};

int main() {
  vector<int> expected;

  expected = {1, 2};
  assert(Solution::numMovesStones(1, 2, 5) == expected);

  expected = {0, 0};
  assert(Solution::numMovesStones(4, 3, 2) == expected);

  expected = {1, 2};
  assert(Solution::numMovesStones(3, 5, 1) == expected);
}
