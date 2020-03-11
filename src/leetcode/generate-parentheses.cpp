//
// Created by saubhik on 2020/03/09.
//
#include <string>
#include <vector>

class Solution {
private:
  static void backTrack(std::vector<std::string> &ans, std::string &tmp, int n,
                        int open, int close) {
    if (tmp.size() == 2 * n)
      ans.push_back(tmp);

    if (open < n) {
      tmp.push_back('(');
      backTrack(ans, tmp, n, open + 1, close);
      tmp.pop_back();
    }

    if (close < open) {
      tmp.push_back(')');
      backTrack(ans, tmp, n, open, close + 1);
      tmp.pop_back();
    }
  }

public:
  // another recursion with backtracking.
  //
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Generate
  // Parentheses. Memory Usage: 13.1 MB, less than 91.74% of C++ online
  // submissions for Generate Parentheses.
  //
  // O(2**n) time, O(n) space.
  // In the above, n is the length of the parentheses string.
  static std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    std::string tmp;
    backTrack(result, tmp, n, 0, 0);
    return result;
  }
};

int main() {
  std::vector<std::string> pars;
  pars = Solution::generateParenthesis(3);
  for (auto &elem : pars)
    printf("%s\n", elem.c_str());
}