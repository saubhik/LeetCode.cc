//
// Created by saubhik on 2019/12/16.
//
#include <string>
using namespace std;

class Solution {
public:
  // 92.24% run-time (36ms), 100% memory (12.6MB).
  // O(n) time, O(1) space.
  static int firstUniqChar(string s) {
    int count[26] = {};
    for (int i = 0; i < s.length(); ++i)
      ++count[s[i] - 'a'];
    for (int i = 0; i < s.length(); ++i)
      if (count[s[i] - 'a'] == 1)
        return i;
    return -1;
  }
};

int main() {
  printf("%d\n", Solution::firstUniqChar("leetcode"));
  printf("%d\n", Solution::firstUniqChar(""));
  printf("%d\n", Solution::firstUniqChar("cc"));
  printf("%d", Solution::firstUniqChar("loveleetcode"));
}
