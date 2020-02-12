#include <cmath>
//
// Created by saubhik on 2020/02/12.
//
#include <bitset>

class Solution {
public:
  // O(n) time
  static int numberOfSteps(int num) {
    int ans = 0;
    while (num) {
      if (num % 2 == 0)
        num /= 2;
      else
        num -= 1;
      ++ans;
    }
    return ans;
  }
};

class Solution2 {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of
  // Steps to Reduce a Number to Zero. Memory Usage: 8.5 MB, less than 100.00%
  // of C++ online submissions for Number of Steps to Reduce a Number to Zero.
  //
  // courtesy: mhelvens
  // the number of steps required is the number of bits required to represent
  // the number and the number of set bits in the representation.
  // O(1) time, O(1) space.
  static int numberOfSteps(int num) {
    return num == 0 ? 0 : (int)log2(num) + (int)std::bitset<32>(num).count();
  }
};

int main() {
  printf("%d\n", Solution::numberOfSteps(14));
  printf("%d", Solution2::numberOfSteps(14));
}
