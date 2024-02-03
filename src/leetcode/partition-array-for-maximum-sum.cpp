class Solution {
public:
    // Suppose a = [6,7,4] and k = 3.
    //         i =  0,1,2
    // Formulating the DP is everything. 
    // Work from the examples. The gross gives birth to the fine.
    // dp[2] = max{
    //   max{4} * 1 + dp[1],
    //   max{7,4} * 2 + dp[0],
    //   max{6,7,4} * 3 + 0,
    // };
    // dp[1] = max{
    //   max{7} * 1 + dp[0],
    //   max{6,7} * 2 + 0,
    // };
    // & so on.
    // Time: O(nk), Space: O(n) (could be made O(k)).
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        auto n = a.size();
        vector<int> dp(n, -1);
        for (int i=0; i<n; ++i) {
            auto tmp = -1; // max in the subarray ending at i.
            for (int j=i; j>i-k && j>=0; --j) {
                tmp = max(tmp, a[j]);
                dp[i] = max(
                    dp[i], 
                    tmp * (i-j+1) + ((j>=1) ? dp[j-1] : 0)
                );
            }
        }
        return dp[n-1];
    }
};