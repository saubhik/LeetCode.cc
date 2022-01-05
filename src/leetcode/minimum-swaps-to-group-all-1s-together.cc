/*
 * Sliding Window of size number of ones in the array.
 * Count the number of zeros in each window.
 */

class Solution {
 public:
  int minSwaps(vector<int>& data) {
    int n = data.size();
    int ones{accumulate(data.begin(), data.end(), 0)};

    int zeros{0};
    int ans{0};

    for (int i = 0; i < ones; ++i) {
      zeros += 1 - data[i];
    }

    ans = zeros;

    for (int right = ones; right < n; ++right) {
      zeros += data[right - ones] - data[right];
      ans = min(ans, zeros);
    }

    return ans;
  }
};
