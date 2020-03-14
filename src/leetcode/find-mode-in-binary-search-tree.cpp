//
// Created by saubhik on 2020/03/12.
//
#include "../utils/btree/bTreeUtils.h"
#include <algorithm>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  static void inOrderWalk(TreeNode *node, std::vector<int> &modes, int &last,
                          int &count, int &maxCount) {
    if (!node)
      return;

    inOrderWalk(node->left, modes, last, count, maxCount);

    if (node->val == last)
      ++count;
    else {

      if (count > maxCount) {
        modes = {last};
        maxCount = count;
      } else if (count == maxCount)
        modes.push_back(last);

      last = node->val;
      count = 1;
    }

    inOrderWalk(node->right, modes, last, count, maxCount);
  }

public:
  // Runtime: 20 ms, faster than 88.61% of C++ online submissions for Find Mode
  // in Binary Search Tree. Memory Usage: 22.1 MB, less than 100.00% of C++
  // online submissions for Find Mode in Binary Search Tree.
  //
  // O(n) time, O(1) space.
  static std::vector<int> findMode(TreeNode *root) {
    std::vector<int> modes = {};
    int last, count, maxCount = INT_MIN;
    last = count = -1;
    inOrderWalk(root, modes, last, count, maxCount);
    if (!modes.empty()) {
      if (count > maxCount) {
        modes = {last};
        maxCount = count;
      } else if (count == maxCount)
        modes.push_back(last);
    }
    return modes;
  }
};

int main() {
  std::vector<int> arr, ans;
  TreeNode *root;

  arr = {1, -1, 2, 2};
  root = (TreeNode *)vecToBTree(arr);
  ans = Solution::findMode(root);
  printf("[");
  for (auto &elem : ans)
    printf(" %d ", elem);
  printf("]");

  printf("\n");

  ans = Solution::findMode(nullptr);
  printf("[");
  for (auto &elem : ans)
    printf("%d ", elem);
  printf("]");
}
