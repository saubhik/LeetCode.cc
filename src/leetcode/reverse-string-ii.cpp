//
// Created by saubhik on 2020/03/17.
//
#include <algorithm>
#include <string>

class Solution {
public:
  // Runtime: 4 ms, faster than 95.85% of C++ online submissions for Reverse
  // String II. Memory Usage: 8.8 MB, less than 100.00% of C++ online
  // submissions for Reverse String II.
  //
  // O(n) time, O(1) space.
  static std::string reverseStr(std::string s, int k) {
    int n = s.length(), p, q;
    for (int i = 0; i < n; i += 2 * k) {
      for (p = i, q = std::min(i + k, n) - 1; p < q; ++p, --q)
        std::swap(s[p], s[q]);
    }
    return s;
  }
};

int main() {
  printf("%s\n", Solution::reverseStr("abcdefg", 2).c_str());
  printf("%s\n", Solution::reverseStr("abcdefg", 4).c_str());
  printf("%s", Solution::reverseStr("abcdefg", 8).c_str());
}
