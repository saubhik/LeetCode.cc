//
// Created by saubhik on 2020/02/14.
//
#include <string>
#include <vector>

class Solution {
public:
  // Runtime: 88 ms, faster than 84.41% of C++ online submissions for Minimum
  // Number of Steps to Make Two Strings Anagram. Memory Usage: 16.4 MB, less
  // than 100.00% of C++ online submissions for Minimum Number of Steps to Make
  // Two Strings Anagram.
  //
  // O(n) time, O(1) space.
  static int minSteps(const std::string &s, const std::string &t) {
    std::vector<int> counter(26, 0);
    for (auto &ch : s)
      ++counter[ch - 'a'];
    int ans = 0;
    for (auto &ch : t)
      if (--counter[ch - 'a'] < 0)
        ++ans;
    return ans;
  }
};

int main() {
  printf("%d\n", Solution::minSteps("bab", "aba"));
  printf("%d\n", Solution::minSteps("leetcode", "practice"));
  printf("%d\n", Solution::minSteps("anagram", "mangaar"));
  printf("%d\n", Solution::minSteps("xxyyzz", "xxyyzz"));
  printf("%d\n", Solution::minSteps("friend", "family"));
}
