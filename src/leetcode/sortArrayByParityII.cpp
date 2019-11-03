//
// Created by saubhik on 2019/11/03.
//
#include <vector>
using namespace std;

class Solution {
public:
  static vector<int> sortArrayByParityII(vector<int> &A) {
    vector<int> ans(A.size());
    int evenPtr = 0, oddPtr = 0;
    for (int i = 0; i < (int)ans.size(); ++i) {
      if (i % 2 == 0) {
        while (evenPtr < A.size() && A[evenPtr] % 2 == 1)
          evenPtr++;
        ans[i] = A[evenPtr++];
      } else {
        while (oddPtr < A.size() && A[oddPtr] % 2 == 0)
          oddPtr++;
        ans[i] = A[oddPtr++];
      }
    }
    return ans;
  }

  // traditional two pass
  static vector<int> sortArrayByParityII2(vector<int> &A) {
    vector<int> ans(A.size());

    // pass once to store the even entries
    int t = 0;
    for (int elem : A) {
      if (elem % 2 == 0) {
        ans[t] = elem;
        t += 2;
      }
    }

    // pass once to store the odd entries
    t = 1;
    for (int elem : A) {
      if (elem % 2 == 1) {
        ans[t] = elem;
        t += 2;
      }
    }

    return ans;
  }

  // constant space, two pointers, in-place
  static vector<int> sortArrayByParityII3(vector<int> &A) {
    int evenPtr = 0, oddPtr = 1, tmp;
    for (; evenPtr < (int)A.size(); evenPtr += 2) {
      if (A[evenPtr] % 2 == 1) {
        while (A[oddPtr] % 2 == 1)
          oddPtr += 2;
        // swap
        tmp = A[evenPtr];
        A[evenPtr] = A[oddPtr];
        A[oddPtr] = tmp;
      }
    }
    return A;
  }
};

int main() {
  vector<int> vec = {4, 2, 5, 7}, ans;
  ans = Solution::sortArrayByParityII(vec);
  for (int elem : ans)
    printf("%d ", elem);

  printf("\n");

  ans = Solution::sortArrayByParityII2(vec);
  for (int elem : ans)
    printf("%d ", elem);

  printf("\n");

  ans = Solution::sortArrayByParityII3(vec);
  for (int elem : ans)
    printf("%d ", elem);
}
