class Solution {
public:
    // O(mn) time, O(min(m, n)) space.
    // We just need two n-element rows at a time, not the entire mxn table.
    // Base case: LCS is 0 when no chars present in either s or t.
    // dp[i][j] = dp[i-1][j-1] + 1             if s[i] == t[j]
    //          = max(dp[i-1][j], dp[i][j-1])  otherwise
    int longestCommonSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (n > m) return longestCommonSubsequence(t, s);
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (s[i] == t[j]) dp2[j] = j == 0 ? 1 : dp1[j-1] + 1;
                else dp2[j] = j == 0 ? dp1[j] : max(dp1[j],dp2[j-1]);
            }
            swap(dp1, dp2);
        }
        return dp1[n-1];
    }
};