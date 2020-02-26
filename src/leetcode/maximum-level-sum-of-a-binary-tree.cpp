//
// Created by saubhik on 2020/02/26.
//
#include "../utils/btree/bTreeUtils.h"
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // Runtime: 216 ms, faster than 91.35% of C++ online submissions for Maximum
  // Level Sum of a Binary Tree. Memory Usage: 73.5 MB, less than 100.00% of C++
  // online submissions for Maximum Level Sum of a Binary Tree.
  //
  // O(n) time, O(n) space.
  static int maxLevelSum(TreeNode *root) {
    std::queue<TreeNode *> q;
    q.push(root);
    std::vector<TreeNode *> levelNodes;
    int levelSum, maxLevelSum = INT_MIN, maxLevel = -1, level = 1;
    while (!q.empty()) {
      levelNodes = {};
      while (!q.empty())
        levelNodes.push_back(q.front()), q.pop();
      levelSum = 0;
      for (auto &levelNode : levelNodes) {
        levelSum += levelNode->val;
        if (levelNode->left)
          q.push(levelNode->left);
        if (levelNode->right)
          q.push(levelNode->right);
      }
      if (levelSum > maxLevelSum) {
        maxLevelSum = levelSum;
        maxLevel = level;
      }
      ++level;
    }
    return maxLevel;
  }
};

int main() {
  std::vector<int> arr = {1, 7, 0, 7, -8, -1, -1};
  auto node = (TreeNode *)vecToBTree(arr);
  printf("%d\n", Solution::maxLevelSum(node));
}
