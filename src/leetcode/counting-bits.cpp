//
// Created by saubhik on 2020/03/05.
//
#include <vector>

class Solution {
public:
  // Runtime: 44 ms, faster than 100.00% of C++ online submissions for Counting
  // Bits. Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for
  // Counting Bits.
  //
  // O(n) time, one-pass, O(n) space.
  // Do not use any built in functions.
  static std::vector<int> countBits(int num) {
    std::vector<int> ans(num + 1, 0);
    for (int curr = 1, tmp = curr; curr < num + 1; tmp = curr)
      for (int i = 0; i < tmp && curr < num + 1; ++i, ++curr)
        ans[curr] = 1 + ans[i];
    return ans;
  }
};

int main() {
  std::vector<int> ans;
  ans = Solution::countBits(2);
  for (int elem : ans)
    printf("%d ", elem);

  printf("\n");

  ans = Solution::countBits(5);
  for (int elem : ans)
    printf("%d ", elem);
}
