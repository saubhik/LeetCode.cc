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
public:
  std::unordered_map<int, std::vector<TreeNode *>> memo;

  // Runtime: 184 ms, faster than 39.45% of C++ online submissions for All
  // Possible Full Binary Trees. Memory Usage: 32.8 MB, less than 50.00% of C++
  // online submissions for All Possible Full Binary Trees.
  //
  // O(2^N) (Catalan number), O(2^N) space.
  std::vector<TreeNode *> allPossibleFBT(int N) {
    if (memo.find(N) != memo.end()) {
      return memo[N];
    }

    std::vector<TreeNode *> trees;

    if (N == 1) {
      trees.emplace_back(new TreeNode(0));
      memo[N] = trees;
      return trees;
    }

    for (int i = 1; i < N; i += 2) {
      std::vector<TreeNode *> lefts = allPossibleFBT(i);
      std::vector<TreeNode *> rights = allPossibleFBT(N - i - 1);
      for (TreeNode *left : lefts) {
        for (TreeNode *right : rights) {
          auto *root = new TreeNode(0);
          root->left = left;
          root->right = right;
          trees.push_back(root);
        }
      }
    }

    memo[N] = trees;
    return trees;
  }
};

int main() {
  std::vector<TreeNode *> trees;
  trees = Solution().allPossibleFBT(7);
  assert(trees.size() == 5);
}
