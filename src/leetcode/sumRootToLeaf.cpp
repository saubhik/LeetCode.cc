//
// Created by saubhik on 2019/11/20.
//
#include "../utils/btree/bTreeUtils.h"
#include <cstdio>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // 93.40% run-time, 100% memory
  // O(n) time, O(h) space.
  static int sumRootToLeaf(TreeNode *root, int val = 0) {
    if (!root)
      return 0;

    if (!root->left && !root->right)
      return 2 * val + root->val;

    return sumRootToLeaf(root->left, 2 * val + root->val) +
           sumRootToLeaf(root->right, 2 * val + root->val);
  }
};

int main() {
  vector<int> nodes = {1, 0, 1, 0, 1, 0, 1};
  //  showBTree(nodes);
  TreeNode *root = (TreeNode *)(vecToBTree(nodes));
  printf("%d\n", Solution::sumRootToLeaf(root));

  nodes = {1, 1};
  root = (TreeNode *)(vecToBTree(nodes));
  printf("%d", Solution::sumRootToLeaf(root));
}
