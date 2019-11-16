//
// Created by saubhik on 2019/11/16.
//
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  // 99% run-time, 100% memory
  static int thirdMax(vector<int> &nums) {
    long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
    for (int num : nums) {
      if (num > max1) {
        max3 = max2;
        max2 = max1;
        max1 = num;
      }
      if (num > max2 && num != max1) {
        max3 = max2;
        max2 = num;
      }
      if (num > max3 && num != max2 && num != max1) {
        max3 = num;
      }
    }
    return max3 != LONG_MIN ? (int)max3 : (int)max1;
  }
};

class Solution2 {
public:
  // 34.10% run-time, 46.15% memory
  // using set to maintain top3
  static int thirdMax(vector<int> &nums) {
    set<int> s;
    for (int num : nums) {
      s.insert(num);
      if (s.size() > 3)
        s.erase(s.begin());
    }
    return (s.size() < 3) ? *s.rbegin() : *s.begin();
  }
};

int main() {
  vector<int> nums = {2, 2, 3, 1};
  printf("%d\n", Solution::thirdMax(nums));
  printf("%d\n", Solution2::thirdMax(nums));

  nums = {2, 0, 0, 2, 3, 3, 0, 0, -1, -1, 0};
  printf("%d\n", Solution::thirdMax(nums));
  printf("%d\n", Solution2::thirdMax(nums));

  nums = {0, 1, 2, 3};
  printf("%d\n", Solution::thirdMax(nums));
  printf("%d\n", Solution2::thirdMax(nums));

  nums = {1, 2, -2147483648};
  printf("%d\n", Solution::thirdMax(nums));
  printf("%d\n", Solution2::thirdMax(nums));
}
