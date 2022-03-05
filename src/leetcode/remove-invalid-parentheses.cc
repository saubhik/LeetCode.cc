class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    int leftRem = 0;
    int rightRem = 0;
    minRemovalsReqd(s, leftRem, rightRem);
    backtrack(s, leftRem, rightRem, ans);
    return ans;
  }

 private:
  unordered_map<string, bool> visited;
  void backtrack(string& s, int leftRem, int rightRem, vector<string>& ans) {
    if (leftRem == 0 && rightRem == 0) {
      minRemovalsReqd(s, leftRem, rightRem);
      if (leftRem == 0 && rightRem == 0) ans.push_back(s);
      return;
    }

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(' && leftRem > 0) {
        string ns = s.substr(0, i) + s.substr(i + 1);
        // I might visit this string, ns, with different combination
        // of leftRem and rightRem. What then?
        // "))()", left=0, right=2
        // "))()", left=1, right=0
        // I got this substring after removing equal number of left & right
        // braces, so it doesn't matter. So the above case never happens.
        if (!visited[ns]) {
          visited[ns] = true;
          backtrack(ns, leftRem - 1, rightRem, ans);
        }
      }
      if (s[i] == ')' && rightRem > 0) {
        string ns = s.substr(0, i) + s.substr(i + 1);
        if (!visited[ns]) {
          visited[ns] = true;
          backtrack(ns, leftRem, rightRem - 1, ans);
        }
      }
    }
  }

  // Example:
  // ))(((
  // 2+3=5
  //
  // Two cases:
  // 1. Extra right braces at any point.
  // 2. Extra left braces at the end.
  void minRemovalsReqd(string& s, int& leftRem, int& rightRem) {
    int left = 0;
    int right = 0;

    for (char ch : s) {
      if (ch == '(')
        ++left;
      else if (ch == ')') {
        --left;
        if (left < 0) {
          // Need to remove a right brace
          right++;
          left = 0;
        }
      }
    }

    // left  > 0 means unmatching left braces remaining.
    // right > 0 means unmatching right braces remaining.
    leftRem = left;
    rightRem = right;
  }
};
