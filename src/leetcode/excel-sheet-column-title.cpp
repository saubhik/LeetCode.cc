//
// Created by saubhik on 2020/05/06.
//
#include <string>

using namespace std;

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel
  // Sheet Column Title. Memory Usage: 6.1 MB, less than 100.00% of C++ online
  // submissions for Excel Sheet Column Title.
  //
  // O(lgn) time, O(1) extra space.
  static string convertToTitle(int n) {
    string res;
    while (n) {
      res.push_back('A' + --n % 26);
      n /= 26;
    }
    reverse(begin(res), end(res));
    return res;
  }
};

int main() {
  assert(Solution::convertToTitle(1) == "A");
  assert(Solution::convertToTitle(26) == "Z");
  assert(Solution::convertToTitle(701) == "ZY");
  assert(Solution::convertToTitle(703) == "AAA");
}
