//
// Created by saubhik on 2019/12/12.
//
#include <string>
using namespace std;

class Solution {
public:
  // 100% run-time, 61.22% space.
  // O(|s|) time, O(1) space.
  static int titleToNumber(string s, int ans = 0) {
    for (auto ch : s)
      ans = ans * 26 + (ch - 'A' + 1);
    return ans;
  }
};

int main() {
  printf("%d\n", Solution::titleToNumber("A"));
  printf("%d\n", Solution::titleToNumber("AB"));
  printf("%d", Solution::titleToNumber("ZY"));
}
