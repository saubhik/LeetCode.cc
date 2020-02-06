//
// Created by saubhik on 2020/02/06.
//
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  // Runtime: 4 ms, faster than 92.20% of C++ online submissions for Add
  // Strings. Memory Usage: 9 MB, less than 73.91% of C++ online submissions for
  // Add Strings.
  //
  // Also got this:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add
  // Strings. Memory Usage: 9.1 MB, less than 43.48% of C++ online submissions
  // for Add Strings.
  //
  // O(n) time, O(1) space.
  static string addStrings(string num1, string num2) {
    int i = (int)num1.size() - 1, j = (int)num2.size() - 1, carry = 0, sum;
    string res;
    while (i >= 0 || j >= 0 || carry) {
      sum = carry;
      if (i >= 0)
        sum += num1[i--] - '0';
      if (j >= 0)
        sum += num2[j--] - '0';
      carry = sum / 10;
      res.push_back('0' + sum % 10);
    }
    reverse(begin(res), end(res));
    return res;
  }
};

int main() {
  printf("%s\n", Solution::addStrings("99", "34").c_str());
  printf("%s", Solution::addStrings("28", "3").c_str());
}
