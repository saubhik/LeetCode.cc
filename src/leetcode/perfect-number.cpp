//
// Created by saubhik on 2020/05/06.
//
#include <cmath>
#include <iostream>

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Perfect
  // Number. Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions
  // for Perfect Number.
  //
  // O(sqrt(n)) time, O(1) space.
  static bool checkPerfectNumber(int num) {
    if (num == 1) {
      return false;
    }

    int divSum = 1;
    for (int i = 2; i < sqrt(num); ++i) {
      if (num % i == 0) {
        divSum += i + (num / i);
      }
    }
    return num == divSum;
  }
};

int main() {
  assert(Solution::checkPerfectNumber(28));
  assert(!Solution::checkPerfectNumber(29));
  assert(!Solution::checkPerfectNumber(1));
}
