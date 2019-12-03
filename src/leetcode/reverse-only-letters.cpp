//
// Created by saubhik on 2019/12/03.
//
#include <string>
using namespace std;

class Solution {
public:
  // 100% run-time, 90.91% memory
  // O(n) time, O(1) space.
  static string reverseOnlyLetters(string S) {
    for (int i = 0, j = S.length() - 1; i < j;) {
      if (('a' <= S[i] && S[i] <= 'z') || ('A' <= S[i] && S[i] <= 'Z')) {
        if (('a' <= S[j] && S[j] <= 'z') || ('A' <= S[j] && S[j] <= 'Z')) {
          swap(S[i++], S[j--]);
        } else {
          --j; // S[j] is not alphabet
        }
      } else {
        ++i; // S[i] is not alphabet
      }
    }
    return S;
  }
};

class Solution2 {
public:
  // using library function
  static string reverseOnlyLetters(string S) {
    for (int i = 0, j = S.length() - 1; i < j;) {
      if (!isalpha(S[i]))
        ++i;
      else if (!isalpha(S[j]))
        --j;
      else
        swap(S[i++], S[j--]);
    }
    return S;
  }
};

int main() {
  printf("%s\n", Solution::reverseOnlyLetters("ab-cd").c_str());
  printf("%s\n", Solution2::reverseOnlyLetters("ab-cd").c_str());
  printf("%s\n", Solution::reverseOnlyLetters("a-bC-dEf-ghIj").c_str());
  printf("%s\n", Solution2::reverseOnlyLetters("a-bC-dEf-ghIj").c_str());
  printf("%s\n", Solution::reverseOnlyLetters("Test1ng-Leet=code-Q!").c_str());
  printf("%s", Solution2::reverseOnlyLetters("Test1ng-Leet=code-Q!").c_str());
}
