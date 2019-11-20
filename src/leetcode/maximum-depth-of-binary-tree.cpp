//
// Created by saubhik on 2019/11/20.
//
#include "../utils/btree/bTreeUtils.h"
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // 87.85% run-time, 79.12% memory
  // O(n) time, O(h) space.
  static int maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
  }
};

int main() {
  vector<int> nodes = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root = (TreeNode *)vecToBTree(nodes);
  printf("%d", Solution::maxDepth(root));
}
