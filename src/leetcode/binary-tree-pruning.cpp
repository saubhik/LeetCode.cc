//
// Created by saubhik on 2020/02/02.
//
#include "../utils/btree/bTreeUtils.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // Runtime: 4 ms, faster than 71.14% of C++ online submissions for Binary Tree
  // Pruning. Memory Usage: 11.2 MB, less than 7.14% of C++ online submissions
  // for Binary Tree Pruning.
  //
  // this problem is same as delete-leaves-with-a-given-value
  // O(n) time, O(n) space; where n is the number of vertices.
  static TreeNode *pruneTree(TreeNode *node) {
    if (!node)
      return nullptr;
    node->left = pruneTree(node->left);
    node->right = pruneTree(node->right);
    return !node->left && !node->right && node->val == 0 ? nullptr : node;
  }
};

int main() {
  vector<int> arr = {1, -1, 0, 0, 1};
  auto node = (TreeNode *)vecToBTree(arr);
  TreeNode *ans = Solution::pruneTree(node);
  showBTree((BinTree<int>::Node *)(ans));

  printf("\n");

  arr = {1, 0, 1, 0, 0, 0, 1};
  node = (TreeNode *)vecToBTree(arr);
  ans = Solution::pruneTree(node);
  showBTree((BinTree<int>::Node *)(ans));

  printf("\n");

  arr = {1, 1, 0, 1, 1, 0, 1, 0};
  node = (TreeNode *)vecToBTree(arr);
  ans = Solution::pruneTree(node);
  showBTree((BinTree<int>::Node *)(ans));
}
