//
// Created by saubhik on 2020/02/11.
//
#include <cmath>
#include <cstdio>
using namespace std;

class Solution {
public:
  // O(log_{3}{n}) time, O(1) space.
  static bool isPowerOfThree(int n) {
    if (n < 1)
      return false;
    while (n % 3 == 0)
      n /= 3;
    return n == 1;
  }
};

class Solution2 {
private:
  static bool is_integer(double k) { return floor(k) == k; }

public:
  // O(?) time, O(1) space.
  static bool isPowerOfThree(int n) { return is_integer(log(n) / log(3)); }
};

class Solution3 {
public:
  // O(1) time, O(1) space.
  static bool isPowerOfThree(int n) {
    /* An important piece of information can be deduced from the function
     * signature. Since it is int, with maximum value INT_MAX, we can know the
     * the maximum value of n that is a power of 3. It is log_{3}{INT_MAX}. Any
     * n which is a power of 3, will be a factor of 3^19 = 1162261467.
     */
    return n > 0 && 1162261467 % n == 0;
  }
};

int main() {
  printf("%d ", Solution::isPowerOfThree(9));
  printf("%d ", Solution2::isPowerOfThree(9));
  printf("%d ", Solution3::isPowerOfThree(9));
  printf("%d ", Solution::isPowerOfThree(45));
  printf("%d ", Solution2::isPowerOfThree(45));
  printf("%d ", Solution3::isPowerOfThree(45));
}