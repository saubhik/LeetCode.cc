class Solution {
 public:
  // lee(t(c)o)de) -> lee(t(c)o)de
  // a)b(c)d -> ab(c)d
  //
  // If starts with ')' remove it.
  // ))((
  // Track number of '('.
  string minRemoveToMakeValid(string s) {
    int leftBracs = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(') {
        ++leftBracs;
      } else if (s[i] == ')') {
        if (leftBracs > 0) {
          --leftBracs;
        } else {
          s[i] = '!';  // delete this
        }
      }
    }

    // "))(("
    if (leftBracs > 0) {
      for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == '(') {
          s[i] = '!';  // delete this
          if (--leftBracs == 0) {
            break;
          }
        }
      }
    }

    s.erase(std::remove(s.begin(), s.end(), '!'), s.end());
    return s;
  }
};
