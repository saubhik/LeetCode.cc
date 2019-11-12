//
// Created by saubhik on 2019/11/11.
//
#include <vector>
using namespace std;

// 12.36% run-time, 50% memory
class Solution1 {
public:
  // O(NlogN) time
  static int smallestRangeI(vector<int> &A, int K) {
    sort(A.begin(), A.end());

    int ma, mi;

    A[0] += K;
    ma = mi = A[0];

    for (size_t i = 1; i < A.size(); ++i) {
      if (A[0] > A[i])
        A[i] = min(A[0], A[i] + K);

      else if (A[0] < A[i])
        A[i] = max(A[0], A[i] - K);

      ma = max(ma, A[i]);
      mi = min(mi, A[i]);
    }

    return ma - mi;
  }
};

class Solution2 {
public:
  // 88.63% run-time, 100% memory
  // O(N) time, O(1) space
  static int smallestRangeI(vector<int> &A, int K) {
    short mi = A[0], ma = A[0];

    for (size_t i = 1; i < A.size(); ++i) {
      mi = min((short)A[i], mi);
      ma = max((short)A[i], ma);
    }

    short diff = ma - (short)K - (mi + (short)K);

    return (diff < 0) ? 0 : diff;
  }
};

int main() {
  vector<int> arr = {1};
  printf("%d\n", Solution2::smallestRangeI(arr, 0));
  arr = {0, 10};
  printf("%d\n", Solution2::smallestRangeI(arr, 2));
  arr = {1, 3, 6};
  printf("%d", Solution2::smallestRangeI(arr, 3));
}
