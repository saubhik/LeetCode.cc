//
// Created by saubhik on 2019/12/16.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 96.72% run-time (12 ms), 100% memory (9.7MB).
  // O(n) time, O(1) space.
  static bool lemonadeChange(vector<int> &bills) {
    int count[3] = {};
    for (int num : bills) {
      if (num == 5)
        ++count[0];

      if (num == 10) {
        ++count[1];
        if (--count[0] < 0)
          return false;
      }

      if (num == 20) {
        ++count[2];
        if ((count[1] == 0 && count[0] < 3) || (count[0] == 0))
          return false;
        else {
          if (count[1] > 0)
            --count[1], --count[0];
          else
            count[0] -= 3;
        }
      }
    }
    return true;
  }
};

int main() {
  vector<int> bills = {5, 5, 5, 10, 20};
  printf("%d\n", Solution::lemonadeChange(bills));

  bills = {5, 5, 10};
  printf("%d\n", Solution::lemonadeChange(bills));

  bills = {10, 10};
  printf("%d\n", Solution::lemonadeChange(bills));

  bills = {5, 5, 10, 10, 20};
  printf("%d\n", Solution::lemonadeChange(bills));
}
