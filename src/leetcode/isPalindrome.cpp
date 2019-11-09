#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // converting integer to string
  static bool isPalindrome_INVALID_1(int x) {
    string s1 = to_string(x), s2 = s1;
    reverse(begin(s1), end(s1));
    return s1 == s2;
  }

  // without converting to string
  // super slow: 18.76%, 15.45%
  // O(|digits|) extra space
  static bool isPalindrome_SLOW_1(int x) {
    if (x < 0)
      return false;

    if (x == 0)
      return true;

    int y = x;
    vector<int> digits;
    while (y) {
      digits.push_back(y % 10);
      y /= 10;
    }
    for (size_t i = 0, j = digits.size() - 1; i < j; ++i, --j)
      if (digits[i] != digits[j])
        return false;
    return true;
  }

  // try the above solution without extra space
  // 100% time, 100% mem
  // time complexity: O(log_10(n))
  static bool isPalindrome(int x) {
    if (x < 0)
      return false;
    unsigned reverse = 0, y = x;
    while (y) {
      reverse = reverse * 10 + (y % 10);
      y /= 10;
    }
    return reverse == x;
  }
};

int main() {
  printf("%d\n", Solution::isPalindrome(121));
  printf("%d\n", Solution::isPalindrome(-121));
  printf("%d\n", Solution::isPalindrome(0));
  printf("%d", Solution::isPalindrome(10));
}
