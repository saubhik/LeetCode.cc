class Solution {
 public:
  // [8,3,2,4,5]
  // Sum = 22
  // Replicate each index w[i] times.
  // Generate random number in [0, 22).
  // Call the random number target.
  // Check where the target falls.
  // 8, 11, 13, 17, 22
  // First 8 units belong to index 0.
  // Next  3 units belong to index 1.
  // Next  2 units belong to index 2.
  // Next  4 units belong to index 3.
  // Next  5 units belong to index 4.
  // Binary search position in the list of prefix sums.
  Solution(vector<int>& w) {
    int tmp = 0;
    for (int wt : w) {
      tmp += wt;
      prefixSums.push_back(tmp);
    }
  }

  int pickIndex() {
    float target = ((float)rand() / RAND_MAX) * prefixSums.back();

    // Check where target falls in prefixSums
    int lo = 0;
    int hi = prefixSums.size() - 1;

    if (prefixSums[lo] > target) return lo;
    if (prefixSums[hi] <= target) return hi;  // target cannot be greater

    // invariant:
    // prefixSums[lo] <= target
    //         target <  prefixSums[hi]
    while ((hi - lo) > 1) {
      int mid = lo + (hi - lo) / 2;
      if (prefixSums[mid] == target)
        return mid;
      else if (prefixSums[mid] < target)
        lo = mid;
      else
        hi = mid;
    }

    return hi;
  }

 private:
  vector<int> prefixSums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
