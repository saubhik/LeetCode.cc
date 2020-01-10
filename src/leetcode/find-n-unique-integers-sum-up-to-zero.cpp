//
// Created by saubhik on 2020/01/10.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 4 ms, faster than 98.69% of C++ online submissions for Find N
  // Unique Integers Sum up to Zero. Memory Usage: 8.9 MB, less than 100.00% of
  // C++ online submissions for Find N Unique Integers Sum up to Zero.
  //
  // O(n) time, O(1) space.
  static vector<int> sumZero(int n) {
    vector<int> ans(n, 0);
    for (int i = 0; n - i >= 2; i += 2)
      ans[i] = i + 1, ans[i + 1] = -(i + 1);
    if (n % 2)
      ans[n - 1] = 0;
    return ans;
  }
};

int main() {
  vector<int> ans;
  ans = Solution::sumZero(5);
  for (int num : ans)
    printf("%d ", num);

  printf("\n");

  ans = Solution::sumZero(3);
  for (int num : ans)
    printf("%d ", num);

  printf("\n");

  ans = Solution::sumZero(1);
  for (int num : ans)
    printf("%d ", num);
}
