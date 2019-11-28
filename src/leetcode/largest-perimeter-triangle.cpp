//
// Created by saubhik on 2019/11/28.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 49.94% run-time, 100% memory
  // O(nlogn) time, O(1) space
  static int largestPerimeter(vector<int> &A) {
    sort(A.begin(), A.end());
    for (auto i = A.size() - 3; i >= 0; --i)
      if (A[i] + A[i + 1] > A[i + 2])
        return A[i] + A[i + 1] + A[i + 2];
    return 0;
  }
};

int main() {
  vector<int> A = {2, 1, 2};
  printf("%d\n", Solution::largestPerimeter(A));

  A = {1, 2, 1};
  printf("%d\n", Solution::largestPerimeter(A));

  A = {3, 2, 3, 4};
  printf("%d\n", Solution::largestPerimeter(A));

  A = {3, 6, 2, 3};
  printf("%d\n", Solution::largestPerimeter(A));
}
