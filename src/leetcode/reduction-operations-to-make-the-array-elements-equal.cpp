/*
Given an integer array nums, your goal is to make all elements in nums equal.
To complete one operation, follow these steps:

- Find the largest value in nums.
  Let its index be i (0-indexed) and its value be largest.
  If there are multiple elements with the largest value, pick the smallest i.
- Find the next largest value in nums strictly smaller than largest.
  Let its value be nextLargest.
- Reduce nums[i] to nextLargest.

Return the number of operations to make all elements in nums equal.
*/

class Solution {
public:
    int arr[50001];
    int reductionOperations(vector<int>& nums) {
        memset(arr, 0, sizeof(arr));
        int mini = INT_MAX, maxi = INT_MIN;
        for (int &n: nums) {
            ++arr[n];
            mini = min(n, mini);
            maxi = max(n, maxi);
        }
        int res = 0, cnt = arr[mini];
        for (int i = mini + 1; i <= maxi; i++) {
            if (arr[i] > 0) {
                res += nums.size() - cnt;
            }
            cnt += arr[i];
        }
        return res;
    }
};
