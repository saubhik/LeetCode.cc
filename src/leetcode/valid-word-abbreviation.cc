class Solution {
 public:
  // a2e
  // check length of substring in between a & e and
  // all occurrences of e.
  // i12iz4n
  // Check length of substring in between i & i.
  bool validWordAbbreviation(string word, string abbr) {
    int m = abbr.length();
    int n = word.length();
    int j = 0;
    for (int i = 0; i < m; ++i) {
      if (isalpha(abbr[i])) {
        if (abbr[i] != word[j]) return false;
        ++j;
      } else {
        // Extract number from the abbr: i12i
        // assert(isdigit(abbr[i]));
        if (abbr[i] == '0') return false;  // no leading zeros allowed
        int k = i;
        while (k < m && isdigit(abbr[k])) ++k;
        int num = stoi(abbr.substr(i, k - i));
        i = k;  // we already check for k in this iter

        // Check num is length of substring from j
        // to *some* occurrence of abbr[k]
        if (k < m) {
          char ch = abbr[k];
          int p = j;
          for (; p < n; ++p) {
            if (word[p] == ch && num == p - j) {
              break;
            }
          }
          if (p == n) return false;  // did not find ch
          j = p + 1;
        } else {
          // abbr ends with a number
          // This must equal the length of the remaining
          // string word: (n-j)
          return num == n - j;
        }
      }
    }
    return j == n;
  }
};
