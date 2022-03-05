class Solution {
 public:
  // length=1 should solve the problem.
  // If not, solution is impossible.
  // length=max-ribbon-length might not solve the problem.
  // If it solved, that's the answer.
  // Otherwise, there is a length from which solution is impossible.
  // Find the length just before that.
  // Binary search on speculated ribbon length!
  // Time: O(NlogL) where N is ribbons.size() and L is the max length.
  int maxLength(vector<int>& ribbons, int k) {
    int lo = 1;
    int hi = *max_element(ribbons.begin(), ribbons.end());

    if (!possible(ribbons, k, lo)) return 0;
    if (possible(ribbons, k, hi)) return hi;

    // invariant:
    // lo should solve the problem.
    // hi should not solve the problem.
    while ((hi - lo) > 1) {
      int mid = lo + (hi - lo) / 2;
      if (possible(ribbons, k, mid))
        lo = mid;
      else
        hi = mid;
    }

    return lo;
  }

 private:
  bool possible(const vector<int>& ribbons, const int k, int length) {
    int n = ribbons.size();
    int num = 0;
    for (int i = 0; i < n; ++i) {
      if (ribbons[i] >= length) {
        num += ribbons[i] / length;
        if (num >= k) return true;
      }
    }
    return false;
  }
};
