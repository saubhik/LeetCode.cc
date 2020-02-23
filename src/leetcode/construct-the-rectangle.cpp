//
// Created by saubhik on 2020/02/23.
//
#include <cmath>
#include <vector>

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Construct
  // the Rectangle. Memory Usage: 8.2 MB, less than 75.00% of C++ online
  // submissions for Construct the Rectangle.
  //
  // O(sqrt(n)) time, O(1) space.
  static std::vector<int> constructRectangle(int area) {
    short w = sqrt(area);
    while (area % w != 0)
      --w;
    return {area / w, w};
  }
};

int main() {
  std::vector<int> ans = Solution::constructRectangle(4);
  printf("%d, %d\n", ans[0], ans[1]);

  ans = Solution::constructRectangle(5);
  printf("%d, %d\n", ans[0], ans[1]);
}
