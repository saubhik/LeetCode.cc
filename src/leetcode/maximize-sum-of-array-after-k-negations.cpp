//
// Created by saubhik on 2019/12/18.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 97.74%, 4ms run-time, 92.86%, 8.6MB memory.
  // O(nlgn) time, O(1) space.
  static int largestSumAfterKNegations(vector<int> &A, int K) {
    int sum = 0;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] < 0 && K)
        A[i] *= -1, --K;
      else if (K % 2 == 1)
        sum -= i >= 1 ? 2 * min(A[i], A[i - 1]) : 2 * A[i], K = 0;
      sum += A[i];
    }
    return sum;
  }
};

int main() {
  vector<int> A = {2, -3, -1, 5, -4};
  printf("%d\n", Solution::largestSumAfterKNegations(A, 2));

  A = {3, -1, 0, 2};
  printf("%d\n", Solution::largestSumAfterKNegations(A, 3));

  A = {4, 2, 3};
  printf("%d\n", Solution::largestSumAfterKNegations(A, 1));
}
