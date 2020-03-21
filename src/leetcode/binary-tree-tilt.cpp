//
// Created by saubhik on 2020/03/21.
//
#include "../utils/btree/bTreeUtils.h"
#include <unordered_map>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  static void populateTreeSum(TreeNode *root,
                              std::unordered_map<TreeNode *, int> &treeSum) {
    if (!root)
      return;

    populateTreeSum(root->left, treeSum);
    populateTreeSum(root->right, treeSum);

    treeSum[root] = root->val;
    if (root->left)
      treeSum[root] += treeSum[root->left];
    if (root->right)
      treeSum[root] += treeSum[root->right];
  }

  static void getTilt(TreeNode *root, int &tilt,
                      std::unordered_map<TreeNode *, int> &treeSum) {
    if (!root)
      return;

    if (root->left && root->right)
      tilt += abs(treeSum[root->left] - treeSum[root->right]);
    else if (root->left)
      tilt += abs(treeSum[root->left]);
    else if (root->right)
      tilt += abs(treeSum[root->right]);

    getTilt(root->left, tilt, treeSum);
    getTilt(root->right, tilt, treeSum);
  }

public:
  // Runtime: 32 ms, faster than 17.95% of C++ online submissions for Binary
  // Tree Tilt. Memory Usage: 24.1 MB, less than 33.33% of C++ online
  // submissions for Binary Tree Tilt.
  //
  // O(n) time, O(n) space.
  static int findTilt(TreeNode *root) {
    int tilt = 0;
    std::unordered_map<TreeNode *, int> treeSum;
    populateTreeSum(root, treeSum);
    getTilt(root, tilt, treeSum);
    return tilt;
  }
};

class Solution2 {
private:
  static int dfs(TreeNode *root, int &tilt) {
    if (!root)
      return 0;
    int left = dfs(root->left, tilt);
    int right = dfs(root->right, tilt);
    tilt += abs(left - right);
    return left + right + root->val;
  }

public:
  // Runtime: 16 ms, faster than 92.29% of C++ online submissions for Binary
  // Tree Tilt. Memory Usage: 19.4 MB, less than 100.00% of C++ online
  // submissions for Binary Tree Tilt.
  //
  // O(n) time, O(n) space.
  // no need for extra storage to store tree sums.
  static int findTilt(TreeNode *root) {
    int tilt = 0;
    dfs(root, tilt);
    return tilt;
  }
};

int main() {
  std::vector<int> nodes = {1, 2, 3};
  auto root = (TreeNode *)vecToBTree(nodes);
  assert(Solution::findTilt(root) == 1);
  assert(Solution2::findTilt(root) == 1);

  nodes = {1, 2, 5, 3, 4, 6, 7};
  root = (TreeNode *)vecToBTree(nodes);
  assert(Solution::findTilt(root) == 11);
  assert(Solution2::findTilt(root) == 11);
}
