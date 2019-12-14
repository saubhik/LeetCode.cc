//
// Created by saubhik on 2019/12/14.
//
#include "../utils/btree/bTreeUtils.h"
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  static void inorderTraversal(TreeNode *root, vector<int> &nodes) {
    if (!root)
      return;
    inorderTraversal(root->left, nodes);
    nodes.push_back(root->val);
    inorderTraversal(root->right, nodes);
  }

public:
  // 18.46% run-time (28ms), 46.15% memory (22MB).
  // O(n) time, O(n) space.
  static int getMinimumDifference(TreeNode *root) {
    int minDiff = INT_MAX;
    vector<int> nodes;
    inorderTraversal(root, nodes);
    for (int i = 1; i < nodes.size(); ++i)
      minDiff = min(minDiff, nodes[i] - nodes[i - 1]);
    return minDiff;
  }
};

int main() {
  vector<int> arr = {1, -1, 3, 2, -1};
  TreeNode *root = (TreeNode *)vecToBTree(arr);
  printf("%d", Solution::getMinimumDifference(root));
}
