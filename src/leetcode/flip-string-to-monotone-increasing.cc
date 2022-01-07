class Solution {
 public:
  /*
  int minFlipsMonoIncr(string s) {
    int n = s.length();
    int leftFlips[n + 1];
    int rightFlips[n + 1];

    leftFlips[0] = 0;
    for (int i = 1; i <= n; ++i) {
      leftFlips[i] = leftFlips[i-1] + (s[i-1] - '0');
    }

    rightFlips[n] = 0;
    int ans = leftFlips[n];
    for (int i = n - 1; i >= 0; --i) {
      rightFlips[i] = rightFlips[i + 1] + ('1' - s[i]);
      ans = min(ans, rightFlips[i] + leftFlips[i]);
    }

    return ans;
  }
  */

  int minFlipsMonoIncr(string s) {
    int ones = 0;
    int ans = 0;
    for (char ch : s) {
      if (ch == '1')
        ones++;
      else
        ans = min(ans + 1, ones);
    }
    return ans;
  }
};
