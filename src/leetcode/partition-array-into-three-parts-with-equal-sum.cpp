//
// Created by saubhik on 2019/12/03.
//
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  // 97.20% run-time, 100% memory
  // O(n) time, O(1) space
  static bool canThreePartsEqualSum(vector<int> &A) {
    int count = 0, target = accumulate(A.begin(), A.end(), 0) / 3, tmp = 0;
    for (int num : A) {
      tmp += num;
      if (tmp == target) {
        tmp = 0;
        ++count;
      }
    }
    return (target == 0) ? count > 2 : count == 3;
  }
};

int main() {
  vector<int> A = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
  printf("%d\n", Solution::canThreePartsEqualSum(A));

  A = {0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1};
  printf("%d\n", Solution::canThreePartsEqualSum(A));

  A = {3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
  printf("%d\n", Solution::canThreePartsEqualSum(A));

  A = {-1, 1, 0, 1, -1, -1, 1};
  printf("%d\n", Solution::canThreePartsEqualSum(A));
}
