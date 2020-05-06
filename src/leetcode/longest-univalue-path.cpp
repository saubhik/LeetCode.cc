//
// Created by saubhik on 2020/05/06.
//
#include "../utils/btree/bTreeUtils.h"
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  static int helper(TreeNode *root, int &maxPath) {
    if (root == nullptr) {
      return 0;
    }

    int left = helper(root->left, maxPath);
    int right = helper(root->right, maxPath);

    int pathThruRootLeft = 0, pathThruRootRight = 0;
    if (root->left && root->left->val == root->val) {
      pathThruRootLeft += left + 1;
    }
    if (root->right && root->right->val == root->val) {
      pathThruRootRight += right + 1;
    }
    maxPath = max(maxPath, pathThruRootLeft + pathThruRootRight);

    return max(pathThruRootLeft, pathThruRootRight);
  }

public:
  // Runtime: 176 ms, faster than 24.77% of C++ online submissions for Longest
  // Univalue Path. Memory Usage: 72.1 MB, less than 7.14% of C++ online
  // submissions for Longest Univalue Path.
  //
  // O(n) time, O(n) space.
  static int longestUnivaluePath(TreeNode *root) {
    int maxPath = 0;
    helper(root, maxPath);
    return maxPath;
  }
};

int main() {
  vector<int> nodes = {5, 4, 5, 1, 1, -1, 5};
  auto root = (TreeNode *)vecToBTree(nodes);
  assert(Solution::longestUnivaluePath(root) == 2);

  nodes = {2, 3, 6, 3, 3, 8, 2, 5, 3, 3, 3};
  root = (TreeNode *)vecToBTree(nodes);
  assert(Solution::longestUnivaluePath(root) == 4);
}
