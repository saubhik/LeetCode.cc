//
// Created by saubhik on 2020/05/06.
//
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Powerful
  // Integers. Memory Usage: 6.8 MB, less than 100.00% of C++ online submissions
  // for Powerful Integers.
  //
  // O(mn) time, where m = lg(bound)/lg(x), n = lg(bound)/lg(y).
  // O(lg^2) time, O(lg^2) space.
  static vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> ans;
    for (int i = 0; pow(x, i) < bound; ++i) {
      for (int j = 0; pow(x, i) + pow(y, j) <= bound; ++j) {
        ans.insert(pow(x, i) + pow(y, j));
        if (y == 1) {
          break;
        }
      }
      if (x == 1) {
        break;
      }
    }

    vector<int> res;
    res.insert(end(res), begin(ans), end(ans));
    return res;
  }
};

int main() {
  vector<int> expected;
  expected = {9, 7, 3, 5, 10, 4, 2};
  assert(Solution::powerfulIntegers(2, 3, 10) == expected);

  expected = {14, 10, 8, 4, 6, 2};
  assert(Solution::powerfulIntegers(3, 5, 15) == expected);

  expected = {9, 5, 3, 2};
  assert(Solution::powerfulIntegers(2, 1, 10) == expected);

  expected = {2};
  assert(Solution::powerfulIntegers(1, 1, 10) == expected);
}
