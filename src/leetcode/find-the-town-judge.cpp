//
// Created by saubhik on 2019/12/31.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 152 ms, faster than 81.75% of C++ online submissions for Find the
  // Town Judge. Memory Usage: 42.2 MB, less than 100.00% of C++ online
  // submissions for Find the Town Judge.
  // O(n) time, O(n) space.
  static int findJudge(int N, vector<vector<int>> &trust) {
    vector<int> count(N + 1, 0);
    for (auto &pr : trust) {
      count[pr[0]] = -1;
      if (count[pr[1]] != -1)
        ++count[pr[1]];
    }
    for (int i = 1; i <= N; ++i)
      if (count[i] == N - 1)
        return i;
    return -1;
  }
};

int main() {
  vector<vector<int>> trust;

  trust = {};
  printf("%d\n", Solution::findJudge(1, trust));

  trust = {{1, 2}};
  printf("%d\n", Solution::findJudge(2, trust));

  trust = {{1, 3}, {2, 3}};
  printf("%d\n", Solution::findJudge(3, trust));

  trust = {{1, 3}, {2, 3}, {3, 1}};
  printf("%d\n", Solution::findJudge(3, trust));

  trust = {{1, 2}, {2, 3}};
  printf("%d\n", Solution::findJudge(3, trust));

  trust = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
  printf("%d", Solution::findJudge(4, trust));
}
