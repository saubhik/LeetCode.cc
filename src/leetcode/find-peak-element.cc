class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    if (nums.size() == 1) return 0;

    int n = nums.size();

    // check invariants
    // Covers n=2 case.
    if (nums[0] > nums[1]) return 0;
    if (nums[n - 1] > nums[n - 2]) return n - 1;

    // For n>2 case:
    int lo = 0;
    int hi = n - 1;

    // maintain invariants
    // lo is always in increasing slope
    // hi is always in decreasing slope
    while ((hi - lo) > 1) {
      int mid = lo + (hi - lo) / 2;
      if (nums[mid - 1] < nums[mid]) {
        if (nums[mid] > nums[mid + 1]) return mid;
        lo = mid;
      } else {
        hi = mid;
      }
    }

    // shouldn't reach here
    return -1;
  }
};
