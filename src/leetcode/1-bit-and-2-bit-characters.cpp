//
// Created by saubhik on 2020/01/08.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for 1-bit and
  // 2-bit Characters. Memory Usage: 8.6 MB, less than 100.00% of C++ online
  // submissions for 1-bit and 2-bit Characters.
  //
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
