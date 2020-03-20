//
// Created by saubhik on 2020/03/20.
//
#include "../utils/btree/bTreeUtils.h"
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left{};
  TreeNode *right{};
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  static void dfs(TreeNode *root, std::vector<int> &pathSums, int &sum,
                  int &count) {
    if (!root)
      return;

    pathSums.push_back(0);
    for (auto &elem : pathSums) {
      elem += root->val;
      if (elem == sum)
        ++count;
    }

    dfs(root->left, pathSums, sum, count);
    dfs(root->right, pathSums, sum, count);

    pathSums.pop_back();
    for (auto &elem : pathSums)
      elem -= root->val;
  }

public:
  // Runtime: 40 ms, faster than 14.21% of C++ online submissions for Path Sum
  // III. Memory Usage: 12.7 MB, less than 100.00% of C++ online submissions for
  // Path Sum III.
  //
  // O(n^2) time, O(n) space (O(n) due to dfs stack, and O(n) due to pathSums).
  static int pathSum(TreeNode *root, int sum) {
    std::vector<int> pathSums;
    int count = 0;
    dfs(root, pathSums, sum, count);
    return count;
  }
};

int main() {
  std::vector<int> nodes = {10, 5, -3, 3, 2, -1, 11, 3, -2, -1, 1, -1, -1};
  auto root = (TreeNode *)vecToBTree(nodes);
  assert(Solution::pathSum(root, 8) == 3);
};
