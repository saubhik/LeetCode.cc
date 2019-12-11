//
// Created by saubhik on 2019/12/10.
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
  // 96.97% run-time, 100% memory.
  // O(nlgn) time, O(lgn) space.
  // O(nlgn) time due to binary search for each of n elements.
  // O(lgn) space due to DFS recursion stack.
  static bool findTarget(TreeNode *root, int k) { return dfs(root, root, k); }

private:
  static bool dfs(TreeNode *root, TreeNode *node, int k) {
    if (!node)
      return false;
    else if (searchBST(root, k - node->val, node))
      return true;
    else
      return dfs(root, node->left, k) || dfs(root, node->right, k);
  }

  static bool searchBST(TreeNode *root, int elem, TreeNode *node) {
    if (!root)
      return false;

    if (root->val == elem && root != node)
      return true;
    else
      return (root->val < elem) ? searchBST(root->right, elem, node)
                                : searchBST(root->left, elem, node);
  }
};

class Solution2 {
public:
  // 96.97% run-time, 100% memory.
  // O(n) time, O(n) space.
  static bool findTarget(TreeNode *root, int k) {
    vector<int> vals;
    inOrderWalk(root, vals);
    int l = 0, r = vals.size() - 1, tmp;
    while (l < r) {
      tmp = vals[l] + vals[r];
      if (tmp == k)
        return true;
      else if (tmp < k)
        ++l;
      else
        --r;
    }
    return false;
  }

private:
  static void inOrderWalk(TreeNode *root, vector<int> &vals) {
    if (!root)
      return;
    inOrderWalk(root->left, vals);
    vals.push_back(root->val);
    inOrderWalk(root->right, vals);
  }
};

int main() {
  vector<int> arr = {5, 3, 6, 2, 4, -1, 7};
  TreeNode *root = (TreeNode *)vecToBTree(arr);
  printf("%d %d\n", Solution::findTarget(root, 9),
         Solution2::findTarget(root, 9));
  printf("%d %d\n", Solution::findTarget(root, 28),
         Solution2::findTarget(root, 28));
  printf("%d %d", Solution::findTarget(root, 14),
         Solution2::findTarget(root, 14));
}
