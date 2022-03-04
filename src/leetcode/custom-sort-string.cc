class Solution {
 public:
  // "cbafg", "abcd"
  // Does 'c' appear in s? Yes. Swap it's position with first: "cbad".
  // Does 'b' appear in s? Yes. Swap it's position with second: "cbad".
  // Does 'a' appear in s? Yes. Swap it's position with third: "cbad".
  // Does 'f' appear in s? No.
  // Does 'g' appear in s? No.
  // This is correct since chars in `order` are unique.
  // ----------------------------------------------------
  // >> BUG: There might be multiple occurrences in s. <<
  // ----------------------------------------------------
  string customSortStringAliter(string order, string s) {
    int pos = 0;
    int n = s.length();
    for (char ch : order) {  // O(26) times.
      // Find position of ch in s and swap.
      // "cba", "abccc"
      // "c" : "cbacc" -> "ccabc" -> "cccab"
      // "b" : "cccba"
      // "a" : "cccba"
      for (int i = 0; i < n; ++i) {
        if (s[i] == ch) {
          swap(s[i], s[pos]);
          ++pos;
        }
      }
    }
    return s;
  }

  string customSortString(string order, string s) {
    unordered_map<char, int> counts;
    for (char ch : s) counts[ch]++;
    string ans = "";
    for (char ch : order) {
      for (int i = 0; i < counts[ch]; ++i) ans += ch;
      counts[ch] = 0;
    }
    for (char ch : s)
      if (counts[ch]) ans += ch;
    return ans;
  }
};
