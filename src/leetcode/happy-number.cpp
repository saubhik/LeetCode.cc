//
// Created by saubhik on 2020/02/09.
//
#include <unordered_map>
using namespace std;

class Solution {
private:
  unordered_map<int, bool> ump;

public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy
  // Number. Memory Usage: 8.6 MB, less than 53.85% of C++ online submissions
  // for Happy Number.
  //
  // O(?) time, O(?) space.
  bool isHappy(int n) {
    if (n == 1)
      return true;
    else if (ump[n])
      return false;
    ump[n] = true;
    int m = 0;
    while (n) {
      m += (n % 10) * (n % 10);
      n /= 10;
    }
    return isHappy(m);
  }
};

class Solution2 {
public:
  // TODO: use Floyd's Tortoise & Hare Cycle Detection technique
  bool isHappy(int n) {}
};

int main() {
  printf("%d\n", Solution().isHappy(19));
  printf("%d\n", Solution().isHappy(58));
}
