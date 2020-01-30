//
// Created by saubhik on 2020/01/30.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Play with
  // Chips. Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions
  // for Play with Chips.
  //
  // O(n) time, O(1) space.
  static int minCostToMoveChips(vector<int> &chips) {
    int n = chips.size(), odds = 0, evens = 0;
    for (int i = 0; i < n; ++i)
      if (chips[i] % 2)
        ++odds;
      else
        ++evens;
    return min(odds, evens);
  }
};

int main() {
  vector<int> chips = {1, 2, 3};
  printf("%d\n", Solution::minCostToMoveChips(chips));

  chips = {2, 2, 2, 3, 3};
  printf("%d", Solution::minCostToMoveChips(chips));
}
