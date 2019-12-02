//
// Created by saubhik on 2019/12/02.
//
#include <string>
using namespace std;

class Solution {
public:
  // 100% run-time, 60% memory
  // O(min(|a|, |b|)) time, O(1) space.
  static int findLUSlength(string a, string b) {
    return (a == b) ? -1 : max(a.length(), b.length());
  }
};

int main() {
  printf("%d\n", Solution::findLUSlength("aba", "cdc"));
  printf("%d\n", Solution::findLUSlength("aaa", "aaa"));
}
