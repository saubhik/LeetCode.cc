/*
 * Range Caching:
 * Lot of updates, but single read at end.
 * Modify the values in the ranges.
 * Return the prefix sum in the end.
 * Similar: Corporate Flight Bookings.
 */

class Solution {
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> res(length, 0);

    for (const vector<int>& update : updates) {
      res[update[0]] += update[2];
      if (update[1] + 1 < length) {
        res[update[1] + 1] -= update[2];
      }
    }

    for (int i = 1; i < length; ++i) {
      res[i] += res[i - 1];
    }

    return res;
  }
};
