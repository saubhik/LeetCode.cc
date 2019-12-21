//
// Created by saubhik on 2019/12/21.
//
#include "../utils/btree/bTreeUtils.h"
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  // 82.72%, 4ms run-time; 100%, 13.4% memory.
  // O(n) time, O(n) space.
  static int sumOfLeftLeaves(TreeNode *root, bool left = false) {
    if (!root)
      return 0;
    if (!root->left && !root->right)
      return left ? root->val : 0;
    return sumOfLeftLeaves(root->left, true) +
           sumOfLeftLeaves(root->right, false);
  }
};

int main() {
  vector<int> arr = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root = (TreeNode *)vecToBTree(arr);
  printf("%d", Solution::sumOfLeftLeaves(root));
}
