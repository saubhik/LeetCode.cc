//
// Created by saubhik on 2019/11/17.
//
#include "../../../utils/btree/bTreeUtils.h"
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class FindElements {
public:
  vector<int> nodes;

  explicit FindElements(TreeNode *root) {
    root->val = 0;
    nodes.push_back(0);
    recover(root);
  }

  void recover(TreeNode *root) {
    if (!root)
      return;
    if (root->left) {
      root->left->val = 2 * root->val + 1;
      nodes.push_back(root->left->val);
      recover(root->left);
    }
    if (root->right) {
      root->right->val = 2 * root->val + 2;
      nodes.push_back(root->right->val);
      recover(root->right);
    }
  }

  bool find(int target) {
    for (auto val : nodes)
      if (val == target)
        return true;
    return false;
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
int main() {
  auto *root = new TreeNode(-1);
  root->right = new TreeNode(-1);
  root->right->left = new TreeNode(-1);
  root->right->left->left = new TreeNode(-1);
  auto *obj = new FindElements(root);
  showBTree((BinTree<int>::Node *)(root));
  printf("%d\n", obj->find(2));
  printf("%d\n", obj->find(3));
  printf("%d\n", obj->find(4));
  printf("%d\n", obj->find(5));

  root = new TreeNode(-1);
  root->right = new TreeNode(-1);
  root->left = new TreeNode(-1);
  root->left->left = new TreeNode(-1);
  root->left->right = new TreeNode(-1);
  obj = new FindElements(root);
  showBTree((BinTree<int>::Node *)(root));
  printf("%d\n", obj->find(1));
  printf("%d\n", obj->find(3));
  printf("%d\n", obj->find(5));
}