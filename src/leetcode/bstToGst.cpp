//
// Created by saubhik on 2019/11/06.
//

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  static TreeNode *bstToGst(TreeNode *root) {
    helper(root, 0);
    return root;
  }
  static int helper(TreeNode *root, int carry) {
    if (!root)
      return carry;
    root->val += helper(root->right, carry);
    return helper(root->left, root->val);
  }

  // without using helper
  int pre = 0;
  TreeNode *bstToGst2(TreeNode *root) {
    if (root->left)
      bstToGst2(root->left);
    pre = root->val = root->val + pre;
    if (root->right)
      bstToGst2(root->right);
    return root;
  }
};

int main() {
  // TODO: add checks
}
