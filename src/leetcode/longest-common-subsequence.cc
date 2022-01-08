/*
 * Classical DP problem.
 * Consider: abcde, ace
 *
 *         "a" "ac" "ace"
 * "a"      1   1    1
 * "ab"     1   1    1
 * "abc"    1   2    2
 * "abcd"   1   2    2
 * "abcde"  1   2    3
 */
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

    if (m < n) {
      return longestCommonSubsequence(text2, text1);
    }

    int dp[2][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (text1[i] == text2[j]) {
          dp[1][j] = 1 + (j >= 1 ? dp[0][j - 1] : 0);
        } else {
          dp[1][j] = max(dp[0][j], j >= 1 ? dp[1][j - 1] : 0);
        }
      }

      for (int j = 0; j < n; ++j) {
        dp[0][j] = dp[1][j];
      }
    }

    return dp[1][n - 1];
  }
};
