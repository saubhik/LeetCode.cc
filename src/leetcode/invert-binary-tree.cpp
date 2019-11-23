//
// Created by saubhik on 2019/11/23.
//
#include "../utils/btree/bTreeUtils.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // 100% run-time, 96.36% memory
  // recursive, O(n) time, O(h) space (recursion stack)
  static TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return nullptr;
    auto tmp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = tmp;
    return root;
  }
};

class Solution2 {
public:
  // using swap
  // 100% run-time, 100% memory
  // recursive, O(n) time, O(h) space (recursion stack)
  static TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return nullptr;
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;
  }
};

class Solution3 {
public:
  // 100% run-time, 100% memory
  // iterative, O(n) time, O(n) space
  static TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return nullptr;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      auto node = q.front();
      q.pop();

      TreeNode *left = nullptr, *right = nullptr;

      if (node->left) {
        right = node->left;
        q.push(node->left);
      }

      if (node->right) {
        left = node->right;
        q.push(node->right);
      }

      node->left = left;
      node->right = right;
    }

    return root;
  }
};

int main() {
  vector<int> nodes = {4, 2, 7, 1, 3, 6, 9};
  TreeNode *root = (TreeNode *)(vecToBTree(nodes));
  auto ans = Solution3::invertTree(root);
  showBTree((BinTree<int>::Node *)(ans));
}
