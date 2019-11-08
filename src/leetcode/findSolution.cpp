//
// Created by saubhik on 2019/11/08.
//
#include <vector>
using namespace std;
class CustomFunction {
public:
  // Returns f(x, y) for any given positive integers x and y.
  // Note that f(x, y) is increasing with respect to both x and y.
  // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
  static int f(int x, int y);
};

int CustomFunction::f(int x, int y) { return x * y; }

class Solution {
public:
  // 100% run-time, 100% memory
  static vector<vector<int>> findSolution(CustomFunction &customFunction,
                                          int z) {
    vector<vector<int>> ans;
    for (int x = 1; x <= 1000; ++x) {
      if (customFunction.f(x, 1000) < z)
        // no point in searching for lower y
        continue;
      if (customFunction.f(x, 1) > z)
        // no point in searching anymore
        break;
      // our solution must be >= x;
      // linear search for y:
      // for (int y = 1000; y >= 1; --y) {
      //   if (customFunction.f(x, y) == z)
      //     ans.push_back({x, y});
      // binary search for y:
      int lo = 0, hi = 1000;
      while (lo < hi) {
        int mid = hi - (hi - lo) / 2;
        if (customFunction.f(x, mid) < z)
          lo = mid + 1;
        else if (customFunction.f(x, mid) > z)
          hi = mid - 1;
        else
          lo = hi = mid;
      }
      if (customFunction.f(x, hi) == z)
        ans.push_back({x, hi});
    }
    return ans;
  }
};

int main() {
  CustomFunction customFunction = CustomFunction();
  vector<vector<int>> res = Solution::findSolution(customFunction, 5);
  for (const auto &elem : res) {
    for (int num : elem)
      printf("%d ", num);
    printf("\n");
  }
}