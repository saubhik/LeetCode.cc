//
// Created by saubhik on 2019/11/13.
//
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  // Two pass algorithm
  // 97.34% run-time, 100% memory
  static vector<int> shortestToChar(const string &S, char C) {
    int n = S.length();
    vector<int> ans(n);
    int count = 10000;

    for (int i = 0; i < n; ++i)
      if (S[i] == C)
        count = 0;
      else
        ans[i] = ++count;

    for (int i = n - 1; i > -1; --i)
      if (S[i] == C)
        count = 0;
      else
        ans[i] = min(ans[i], ++count);

    return ans;
  }
};

int main() {
  vector<int> out;
  out = Solution::shortestToChar("loveleetcode", 'e');
  for (auto num : out)
    printf("%d ", num);
}
