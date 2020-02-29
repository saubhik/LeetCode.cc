//
// Created by saubhik on 2020/02/29.
//
#include <cmath>
#include <vector>

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Path In
  // Zigzag Labelled Binary Tree. Memory Usage: 7.7 MB, less than 100.00% of C++
  // online submissions for Path In Zigzag Labelled Binary Tree.
  //
  // O(logn) time, O(1) space.
  static std::vector<int> pathInZigZagTree(int label) {
    int level = (int)log2(label) + 1, tmp = pow(2, level);
    std::vector<int> res(level);
    for (int l = level; l > 0; --l, label /= 2, tmp /= 2)
      label = res[l - 1] = (l == level) ? label : tmp - 1 - label + tmp / 2;
    return res;
  }
};

class Solution2 {
public:
  // courtesy: votrubac
  // Idea is to convert the log2 and pow to bit shift ops.
  // Nodes in a level are between (1 << (level - 1)) and (1 << level - 1).
  static std::vector<int> pathInZigZagTree(unsigned label, int level = 0) {
    while ((unsigned)1 << (unsigned)level <= label)
      ++level;
    std::vector<int> res(level);
    for (; label >= 1; label /= 2, --level) {
      res[level - 1] = label;
      label = ((unsigned)1 << (unsigned)level) - 1 - label +
              ((unsigned)1 << (unsigned)(level - 1));
    }
    return res;
  }
};

int main() {
  std::vector<int> ans;
  ans = Solution2::pathInZigZagTree(14);
  for (int elem : ans)
    printf("%d ", elem);

  printf("\n");

  ans = Solution2::pathInZigZagTree(26);
  for (int elem : ans)
    printf("%d ", elem);

  printf("\n");

  ans = Solution2::pathInZigZagTree(1);
  for (int elem : ans)
    printf("%d ", elem);
}
