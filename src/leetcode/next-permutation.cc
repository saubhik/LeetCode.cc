class Solution {
 private:
  int getMinElementGreaterThan(vector<int>& nums, int start, int num) {
    int n = nums.size();

    // invariants
    // lo is > num: true for start
    // hi is <= num
    int lo = start;
    int hi = n - 1;

    // we know nums[lo] > num
    if (nums[hi] > num) return hi;

    // invariants satisfied
    while ((hi - lo) > 1) {
      int mid = lo + (hi - lo) / 2;
      if (nums[mid] > num) {
        lo = mid;
      } else {
        hi = mid;
      }
    }

    // lo,hi with:
    // nums[lo] > num &
    // nums[hi] <= num
    return lo;
  }

 public:
  // [1,3,2]
  //  ^....
  void nextPermutation(vector<int>& nums) {
    int n = nums.size(), i;
    // Get the first decreasing number.
    for (i = n - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        // Get the minimum element greater than nums[i].
        int j = getMinElementGreaterThan(nums, i + 1, nums[i]);
        swap(nums[j], nums[i]);
        break;
      }
    }

    reverse(nums.begin() + i + 1, nums.end());
  }
};
