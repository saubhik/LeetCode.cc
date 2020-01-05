//
// Created by saubhik on 2020/01/05.
//
#include "../utils/btree/bTreeUtils.h"
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  // Runtime: 4 ms, faster than 94.90% of C++ online submissions for Binary Tree
  // Level Order Traversal II. Memory Usage: 13.7 MB, less than 100.00% of C++
  // online submissions for Binary Tree Level Order Traversal II. O(n) time,
  // O(n) space where n is the number of nodes in the tree.
  static vector<vector<int>> levelOrderBottom(TreeNode *root) {
    if (!root)
      return {};

    queue<TreeNode *> q;
    q.push(root);

    vector<vector<int>> res = {{root->val}};
    vector<int> levelValues;
    int levelSize;

    while (!q.empty()) {
      levelValues = {}, levelSize = q.size();
      while (levelSize--) {
        auto &node = q.front();
        if (node->left)
          levelValues.push_back(node->left->val), q.push(node->left);
        if (node->right)
          levelValues.push_back(node->right->val), q.push(node->right);
        q.pop();
      }
      if (!levelValues.empty())
        res.push_back(levelValues);
    }

    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  vector<int> arr = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root = (TreeNode *)vecToBTree(arr);
  vector<vector<int>> ans = Solution::levelOrderBottom(root);
  for (auto &level : ans) {
    for (auto &val : level)
      printf("%d ", val);
    printf("\n");
  }
}
