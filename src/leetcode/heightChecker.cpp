//
// Created by saubhik on 2019/11/03.
//
#include <vector>
using namespace std;

class Solution {
public:
  // using partial_sort_copy
  static int heightChecker(vector<int> &heights) {
    int count = 0;
    vector<int> sorted(heights.size());
    partial_sort_copy(begin(heights), end(heights), begin(sorted), end(sorted));
    for (int i = 0; i < (int)heights.size(); ++i) {
      count += heights[i] != sorted[i];
    }
    return count;
  }

  // using vector constructor to copy
  static int heightChecker2(vector<int> &heights) {
    int count = 0;
    vector<int> sorted(heights);
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < (int)heights.size(); ++i)
      count += heights[i] != sorted[i];
    return count;
  }
};

int main() {
  vector<int> heights = {1, 1, 4, 2, 1, 3};
  printf("%d\n", Solution::heightChecker2(heights));
}