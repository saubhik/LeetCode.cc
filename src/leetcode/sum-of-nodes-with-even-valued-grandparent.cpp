//
// Created by saubhik on 2020/01/27.
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
  // Runtime: 44 ms, faster than 90.83% of C++ online submissions for Sum of
  // Nodes with Even-Valued Grandparent. Memory Usage: 31.4 MB, less than
  // 100.00% of C++ online submissions for Sum of Nodes with Even-Valued
  // Grandparent.
  // O(n) time, O(n) space, where n is number of nodes.
  static int sumEvenGrandparent(TreeNode *root, TreeNode *p = nullptr,
                                TreeNode *gp = nullptr) {
    if (!root)
      return 0;
    int ans = sumEvenGrandparent(root->left, root, p) +
              sumEvenGrandparent(root->right, root, p);
    if (gp && gp->val % 2 == 0)
      ans += root->val;
    return ans;
  }
};

int main() {
  vector<int> nodes = {6, 7, 8, 2, 7, 1, 3, 9, -1, 1, 4, -1, -1, -1, 5};
  auto *root = (TreeNode *)vecToBTree(nodes);
  printf("%d", Solution::sumEvenGrandparent(root));
}
