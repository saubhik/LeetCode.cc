//
// Created by saubhik on 2020/04/05.
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
  std::vector<std::vector<TreeNode *>> memo{21};

public:
  // O(2^N) (Catalan number), O(2^N) space.
  std::vector<TreeNode *> allPossibleFBT(int N) {
    if (!memo[N].empty()) {
      return memo[N];
    }

    if (N == 1)
      return memo[N] = {new TreeNode(0)};

    std::vector<TreeNode *> trees;
    for (int i = 1; i < N; i += 2) {
      for (auto &left : allPossibleFBT(i)) {
        for (auto &right : allPossibleFBT(N - 1 - i)) {
          auto root = new TreeNode(0);
          root->left = left;
          root->right = right;
          trees.push_back(root);
        }
      }
    }

    return memo[N] = trees;
  }
};

int main() {
  std::vector<TreeNode *> trees;
  trees = Solution().allPossibleFBT(7);
  assert(trees.size() == 5);
}
