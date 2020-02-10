//
// Created by saubhik on 2020/02/10.
//
#include "../utils/btree/bTreeUtils.h"
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // Runtime: 32 ms, faster than 95.28% of C++ online submissions for Lowest
  // Common Ancestor of a Binary Search Tree. Memory Usage: 25.7 MB, less than
  // 100.00% of C++ online submissions for Lowest Common Ancestor of a Binary
  // Search Tree.
  //
  // O(h) time, O(1) space.
  static TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p,
                                        TreeNode *q) {
    while ((p->val < root->val && q->val < root->val) ||
           (p->val > root->val && q->val > root->val)) {
      while (p->val < root->val && q->val < root->val)
        root = root->left;
      while (p->val > root->val && q->val > root->val)
        root = root->right;
    }
    return root;
  }
};

int main() {
  vector<int> arr = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
  auto root = (TreeNode *)vecToBTree(arr);
  TreeNode *p = root->left, *q = root->right;
  TreeNode *ans = Solution::lowestCommonAncestor(root, p, q);
  showBTree((BinTree<int>::Node *)(ans));

  printf("\n");

  root = (TreeNode *)vecToBTree(arr);
  p = root->left, q = root->left->right;
  ans = Solution::lowestCommonAncestor(root, p, q);
  showBTree((BinTree<int>::Node *)(ans));
}
