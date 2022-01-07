// Try to replace first non-'a' character with 'a'.
// This is greedy.
class Solution {
 public:
  string breakPalindrome(string palindrome) {
    int n = palindrome.length();

    if (n == 1) {
      return "";
    }

    for (int i = 0; i < n / 2; ++i) {
      if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        return palindrome;
      }
    }

    // All a's in the first half.
    palindrome[n - 1] = 'b';
    return palindrome;
  }
};
