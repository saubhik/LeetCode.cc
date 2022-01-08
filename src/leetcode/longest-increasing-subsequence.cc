/*
 * Classical DP problem.
 * Consider dp[i] = LIS ending with nums[i].
 * dp[i] = 1 + max(dp[j]) for 0 <= j < i, and nums[j] < nums[i].
 */
class Solution {
 public:
  // int lengthOfLIS(vector<int>& nums) {
  //     int n = nums.size();
  //     int dp[n];
  //     int ans = INT_MIN;
  //     fill(dp, dp+n, 1);
  //     for (int i = 0; i < n; ++i) {
  //         for (int j = 0; j < i; ++j) {
  //             if (nums[j] < nums[i]) {
  //                 dp[i] = max(dp[i], 1 + dp[j]);
  //             }
  //         }
  //         ans = max(ans, dp[i]);
  //     }
  //     return ans;
  // }
  int lengthOfLIS(vector<int>& nums) {
    // O(nlogn) time, O(n) space.
    vector<int> seq;
    for (int n : nums) {
      if (seq.empty() || seq.back() < n) {
        seq.push_back(n);
      } else {
        int idx = findMinMax(seq, n);
        seq[idx] = n;
      }
    }
    return seq.size();
  }

 private:
  int findMinMax(vector<int>& seq, int n) {
    int left = 0;
    int right = seq.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (seq[mid] == n) {
        return mid;
      } else if (seq[mid] > n) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
