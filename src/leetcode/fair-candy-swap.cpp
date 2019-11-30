//
// Created by saubhik on 2019/11/30.
//
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  // 87.48% run-time, 50% memory
  // O(n1 + n2) time, O(n2) space
  static vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
    int sumA = accumulate(A.begin(), A.end(), 0),
        sumB = accumulate(B.begin(), B.end(), 0), target = (sumA + sumB) / 2;
    bool swapped = false;
    if (A.size() < B.size()) {
      swap(A, B);
      swap(sumA, sumB);
      swapped = true;
    }
    unordered_set<int> st(B.begin(), B.end());
    for (int num : A) {
      int other = target - (sumA - num);
      if (st.find(other) != st.end()) {
        if (swapped)
          return {other, num};
        else
          return {num, other};
      }
    }
    return {};
  }
};

int main() {
  vector<int> A = {1, 1}, B = {2, 2}, ans;
  ans = Solution::fairCandySwap(A, B);
  for (auto num : ans)
    printf("%d ", num);

  printf("\n");

  A = {1, 2}, B = {2, 3};
  ans = Solution::fairCandySwap(A, B);
  for (auto num : ans)
    printf("%d ", num);

  printf("\n");

  A = {2}, B = {1, 3};
  ans = Solution::fairCandySwap(A, B);
  for (auto num : ans)
    printf("%d ", num);

  printf("\n");

  A = {1, 2, 5}, B = {2, 4};
  ans = Solution::fairCandySwap(A, B);
  for (auto num : ans)
    printf("%d ", num);
}
