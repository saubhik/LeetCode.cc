//
// Created by saubhik on 2019/11/07.
//
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // O(n) worst case time, O(n) space
  static TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (!root)
      return new TreeNode(val);
    if (val < root->val)
      root->left = insertIntoBST(root->left, val);
    else
      root->right = insertIntoBST(root->right, val);
    return root;
  }

  // O(n) time, O(1) space
  static TreeNode *insertIntoBSTIterative(TreeNode *root, int val) {
    TreeNode *curr = root, *newNode = new TreeNode(val);
    while (curr) {
      if (val < curr->val) {
        if (!curr->left) {
          curr->left = newNode;
          break;
        } else {
          curr = curr->left;
        }
      } else {
        if (!curr->right) {
          curr->right = newNode;
          break;
        } else {
          curr = curr->right;
        }
      }
    }
    return root ? root : newNode;
  }

  // O(n) time, O(1) space, use trailing pointer
  // Motivation: I don't want to check for null every time
  static TreeNode *insertIntoBSTIterative2(TreeNode *root, int val) {
    auto *node = new TreeNode(val);
    if (!root)
      return node;
    TreeNode *curr = root, *prev = root;
    while (curr) {
      prev = curr;
      if (val < curr->val)
        curr = curr->left;
      else
        curr = curr->right;
    }
    if (val < prev->val)
      prev->left = node;
    else
      prev->right = node;
    return root;
  }

  // This is just beautiful programming
  static TreeNode *insertIntoBSTIterative3(TreeNode *root, int val) {
    TreeNode **curr = &root;
    while (*curr) {
      curr = (val > (*curr)->val) ? &(*curr)->right : &(*curr)->left;
    }
    *curr = new TreeNode(val);
    return root;
  }
};
