class Solution {
public:
    const int MOD = 1e9+7;
    // Find sum(min(s)) over all subarrays s.
    // Monotonic stack: O(n) time, O(n) space.
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s;
        int n = arr.size();
        int ans = 0;
        for (int i=0; i<=n; ++i) {
            while (!s.empty() && (i == n || arr[s.top()] > arr[i])) {
                auto mid = s.top(); s.pop();
                // i is the index of the next smaller element after top.
                // s.top() is the index of the prev smaller element before top.
                // (left_border, right_border) is the widest range with smallest element arr[mid].
                // Number of subarrays containing mid in this range = (mid - left_border) * (right_border - mid).
                // Consider contribution of each element right after popping it from monotonic stack.
                auto right_border = i;
                auto left_border = s.empty() ? -1 : s.top();
                auto count = (mid - left_border) * (right_border - mid);
                ans += ((long) count * arr[mid]) % MOD;
                ans %= MOD;
            } 
            s.push(i);
        }
        return ans;
    }
};
