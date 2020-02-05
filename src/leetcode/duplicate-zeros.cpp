//
// Created by saubhik on 2020/02/05.
//
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 20 ms, faster than 81.41% of C++ online submissions for Duplicate
  // Zeros. Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions
  // for Duplicate Zeros.
  //
  // O(n) time, O(n) space.
  static void duplicateZeros(vector<int> &arr) {
    queue<int> tmp;
    for (int &i : arr) {
      if (i == 0)
        tmp.push(0);
      if (tmp.empty())
        continue;
      else {
        tmp.push(i);
        i = tmp.front();
        tmp.pop();
      }
    }
  }
};

class Solution2 {
public:
  // Runtime: 16 ms, faster than 98.79% of C++ online submissions for Duplicate
  // Zeros. Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions
  // for Duplicate Zeros.
  //
  // Two pointer method, O(n) time, O(1) space.
  // One pointer is pointing at end, and other one at an hypothetical end.
  static void duplicateZeros(vector<int> &arr) {
    int numZeros = count(begin(arr), end(arr), 0);
    if (numZeros == 0)
      return;
    int n = arr.size(), j = n + numZeros - 1;
    for (int i = n - 1; i >= 0; --i) {
      if (j <= n - 1) {
        arr[j--] = arr[i];
        if (arr[i] == 0)
          arr[j--] = arr[i];
      } else {
        j = arr[i] == 0 ? j - 2 : j - 1;
        if (j == n - 2)
          arr[j + 1] = 0;
      }
    }
  }
};

class Solution3 {
public:
  // courtesy: Lee
  // Two pointer method, O(n) time, O(1) space.
  static void duplicateZeros(vector<int> &A) {
    int n = A.size(), j = n + count(A.begin(), A.end(), 0);
    for (int i = n - 1; i >= 0; --i) {
      if (--j < n)
        A[j] = A[i];
      if (A[i] == 0 && --j < n)
        A[j] = 0;
    }
  }
};

int main() {
  vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
  Solution2::duplicateZeros(arr);
  for (int &elem : arr)
    printf("%d ", elem);

  printf("\n");

  arr = {8, 4, 5, 0, 0, 0, 0, 7};
  Solution2::duplicateZeros(arr);
  for (int &elem : arr)
    printf("%d ", elem);
}
