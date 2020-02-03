//
// Created by saubhik on 2020/02/03.
//
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone
  // Weight. Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions
  // for Last Stone Weight.
  //
  // O(nlogn) time, O(n) space.
  static int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> pq(begin(stones), end(stones));
    while (pq.size() > 1) {
      auto a = pq.top();
      pq.pop();
      auto b = pq.top();
      pq.pop();
      pq.push(a - b);
    }
    return pq.empty() ? 0 : pq.top();
  }
};

int main() {
  vector<int> stones = {2, 7, 4, 1, 8, 1};
  printf("%d", Solution::lastStoneWeight(stones));
}
