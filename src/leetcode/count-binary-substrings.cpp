//
// Created by saubhik on 2019/12/08.
//
/*
 * Do not know how this is an easy question. I spent quite a bit of time on it.
 */
#include <string>
using namespace std;

class Solution {
public:
  // 68.89% run-time, 100% memory.
  // O(n) time, O(1) space.
  static int countBinarySubstrings(string s) {
    int ans = 0, n = s.length();

    for (int i = 0; i < n;) {
      int count0s = 0, count1s = 0, j = i;
      bool streak0 = s[i] == '0', changed = false;

      do {

        if (streak0 && s[j] == '0')
          ++j, ++count0s;
        else if (!streak0 && s[j] == '1')
          ++j, ++count1s;
        else {
          if (changed)
            break;
          else
            streak0 = !streak0, changed = true, i = j;
        }

      } while (j < n && count0s != count1s);

      if (!changed)
        break;

      ans += min(count0s, count1s);
    }

    return ans;
  }
};

class Solution2 {
public:
  // 95.50% run-time, 100% memory
  // much much cleaner
  // prev -> stores count of 0s or 1s, whichever occurred previously
  // cur -> stores count of 0s or 1s, whichever occurs now
  // What can I learn from this?
  // Maybe if I thought about one layer of abstraction above 0s and 1s, I could
  // have come up with this.
  static int countBinarySubstrings(string s) {
    int ans = 0, prev = 0, cur = 1, n = s.length();
    for (int i = 1; i < n; ++i) {
      if (s[i - 1] != s[i]) {
        ans += min(prev, cur);
        prev = cur;
        cur = 1;
      } else {
        ++cur;
      }
    }
    return ans + min(prev, cur);
  }
};

int main() {
  printf("%d %d\n", Solution::countBinarySubstrings("00110011"),
         Solution2::countBinarySubstrings("00110011"));
  printf("%d %d\n", Solution::countBinarySubstrings("10101"),
         Solution2::countBinarySubstrings("10101"));
  printf("%d %d\n", Solution::countBinarySubstrings("00110"),
         Solution2::countBinarySubstrings("00110"));
}
