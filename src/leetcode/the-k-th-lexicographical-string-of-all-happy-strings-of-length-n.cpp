//
// Created by saubhik on 2020/05/07.
//
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  static string enumerate(vector<string> &strings, int n, int k) {
    if (n == 0) {
      return k <= strings.size() ? strings[k - 1] : "";
    }

    vector<string> newStrings;
    for (string elem : strings) {
      for (char ch : {'a', 'b', 'c'}) {
        if (elem.empty()) {
          newStrings.emplace_back(1, ch);
        } else if (elem.back() != ch) {
          newStrings.push_back(elem + ch);
        }
      }
    }

    return enumerate(newStrings, --n, k);
  }

public:
  // Runtime: 120 ms, faster than 34.10% of C++ online submissions for The k-th
  // Lexicographical String of All Happy Strings of Length n. Memory Usage: 39
  // MB, less than 100.00% of C++ online submissions for The k-th
  // Lexicographical String of All Happy Strings of Length n.
  //
  // O(3^n) time, O(3^n) space.
  static string getHappyString(int n, int k) {
    vector<string> strings = {""};
    return enumerate(strings, n, k);
  }
};

int main() {
  assert(Solution::getHappyString(1, 3) == "c");
  assert(Solution::getHappyString(1, 4).empty());
  assert(Solution::getHappyString(3, 9) == "cab");
  assert(Solution::getHappyString(2, 7).empty());
  assert(Solution::getHappyString(10, 100) == "abacbabacb");
}
