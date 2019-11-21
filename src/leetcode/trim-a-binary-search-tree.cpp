//
// Created by saubhik on 2019/11/21.
//
#include "../utils/btree/bTreeUtils.h"
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // 90.56% run-time, 68.42% memory
  static TreeNode *trimBST(TreeNode *root, int L, int R) {
    if (!root) {
      return nullptr;
    }

    if (root->val < L) {
      return trimBST(root->right, L, R);
    }

    else if (root->val > R) {
      return trimBST(root->left, L, R);
    }

    else {
      root->left = trimBST(root->left, L, R);
      root->right = trimBST(root->right, L, R);
      return root;
    }
  }
};

int main() {
  vector<int> nodes = {1, 0, 2};
  TreeNode *ans, *root = (TreeNode *)vecToBTree(nodes);
  ans = Solution::trimBST(root, 1, 2);
  showBTree((BinTree<int>::Node *)(ans));

  puts("");

  nodes = {3, 0, 4, -1, 2, -1, -1, 1, -1};
  root = (TreeNode *)vecToBTree(nodes);
  //  showBTree(nodes);
  ans = Solution::trimBST(root, 1, 3);
  showBTree((BinTree<int>::Node *)(ans));

  puts("");

  nodes = {3, 1, 4, -1, 2};
  root = (TreeNode *)vecToBTree(nodes);
  //  showBTree(nodes);
  ans = Solution::trimBST(root, 1, 2);
  showBTree((BinTree<int>::Node *)(ans));
}
