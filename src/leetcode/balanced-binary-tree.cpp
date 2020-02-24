//
// Created by saubhik on 2020/02/24.
//
#include "../utils/btree/bTreeUtils.h"
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  static int height(TreeNode *node) {
    if (!node)
      return 0;
    int left = height(node->left);
    if (left == -1)
      return -1;
    int right = height(node->right);
    if (right == -1)
      return -1;
    if (abs(left - right) > 1)
      return -1;
    return 1 + std::max(left, right);
  }

public:
  // Runtime: 12 ms, faster than 84.63% of C++ online submissions for Balanced
  // Binary Tree. Memory Usage: 17.2 MB, less than 93.22% of C++ online
  // submissions for Balanced Binary Tree.
  //
  // Runtime: 8 ms, faster than 97.21% of C++ online submissions for Balanced
  // Binary Tree. Memory Usage: 17.3 MB, less than 81.36% of C++ online
  // submissions for Balanced Binary Tree.
  //
  // O(n) time, O(n) space.
  static bool isBalanced(TreeNode *root) { return height(root) != -1; }
};

int main() {
  vector<int> arr = {3, 9, 20, -1, -1, 15, 7};
  auto *root = (TreeNode *)vecToBTree(arr);
  printf("%d\n", Solution::isBalanced(root));

  arr = {1, 2, 2, 3, 3, -1, -1, 4, 4};
  root = (TreeNode *)vecToBTree(arr);
  printf("%d\n", Solution::isBalanced(root));
}
