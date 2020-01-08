//
// Created by saubhik on 2020/01/08.
//
#include <vector>
using namespace std;

class Solution {
public:
  // O(n) time, O(1) space.
  static bool isOneBitCharacter(vector<int> &bits) {
    int n = bits.size();
    bool isOneBit = false;
    for (int i = 0; i < n; ++i) {
      if (bits[i] == 1)
        ++i, isOneBit = false;
      else
        isOneBit = true;
    }
    return isOneBit;
  }
};

int main() {
  vector<int> bits = {1, 0, 0};
  printf("%d\n", Solution::isOneBitCharacter(bits));

  bits = {1, 1, 1, 0};
  printf("%d\n", Solution::isOneBitCharacter(bits));
}
