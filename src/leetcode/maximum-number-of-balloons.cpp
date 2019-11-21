//
// Created by saubhik on 2019/11/21.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // 100% runtime, 100% memory
  static int maxNumberOfBalloons(string text) {
    vector<int> mp(26, 0);
    for (char s : text)
      if (s == 'b' || s == 'a' || s == 'l' || s == 'o' || s == 'n')
        ++mp[s - 'a'];

    int ans = 10000;
    for (auto s : "balon")
      if (s == 'l' || s == 'o')
        ans = min(ans, mp[s - 'a'] / 2);
      else if (s != '\0')
        ans = min(ans, mp[s - 'a']);

    return ans;
  }
};

int main() {
  printf("%d\n", Solution::maxNumberOfBalloons("nlaebolko"));
  printf("%d\n", Solution::maxNumberOfBalloons("loonbalxballpoon"));
  printf("%d", Solution::maxNumberOfBalloons("leetcode"));
}