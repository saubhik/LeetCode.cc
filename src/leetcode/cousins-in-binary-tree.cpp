//
// Created by saubhik on 2019/12/14.
//
#include "../utils/btree/bTreeUtils.h"
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // 76.22% (4ms) run-time, 100% (11.1MB) memory.
  // O(n) time, O(n) space.
  bool isCousins(TreeNode *root, int x, int y) {
    valX = x, valY = y;
    dfs(root, nullptr, 0);
    return depthX == depthY && parentX && parentY &&
           parentX->val != parentY->val;
  }

private:
  TreeNode *parentX = nullptr, *parentY = nullptr;
  int depthX, depthY, valX, valY;

  void dfs(TreeNode *node, TreeNode *parent, int depth) {
    if (parentX && parentY)
      // already found both values
      return;

    if (node->val == valX) {
      parentX = parent;
      depthX = depth;
    }

    if (node->val == valY) {
      parentY = parent;
      depthY = depth;
    }

    if (node->left)
      dfs(node->left, node, depth + 1);
    if (node->right)
      dfs(node->right, node, depth + 1);
  }
};

int main() {
  TreeNode *root;
  vector<int> arr;

  arr = {1, 2, 3, 4};
  root = (TreeNode *)vecToBTree(arr);
  printf("%d\n", Solution().isCousins(root, 4, 3));

  arr = {1, 2, 3, -1, 4, -1, 5};
  root = (TreeNode *)vecToBTree(arr);
  printf("%d\n", Solution().isCousins(root, 5, 4));

  arr = {1, 2, 3, -1, 4};
  root = (TreeNode *)vecToBTree(arr);
  printf("%d", Solution().isCousins(root, 2, 3));
}
