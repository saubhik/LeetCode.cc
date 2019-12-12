//
// Created by saubhik on 2019/12/12.
//
#include <string>
using namespace std;

class Solution {
public:
  // 100% run-time, 75% memory.
  // O(n) time, O(1) space.
  static bool detectCapitalUse(string word) {
    for (int i = 1; i < word.length(); ++i)
      if ((isupper(word[i]) && islower(word[i - 1])) ||
          (islower(word[i]) && isupper(word[i - 1]) && i > 1))
        return false;
    return true;
  }
};

int main() {
  printf("%d\n", Solution::detectCapitalUse("USA"));
  printf("%d\n", Solution::detectCapitalUse("leetcode"));
  printf("%d\n", Solution::detectCapitalUse("Google"));
  printf("%d\n", Solution::detectCapitalUse("GOOGLe"));
  printf("%d", Solution::detectCapitalUse("FlaG"));
}
