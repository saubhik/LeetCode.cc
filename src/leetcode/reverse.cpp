//
// Created by saubhik on 2019/11/02.
//
#include <iostream>
using namespace std;

class Solution {
public:
  static int reverse(int x) {
    int num = 0;
    while (x) {
      if (num > INT_MAX / 10 || num < INT_MIN / 10)
        return 0;
      num = num * 10 + x % 10;
      x /= 10;
    }
    return num;
  }
};

int main() {
  cout << Solution::reverse(-120);
  cout << "\n";
  cout << Solution::reverse(1534236469);
  cout << "\n";
  cout << Solution::reverse(-2147483648);
}
