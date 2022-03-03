class Solution {
 public:
  // O(logn) time.
  double myPow(double x, int n) {
    if (x == 1 || x == 0) return x;
    if (x == -1) return (n % 2 == 0) ? 1 : -1;
    if (n == 0) return 1;
    if (n == INT_MIN) return 0;

    int posn = n > 0 ? n : -n;
    double prod = x;
    double ans = 1;
    while (posn > 0) {
      int i = 1;
      while (i < INT_MAX / 2 && i * 2 <= posn) {
        prod = prod * prod;
        i *= 2;
      }
      ans *= prod;
      prod = x;
      posn -= i;
    }

    return n > 0 ? ans : 1 / ans;
  }
};
