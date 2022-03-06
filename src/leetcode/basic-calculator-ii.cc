class Solution {
 public:
  // Using a stack.
  // O(n) time and O(n) space.
  int calculateAliter(string& s) {
    stack<int> st;
    int n = s.length();
    int num = 0;
    char currOp = '+';
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) num = num * 10 + (s[i] - '0');
      if (!isdigit(s[i]) && !iswspace(s[i]) || i == n - 1) {
        int top;
        switch (currOp) {
          case '+':
            st.push(num);
            break;
          case '-':
            st.push(-num);
            break;
          case '*':
            top = st.top();
            st.pop();
            st.push(top * num);
            break;
          case '/':
            top = st.top();
            st.pop();
            st.push(top / num);
            break;
        }
        num = 0;
        currOp = s[i];
      }
    }
    // No more numbers in string.
    // Add all remaining numbers in stack.
    int ans = 0;
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }

    return ans;
  }

  // O(n) time, O(1) space.
  // Without using a stack.
  // Use three states:
  // 1. result
  // 2. lastNum
  // 3. currNum
  // and currOp (for operator).
  int calculate(string& s) {
    stack<int> st;
    int n = s.length();
    char currOp = '+';
    int currNum = 0;
    int lastNum = 0;
    int result = 0;
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) currNum = 10 * currNum + (s[i] - '0');
      if (!isdigit(s[i]) && !iswspace(s[i]) || i == n - 1) {
        switch (currOp) {
          case '+':
            result += lastNum;
            lastNum = currNum;
            break;
          case '-':
            result += lastNum;
            lastNum = -currNum;
            break;
          case '*':
            lastNum *= currNum;
            break;
          case '/':
            lastNum /= currNum;
            break;
        }
        currNum = 0;
        currOp = s[i];
      }
    }
    result += lastNum;
    return result;
  }
};
