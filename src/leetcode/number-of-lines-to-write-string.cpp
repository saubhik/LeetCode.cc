//
// Created by saubhik on 2019/11/24.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // 100% run-time, 100% memory
  // O(n) time, O(1) additional space.
  // Here n is the string length.
  static vector<int> numberOfLines(vector<int> &widths, string S) {
    vector<int> ans = {1, 0};
    for (int i = 0; i < S.length(); ++i) {
      if (ans[1] + widths[S[i] - 'a'] > 100) {
        ans[1] = 0;
        ans[0] += 1;
      }
      ans[1] += widths[S[i] - 'a'];
    }
    return ans;
  }
};

int main() {
  vector<int> widths = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                        10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  auto nums = Solution::numberOfLines(widths, "abcdefghijklmnopqrstuvwxyz");
  for (auto elem : nums)
    printf("%d ", elem);

  printf("\n");

  widths = {4,  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
            10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  nums = Solution::numberOfLines(widths, "bbbcccdddaaa");
  for (auto elem : nums)
    printf("%d ", elem);
}
