//
// Created by saubhik on 2019/11/03.
//
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left{};
  TreeNode *right{};
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  static bool isUnivalTree(TreeNode *root) { return helper(root, root->val); }
  static bool helper(TreeNode *root, int val) {
    if (!root)
      return true;
    if (root->val == val)
      return helper(root->left, val) && helper(root->right, val);
    return false;
  }
};

int main() {
  auto *root = new TreeNode(2);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(2);
  root->right = new TreeNode(2);
  printf("%d\n", Solution::isUnivalTree(root));

  root = new TreeNode(2);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(2);
  root->right = new TreeNode(2);
  printf("%d", Solution::isUnivalTree(root));
}
