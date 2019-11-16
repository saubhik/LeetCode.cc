//
// Created by saubhik on 2019/11/16.
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
  // 80.51% run-time, 80.56% memory.
  // O(N^2) time. For every node, I have to find maximum.
  // O(1) space. Not using any additional space.
  static TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    auto left = nums.begin(), right = nums.end();
    auto *root = helper(nums, left, right);
    return root;
  }
  static TreeNode *helper(vector<int> &nums, vector<int>::iterator &left,
                          vector<int>::iterator &right) {
    if (left >= right)
      return nullptr;
    auto it = max_element(left, right);
    auto *root = new TreeNode(*it);
    root->left = helper(nums, left, it);
    root->right = helper(nums, ++it, right);
    return root;
  }
};

class Solution2 {
public:
  // TODO: tomorrow
};

int main() {
  vector<int> nums = {3, 2, 1, 6, 0, 5};
  auto *root = Solution::constructMaximumBinaryTree(nums);
  showBTree((BinTree<int>::Node *)(root));
}