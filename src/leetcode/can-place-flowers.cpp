//
// Created by saubhik on 2020/02/07.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 12 ms, faster than 97.12% of C++ online submissions for Can Place
  // Flowers. Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions
  // for Can Place Flowers.
  //
  // O(n) time, O(1) space.
  static bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int s = flowerbed.size();
    for (int i = 0; i < s; ++i)
      if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
          (i == s - 1 || flowerbed[i + 1] == 0)) {
        flowerbed[i] = 1;
        if (n-- < 0)
          return true;
      }
    return n <= 0;
  }
};

int main() {
  vector<int> flowerbed = {1, 0, 0, 0, 1};
  printf("%d\n", Solution::canPlaceFlowers(flowerbed, 1));
  printf("%d\n", Solution::canPlaceFlowers(flowerbed, 2));

  flowerbed = {1, 0, 0, 0, 0, 1};
  printf("%d", Solution::canPlaceFlowers(flowerbed, 1));
}
