//
// Created by saubhik on 2019/12/10.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 97.99% run-time, 88.89% memory.
  // O(n) time, O(1) space.
  static int maxProfit(vector<int> &prices) {
    int profit = 0, n = prices.size();

    if (n == 1)
      return profit;

    for (int i = 0; i < n; ++i) {
      if (i == 0 && prices[i] < prices[i + 1])
        profit -= prices[i];
      else if (i == n - 1 && prices[i] > prices[i - 1])
        profit += prices[i];
      else if (0 < i && i < n - 1 && prices[i - 1] < prices[i] &&
               prices[i] >= prices[i + 1])
        profit += prices[i];
      else if (0 < i && i < n - 1 && prices[i - 1] >= prices[i] &&
               prices[i] < prices[i + 1])
        profit -= prices[i];
    }

    return profit;
  }
};

class Solution2 {
public:
  // 97.99% run-time, 100% memory
  // simple one pass.
  // O(n) time, O(1) space.
  static int maxProfit(vector<int> &prices) {
    int profit = 0, n = prices.size();
    for (int i = 1; i < n; ++i)
      if (prices[i] > prices[i - 1])
        profit += prices[i] - prices[i - 1];
    return profit;
  }
};

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  printf("%d %d\n", Solution::maxProfit(prices), Solution2::maxProfit(prices));

  prices = {1, 2, 3, 4, 5};
  printf("%d %d\n", Solution::maxProfit(prices), Solution2::maxProfit(prices));

  prices = {7, 6, 4, 3, 1};
  printf("%d %d\n", Solution::maxProfit(prices), Solution2::maxProfit(prices));

  prices = {7, 0, 0, 0, 4, 4, 4, 3, 1};
  printf("%d %d\n", Solution::maxProfit(prices), Solution2::maxProfit(prices));

  prices = {1};
  printf("%d %d\n", Solution::maxProfit(prices), Solution2::maxProfit(prices));

  prices = {1, 1, 0};
  printf("%d %d", Solution::maxProfit(prices), Solution2::maxProfit(prices));
}
