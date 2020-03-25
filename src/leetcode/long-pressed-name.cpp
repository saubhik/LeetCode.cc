//
// Created by saubhik on 2020/03/25.
//
#include <string>

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Long
  // Pressed Name. Memory Usage: 6.2 MB, less than 100.00% of C++ online
  // submissions for Long Pressed Name.
  //
  // O(n) time, O(1) space.
  static bool isLongPressedName(std::string name, const std::string &typed) {
    int j = 0;
    for (char i : typed)
      if (j < name.length() && name[j] == i)
        ++j;
      else if (j == 0 || name[j - 1] != i)
        return false;
    return j == name.length();
  }
};

int main() {
  assert(Solution::isLongPressedName("alex", "aaleex"));
  assert(!Solution::isLongPressedName("saeed", "ssaaedd"));
  assert(Solution::isLongPressedName("leelee", "lleeelee"));
  assert(Solution::isLongPressedName("laiden", "laiden"));
  assert(!Solution::isLongPressedName("pyplrz", "ppyypllr"));
  assert(!Solution::isLongPressedName("dfuyalc", "fuuyallc"));
}
