class Solution {
 public:
  // Find the left most digit with a smaller digit.
  // (There exists a larger digit in the number.)
  // Swap with the largest digit.
  int maximumSwap(int num) {
    int digits[8];
    int maxSoFarIdxs[8];

    int sz = 0;
    int maxSoFarIdx = 0;
    while (num) {
      digits[sz] = num % 10;
      num /= 10;
      if (digits[maxSoFarIdx] < digits[sz]) maxSoFarIdx = sz;
      maxSoFarIdxs[sz] = maxSoFarIdx;
      ++sz;
    }

    // Compare with the maxRt at each index.
    for (int i = sz - 1; i > 0; --i) {
      if (digits[i] < digits[maxSoFarIdxs[i - 1]]) {
        swap(digits[i], digits[maxSoFarIdxs[i - 1]]);
        break;
      }
    }

    int ans = 0;
    int pow = 1;
    for (int i = 0; i < sz; ++i) {
      ans += digits[i] * pow;
      pow *= 10;
    }

    return ans;
  }
};
