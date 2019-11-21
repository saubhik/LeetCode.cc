//
// Created by saubhik on 2019/11/18.
//
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  static int lastStoneWeight(vector<int> &stones) {
    while (stones.size() > 1) {
      int max1 = 0, max2 = 0;
      for (int i = 0; i < (int)stones.size(); ++i) {
        if (stones[i] >= max2)
          max2 = stones[i];
        if (stones[i] >= max1) {
          max2 = max1;
          max1 = stones[i];
        }
      }
      if (max1 > max2)
        stones.push_back(max1 - max2);
    }
  }
};
