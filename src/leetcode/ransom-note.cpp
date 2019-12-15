//
// Created by saubhik on 2019/12/15.
//
#include <string>
using namespace std;

class Solution {
public:
  // 90.10% run-time (20ms), 100% memory (11MB).
  // O(|ransomNote|) time, O(|magazine|) space.
  static bool canConstruct(string ransomNote, string magazine) {
    int mp[26] = {};
    for (char ch : magazine)
      ++mp[ch - 'a'];

    for (char ch : ransomNote)
      if (--mp[ch - 'a'] < 0)
        return false;

    return true;
  }
};

int main() {
  printf("%d\n", Solution::canConstruct("a", "b"));
  printf("%d\n", Solution::canConstruct("aa", "ab"));
  printf("%d\n", Solution::canConstruct("aa", "aab"));
}
