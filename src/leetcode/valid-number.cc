class Solution {
 public:
  // 1. First char is either sign or digit or dot.
  // 2. After sign, either digits then dot,
  //    or digits then dot & then more digits,
  //    or dot then digits
  //    or only digits.
  // 3. Maybe an e or E.
  // 4. After e or E, maybe a sign.
  // 5. After sign, only one or more digits.
  bool isNumber(string s) {
    // First char is either sign or digit or dot.
    bool seenSign = false;
    bool seenDot = false;
    bool seenDigit = false;
    if (s[0] != '+' && s[0] != '-' && !isdigit(s[0]) && s[0] != '.')
      return false;
    if (s[0] == '+' || s[0] == '-') seenSign = true;
    if (s[0] == '.') seenDot = true;
    if (isdigit(s[0])) seenDigit = true;
    int i = 1;
    while (i < s.length() && s[i] != 'e' && s[i] != 'E') {
      if (seenSign) {
        if (s[i] == '+' || s[i] == '-') return false;
      }
      if (seenDot) {
        if (s[i] == '.') return false;
      }
      if (!seenDot && s[i] == '.') {
        seenDot = true;
        ++i;
        continue;
      }
      if (!isdigit(s[i]))
        return false;
      else
        seenDigit = true;
      ++i;
    }
    if (seenDot && !seenDigit) return false;
    if (i == s.length()) return true;
    // s[i] == 'e' or 'E'
    if (!seenDigit) return false;
    seenDigit = false;
    ++i;
    if (s[i] != '+' && s[i] != '-' && !isdigit(s[i])) return false;
    if (isdigit(s[i])) seenDigit = true;
    ++i;
    while (i < s.length()) {
      if (!isdigit(s[i])) return false;
      seenDigit = true;
      ++i;
    }
    if (!seenDigit) return false;
    return true;
  }
};
