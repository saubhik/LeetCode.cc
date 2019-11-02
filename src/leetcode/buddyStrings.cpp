//
// Created by saubhik on 2019/11/02.
//
#include <iostream>
using namespace std;

class Solution {
public:
  static bool buddyStrings(string A, string B) {
    if (A.size() != B.size() || A.size() < 2)
      return false;

    bool swapped = false;
    int prev = -1;
    int count[26] = {0};

    for (int i = 0; i < (int)A.size(); ++i) {
      if (A[i] != B[i]) {
        if (swapped)
          return false;
        if (prev == -1)
          prev = i;
        else if (A[i] == B[prev] && A[prev] == B[i])
          swapped = true;
        else
          return false;
      } else {
        count[A[i] - 'a']++;
      }
    }

    if (swapped)
      return true;

    for (int cnt : count)
      if (cnt > 1)
        return true;

    return false;
  }
};

int main() {
  printf("%d\n", Solution::buddyStrings("ab", "ba"));
  printf("%d\n", Solution::buddyStrings("ab", "ab"));
  printf("%d\n", Solution::buddyStrings("aa", "aa"));
  printf("%d\n", Solution::buddyStrings("aaaaaaabc", "aaaaaaabc"));
  printf("%d\n", Solution::buddyStrings("abab", "abab"));
  printf("%d\n", Solution::buddyStrings("abab", "axax"));
}
