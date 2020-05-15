//
// Created by saubhik on 2020/05/15.
//
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of
  // Square Numbers. Memory Usage: 5.9 MB, less than 100.00% of C++ online
  // submissions for Sum of Square Numbers.
  //
  // O(sqrt(c/2)) time, O(1) space.
  static bool judgeSquareSum(int c) {
    int s;
    for (int i = 0; i * i <= c / 2; ++i) {
      s = sqrt(c - i * i);
      if (s * s + i * i == c) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  assert(Solution::judgeSquareSum(5));
  assert(!Solution::judgeSquareSum(3));
  assert(Solution::judgeSquareSum(2));
}
