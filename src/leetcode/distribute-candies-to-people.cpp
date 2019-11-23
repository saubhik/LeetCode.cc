//
// Created by saubhik on 2019/11/24.
//
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
  // 100% run-time, 100% memory
  static vector<int> distributeCandies(int candies, int num_people) {
    int rounds = (sqrt(1 + 8 * (long)candies) - 1) / (2 * num_people);
    vector<int> ans(num_people, num_people * rounds * (rounds - 1) / 2);
    for (int i = 0; i < num_people; ++i) {
      ans[i] += (i + 1) * rounds;
      candies -= ans[i];
    }

    int lastRound;
    for (int i = 0; i < num_people; ++i)
      if (candies > 0) {
        lastRound = num_people * rounds + (i + 1);
        ans[i] += min(candies, lastRound);
        candies -= min(candies, lastRound);
      } else
        break;

    return ans;
  }
};

class Solution2 {
public:
  // brute force, O(sqrt(candies))
  static vector<int> distributeCandies(int candies, int n) {
    vector<int> res(n);
    for (int i = 0; candies > 0; ++i) {
      res[i % n] += min(candies, i + 1);
      candies -= i + 1;
    }
    return res;
  }
};

int main() {
  auto ans = Solution::distributeCandies(7, 4);
  for (auto elem : ans)
    printf("%d ", elem);

  printf("\n");

  ans = Solution::distributeCandies(10, 3);
  for (auto elem : ans)
    printf("%d ", elem);

  printf("\n");

  ans = Solution::distributeCandies(1000000000, 1000);
  for (auto elem : ans)
    printf("%d ", elem);
}
