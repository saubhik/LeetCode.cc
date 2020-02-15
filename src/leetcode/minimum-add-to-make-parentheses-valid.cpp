//
// Created by saubhik on 2020/02/14.
//
#include <stack>
#include <string>

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum
  // Add to Make Parentheses Valid. Memory Usage: 8.6 MB, less than 38.46% of
  // C++ online submissions for Minimum Add to Make Parentheses Valid.
  //
  // O(n) time, O(n) space.
  static int minAddToMakeValid(const std::string &S) {
    std::stack<char> st;
    for (auto &ch : S) {
      if (ch == ')')
        if (!st.empty() && st.top() == '(') {
          st.pop();
          continue;
        }
      st.push(ch);
    }
    return st.size();
  }
};

class Solution2 {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum
  // Add to Make Parentheses Valid. Memory Usage: 8.4 MB, less than 84.62% of
  // C++ online submissions for Minimum Add to Make Parentheses Valid.
  //
  // O(n) time, O(1) space.
  static int minAddToMakeValid(const std::string &S) {
    int count = 0, ans = 0;
    for (auto &ch : S)
      if (ch == '(' && count <= 0)
        ans += abs(count), count = 1;
      else
        count += (ch == '(') ? 1 : -1;
    return ans + abs(count);
  }
};

int main() {
  printf("%d %d\n", Solution::minAddToMakeValid("())"),
         Solution2::minAddToMakeValid("())"));
  printf("%d %d\n", Solution::minAddToMakeValid("((("),
         Solution2::minAddToMakeValid("((("));
  printf("%d %d\n", Solution::minAddToMakeValid("()"),
         Solution2::minAddToMakeValid("()"));
  printf("%d %d\n", Solution::minAddToMakeValid("()))(("),
         Solution2::minAddToMakeValid("()))(("));
  printf("%d %d\n", Solution::minAddToMakeValid("(()())(("),
         Solution2::minAddToMakeValid("(()())(("));
}
