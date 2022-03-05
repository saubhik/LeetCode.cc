class Solution {
 public:
  // [23,2,6,4,7], k=6
  // Need to check all possible subarray sums.
  // Quadratic time: O(n^2), Constant space: O(1).
  // This is too slow.
  // Continuous subarrays mean prefix sums might be useful.
  // 23,2,6,4,7,11 & k=11
  // 23,25,31,35,42,53 <- prefix sums
  // 1,3,9,2,9,9 (modulo 11)
  // There must be a repeating digit in prefix sum modulo 11.
  // Important: The repeating digit must not be the last one.
  bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int ps = 0;
    // Only store the first index for a ps.
    unordered_map<int, int> pss;
    for (int i = 0; i < n; ++i) {
      ps = (ps + nums[i]) % k;
      // Sum from the start is a multiple of k.
      if (ps == 0 && i > 0) return true;
      // If ps doesn't exist before, insert it.
      if (pss.find(ps) == pss.end()) pss[ps] = i;
      // Otherwise return true, only if the index diff is > 1.
      else if (i - pss[ps] > 1)
        return true;
    }
    return false;
  }
};
