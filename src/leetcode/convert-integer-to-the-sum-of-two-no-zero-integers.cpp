//
// Created by saubhik on 2020/03/16.
//
#include <vector>

class Solution {
private:
  static bool checkNoZero(int i) {
    while (i) {
      if (i % 10 == 0)
        return false;
      i /= 10;
    }
    return true;
  }

public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Convert
  // Integer to the Sum of Two No-Zero Integers. Memory Usage: 7.5 MB, less than
  // 100.00% of C++ online submissions for Convert Integer to the Sum of Two
  // No-Zero Integers.
  //
  // O(n) time, O(1) space.
  static std::vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i <= n / 2; ++i)
      if (checkNoZero(i) && checkNoZero(n - i))
        return {i, n - i};
    return {};
  }
};

int main() {
  std::vector<int> ans;
  ans = Solution::getNoZeroIntegers(2);
  for (auto &elem : ans)
    printf("%d ", elem);

  printf("\n");

  ans = Solution::getNoZeroIntegers(11);
  for (auto &elem : ans)
    printf("%d ", elem);

  printf("\n");

  ans = Solution::getNoZeroIntegers(10000);
  for (auto &elem : ans)
    printf("%d ", elem);

  printf("\n");

  ans = Solution::getNoZeroIntegers(69);
  for (auto &elem : ans)
    printf("%d ", elem);

  printf("\n");

  ans = Solution::getNoZeroIntegers(1010);
  for (auto &elem : ans)
    printf("%d ", elem);
}
