//
// Created by saubhik on 2019/11/24.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // 96.63% run-time, 93.33% memory.
  // O(n) time, O(1) additional space.
  static vector<string> fizzBuzz(int n) {
    vector<string> ans(n);
    for (int i = 1; i <= n; ++i) {
      if (i % 15 == 0)
        ans[i - 1] = "FizzBuzz";
      else if (i % 3 == 0)
        ans[i - 1] = "Fizz";
      else if (i % 5 == 0)
        ans[i - 1] = "Buzz";
      else
        ans[i - 1] = to_string(i);
    }
    return ans;
  }
};

class Solution2 {
public:
  // without using modulo
  // extra writes might be better than expensive arithmetic
  static vector<string> fizzBuzz(int n) {
    vector<string> ans(n);
    for (int i = 1; i <= n; ++i)
      ans[i - 1] = to_string(i);
    for (int i = 3; i <= n; i += 3)
      ans[i - 1] = "Fizz";
    for (int i = 5; i <= n; i += 5)
      ans[i - 1] = "Buzz";
    for (int i = 15; i <= n; i += 15)
      ans[i - 1] = "FizzBuzz";
    return ans;
  }
};

int main() {
  vector<string> ans = Solution::fizzBuzz(15);
  for (auto s : ans)
    printf("%s ", s.c_str());

  printf("\n");

  ans = Solution2::fizzBuzz(15);
  for (auto s : ans)
    printf("%s ", s.c_str());
}
