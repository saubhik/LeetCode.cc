class Solution {
public:
    const int MOD = 1e9+7;
    // dp[i][j][k] = Number of paths from (sx, sy) to (i, j) in k moves.
    // Once i,j is a boundary, accumulate the path count for each outgoing direction.
    // O(mnK) time, O(mn) space.
    int findPaths(int m, int n, int K, int sx, int sy) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> tmp(m, vector<int>(n, 0));
        dp[sx][sy] = 1;
        int ans = 0;
        for (int k=0; k<K; ++k) {
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    if (i == 0  ) ans += dp[i][j], ans %= MOD;
                    if (i == m-1) ans += dp[i][j], ans %= MOD;
                    if (j == 0  ) ans += dp[i][j], ans %= MOD;
                    if (j == n-1) ans += dp[i][j], ans %= MOD;
                    tmp[i][j] = 0;
                    tmp[i][j] += (i>=1)  ? dp[i-1][j] : 0, tmp[i][j] %= MOD;
                    tmp[i][j] += (j>=1)  ? dp[i][j-1] : 0, tmp[i][j] %= MOD;
                    tmp[i][j] += (i+1<m) ? dp[i+1][j] : 0, tmp[i][j] %= MOD;
                    tmp[i][j] += (j+1<n) ? dp[i][j+1] : 0, tmp[i][j] %= MOD;

                }
            }
            swap(dp, tmp);
        }
        return ans;
    }
};