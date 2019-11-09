//
// Created by saubhik on 2019/11/09.
//
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
  // Easy way is to find inorder traversal and make tree
  // but that takes extra O(n) space.
  // super slow: 7.23% run-time, 10% memory
  static TreeNode *increasingBST_SLOW_1(TreeNode *root) {
    TreeNode *node = new TreeNode(root->val), *tmp;

    if (root->left) {
      node = increasingBST_SLOW_1(root->left);

      // go extreme right
      tmp = node;
      while (tmp->right)
        tmp = tmp->right;

      tmp->right = new TreeNode(root->val);
    }

    if (root->right) {
      // go extreme right
      tmp = node;
      while (tmp->right)
        tmp = tmp->right;

      tmp->right = increasingBST_SLOW_1(root->right);
    }

    return node;
  }
};

class Solution2 {
public:
  // with in-order helper
  // 54% run-time, 30% memory
  // this is O(N) time, O(N) space
  // Just for fun:
  // C++ takes ~36ms, ~24.6MB
  // Java takes ~3ms, ~37.3MB
  static TreeNode *increasingBST_SLOW_2(TreeNode *root) {
    if (!root)
      return root;

    vector<int> values;
    inOrderWalk(root, values);

    // We need a pre-pointer otherwise hell:
    // auto *myRoot = new TreeNode(values[0]);
    // TreeNode *curr = myRoot;
    // for (int i = 1; i < (int)values.size(); ++i) {
    //   curr->right = new TreeNode(values[i]);
    //   curr = curr->right;
    // }
    // This is just better coding, not more efficient.
    auto *preRoot = new TreeNode(0), *curr = preRoot;
    for (int val : values) {
      curr->right = new TreeNode(val);
      curr = curr->right;
    }
    return preRoot->right;
  }

  static void inOrderWalk(TreeNode *root, vector<int> &values) {
    if (!root)
      return;
    inOrderWalk(root->left, values);
    values.push_back(root->val);
    inOrderWalk(root->right, values);
  }
};

class Solution3 {
public:
  // O(N) time, O(H) space
  // where H is the height of the tree.
  // Relinking approach.
  // Let's remove the extra space from the previous solution.
  // 77% run-time, 100% memory
  static TreeNode *increasingBST(TreeNode *root) {
    TreeNode *preRoot = new TreeNode(0), *curr = preRoot;
    inOrderWalk(root, curr);
    curr->left = nullptr;
    return preRoot->right;
  }
  static void inOrderWalk(TreeNode *root, TreeNode *&curr) {
    if (!root)
      return;
    inOrderWalk(root->left, curr);
    curr->left = nullptr;
    curr->right = root;
    curr = curr->right;
    inOrderWalk(root->right, curr);
  }
};

class Solution4 {
public:
  // Condense the above logic.
  // This is Lee's solution.
  // 90% run-time, 100% memory
  static TreeNode *increasingBST(TreeNode *root, TreeNode *tail = nullptr) {
    if (!root)
      return tail;
    TreeNode *res = increasingBST(root->left, root);
    root->left = nullptr;
    root->right = increasingBST(root->right, tail);
    return res;
  }
};

int main() {
  TreeNode *root = new TreeNode(5), *node;

  // left sub tree
  root->left = new TreeNode(3);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->left->left->left = new TreeNode(1);

  // right sub tree
  root->right = new TreeNode(6);
  root->right->right = new TreeNode(8);
  root->right->right->left = new TreeNode(7);
  root->right->right->right = new TreeNode(9);

  node = Solution4::increasingBST(root);

  while (node) {
    printf("%d ", node->val);
    node = node->right;
  }

  printf("\n");

  root = new TreeNode(379);
  root->right = new TreeNode(826);

  node = Solution4::increasingBST(root);

  while (node) {
    printf("%d ", node->val);
    node = node->right;
  }
}
