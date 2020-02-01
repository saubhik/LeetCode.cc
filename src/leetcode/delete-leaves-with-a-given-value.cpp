//
// Created by saubhik on 2020/02/01.
//
#include "../utils/btree/bTreeUtils.h"
struct TreeNode {
  int val;
  TreeNode *left{};
  TreeNode *right{};
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // Runtime: 20 ms, faster than 86.37% of C++ online submissions for Delete
  // Leaves With a Given Value. Memory Usage: 21.6 MB, less than 100.00% of C++
  // online submissions for Delete Leaves With a Given Value.
  //
  // DFS: O(n) time, O(n) space.
  static TreeNode *removeLeafNodes(TreeNode *node, int &target,
                                   TreeNode *parent = nullptr) {
    if (!node)
      return nullptr;
    removeLeafNodes(node->left, target, node);
    removeLeafNodes(node->right, target, node);
    if (!node->left && !node->right && node->val == target) {
      if (!parent)
        return nullptr;
      else if (parent->left == node)
        parent->left = nullptr;
      else
        parent->right = nullptr;
    }
    return node;
  }
};

int main() {
  vector<int> treeVec = {1, 2, 3, 2, -1, 2, 4};
  auto node = (TreeNode *)vecToBTree(treeVec);
  int target = 2;
  TreeNode *ans = Solution::removeLeafNodes(node, target);
  showBTree((BinTree<int>::Node *)(ans));

  printf("\n---\n");

  treeVec = {1, 3, 3, 3, 2};
  node = (TreeNode *)vecToBTree(treeVec);
  target = 3;
  ans = Solution::removeLeafNodes(node, target);
  showBTree((BinTree<int>::Node *)(ans));

  printf("\n---\n");

  treeVec = {1, 2, -1, 2, -1, 2};
  node = (TreeNode *)vecToBTree(treeVec);
  target = 2;
  ans = Solution::removeLeafNodes(node, target);
  showBTree((BinTree<int>::Node *)(ans));

  printf("\n---\n");

  treeVec = {1, 1, 1};
  node = (TreeNode *)vecToBTree(treeVec);
  target = 1;
  ans = Solution::removeLeafNodes(node, target);
  showBTree((BinTree<int>::Node *)(ans));

  printf("\n---\n");

  treeVec = {1, 2, 3};
  node = (TreeNode *)vecToBTree(treeVec);
  target = 1;
  ans = Solution::removeLeafNodes(node, target);
  showBTree((BinTree<int>::Node *)(ans));

  printf("\n---");
}
