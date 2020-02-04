//
// Created by saubhik on 2020/02/04.
//
#include "../utils/btree/bTreeUtils.h"
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left{};
  TreeNode *right{};
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  int preVal = 0;
  bool setPreVal = false;

public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum
  // Distance Between BST Nodes. Memory Usage: 11 MB, less than 100.00% of C++
  // online submissions for Minimum Distance Between BST Nodes.
  //
  // DFS. O(n) time, O(h) space.
  int minDiffInBST(TreeNode *node) {
    if (!node)
      return INT_MAX;
    int minDiff = minDiffInBST(node->left);
    if (setPreVal)
      minDiff = min(minDiff, node->val - preVal);
    preVal = node->val, setPreVal = true;
    minDiff = min(minDiff, minDiffInBST(node->right));
    return minDiff;
  }
};

int main() {
  vector<int> arr = {5, 2, 7, 1, 4, -1, -1};
  auto root = (TreeNode *)vecToBTree(arr);
  printf("%d\n", Solution().minDiffInBST(root));
  showBTree(arr);

  printf("\n");

  arr = {96, 12, -1, -1, 13, -1, 52, 29, -1, -1, -1};
  root = (TreeNode *)vecToBTree(arr);
  printf("%d\n", Solution().minDiffInBST(root));
  showBTree(arr);
}
