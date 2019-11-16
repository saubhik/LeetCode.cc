//
// Created by saubhik on 2019/11/16.
//
#include <string>
#include <vector>
using namespace std;

class Solution0 {
public:
  // useless dp. Does not work with super long t.
  short dp[10][50];
  bool isSubsequence(string s, string t) {
    memset(dp, -1, sizeof(dp));
    return go((int)s.length() - 1, (int)t.length() - 1, s, t);
  }
  bool go(int i, int j, string &s, string &t) {

    if (j < i)
      return false;

    if (j == i)
      return s.substr(0, i + 1) == t.substr(0, j + 1);

    if (dp[i][j] != -1)
      return dp[i][j];

    if (s[i] == t[j])
      return dp[i - 1][j - 1] = go(i - 1, j - 1, s, t);
    else
      return dp[i][j - 1] = go(i, j - 1, s, t);
  }
};

class Solution {
public:
  // 95.60% run-time, 85.71% memory
  // O(n) time
  // bad if n is super large and billions of s's are coming.
  static bool isSubsequence(string s, string t) {
    int m = s.length(), n = t.length();
    int j = 0;
    for (int i = 0; i < n && j < m; ++i) {
      if (s[j] == t[i])
        ++j;
    }
    return j == m;
  }
};

class Solution2 {
public:
  // O(|s|log(|t|/26)) time. Helps when |t| >> |s|.
  // for follow up question
  // 19.06% run time, 14.29% memory
  static bool isSubsequence(const string &s, const string &t) {
    vector<vector<int>> store(26);
    for (int i = 0; i < (int)t.size(); ++i)
      store[t[i] - 'a'].push_back(i);
    int index = -1;
    for (char i : s) {
      auto iter =
          upper_bound(store[i - 'a'].begin(), store[i - 'a'].end(), index);
      if (iter == store[i - 'a'].end())
        return false;
      index = *iter;
    }
    return true;
  }
};

int main() {
  printf("%d\n", Solution::isSubsequence("abc", "ahbgdc"));
  printf("%d\n", Solution2::isSubsequence("abc", "ahbgdc"));
  printf("%d\n", Solution::isSubsequence("axc", "ahbgdc"));
  printf("%d\n", Solution2::isSubsequence("axc", "ahbgdc"));
}