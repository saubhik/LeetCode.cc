//
// Created by saubhik on 2020/05/17.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  // Runtime: 680 ms, faster than 19.52% of C++ online submissions for Repeated
  // String Match. Memory Usage: 6.6 MB, less than 100.00% of C++ online
  // submissions for Repeated String Match.
  //
  // O(|A||B|) time, O(1) space.
  static int repeatedStringMatch(string A, string B) {
    int i, j, k, ans, m = A.size(), n = B.size();
    for (i = 0; i < m; ++i) {
      for (k = i, ans = 1, j = 0; j < n; ++j, ++k) {
        if (k == m) {
          k = 0;
          ++ans;
        }
        if (A[k] != B[j]) {
          break;
        }
      }
      if (j == n) {
        return ans;
      }
    }
    return -1;
  }
};

int main() {
  assert(Solution::repeatedStringMatch("abcd", "cdabcdab") == 3);
  assert(Solution::repeatedStringMatch("abcd", "dx") == -1);
  assert(Solution::repeatedStringMatch("abcd", "c") == 1);
  assert(Solution::repeatedStringMatch("dabcddd", "ddda") == 2);
  assert(Solution::repeatedStringMatch("a", "aa") == 2);
}
