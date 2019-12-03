//
// Created by saubhik on 2019/12/03.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 95.68% run-time, 78.95% memory
  // O(n) time, O(1) space.
  static bool isMonotonic(vector<int> &A) {
    bool inc = true, dec = true;
    for (int i = 1; i < A.size(); ++i) {
      if (A[i] > A[i - 1] && dec)
        dec = false;
      if (A[i] < A[i - 1] && inc)
        inc = false;
      if (!inc && !dec)
        return false;
    }
    return inc || dec;
  }
};

int main() {
  vector<int> A = {1, 2, 2, 3};
  printf("%d\n", Solution::isMonotonic(A));

  A = {6, 5, 4, 4};
  printf("%d\n", Solution::isMonotonic(A));

  A = {1, 3, 2};
  printf("%d\n", Solution::isMonotonic(A));

  A = {1, 2, 4, 5};
  printf("%d\n", Solution::isMonotonic(A));

  A = {1, 1, 1};
  printf("%d\n", Solution::isMonotonic(A));
}
