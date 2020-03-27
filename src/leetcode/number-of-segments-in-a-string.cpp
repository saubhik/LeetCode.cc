//
// Created by saubhik on 2020/03/27.
//
#include <string>

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of
  // Segments in a String. Memory Usage: 6.2 MB, less than 100.00% of C++ online
  // submissions for Number of Segments in a String.
  //
  // O(n) time, O(1) space.
  static int countSegments(std::string s) {
    int count = 1, n = s.length();
    bool hasSegment = false;
    for (int i = 0; i < n; ++i) {
      if (i + 1 < n && hasSegment && s[i] == ' ' && s[i + 1] != ' ') {
        ++count;
      }
      if (s[i] != ' ')
        hasSegment = true;
    }
    return hasSegment ? count : 0;
  }
};

int main() {
  assert(Solution::countSegments("Hello, my name is John") == 5);
  assert(Solution::countSegments("Hello,   ") == 1);
  assert(Solution::countSegments("  ") == 0);
  assert(Solution::countSegments("    Hello") == 1);
  assert(Solution::countSegments(" Hello,  my ") == 2);
  assert(Solution::countSegments("a") == 1);
}
