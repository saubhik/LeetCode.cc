//
// Created by saubhik on 2019/11/02.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  static bool checkPossibility(vector<int> &nums) {
    int cnt = 0;
    for (int i = 1; i < (int)nums.size() && cnt <= 1; ++i) {
      // check for i lower than i-1
      // assume problem is solved till i-1
      // so nums[i-2] <= nums[i-1]
      if (nums[i] < nums[i - 1]) {
        if (i - 2 < 0 || nums[i - 2] <= nums[i]) {
          nums[i - 1] = nums[i];
          ++cnt;
        } else {
          nums[i] = nums[i - 1];
          ++cnt;
        }
      }
    }
    return cnt <= 1;
  }
};

int main() {
  vector<int> vec = {4, 2, 3};
  // expected: true
  cout << Solution::checkPossibility(vec);

  cout << "\n";

  vec = {4, 2, 1};
  // expected: false
  cout << Solution::checkPossibility(vec);

  cout << "\n";

  vec = {3, 4, 2, 3};
  // expected: false
  cout << Solution::checkPossibility(vec);
}
