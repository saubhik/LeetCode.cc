//
// Created by saubhik on 2019/11/16.
//
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  // 100% run-time, 72.73% memory
  // time complexity is O(log_{26}(n)).
  // space complexity is also O(log_{26}(n)).
  static string convertToTitle(int n) {
    int tmp;
    string ans;
    while (n) {
      tmp = n % 26 ? n % 26 : 26;
      ans.push_back((char)('A' + tmp - 1));
      n -= tmp;
      n /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  printf("%s\n", Solution::convertToTitle(1).c_str());
  printf("%s\n", Solution::convertToTitle(28).c_str());
  printf("%s\n", Solution::convertToTitle(701).c_str());
}
