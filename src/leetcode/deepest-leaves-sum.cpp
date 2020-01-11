//
// Created by saubhik on 2020/01/11.
//
#include "../utils/btree/bTreeUtils.h"
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  // Lee calls this version of BFS as `level-traversal` BFS.
  //
  // Runtime: 40 ms, faster than 96.02% of C++ online submissions for Deepest
  // Leaves Sum. Memory Usage: 32.1 MB, less than 100.00% of C++ online
  // submissions for Deepest Leaves Sum.
  //
  // O(n) time, O(n) space.
  static int deepestLeavesSum(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int ans = 0;
    while (!q.empty()) {
      int levelWidth = q.size();
      ans = 0;
      for (int i = 0; i < levelWidth; ++i) {
        TreeNode *node = q.front();
        q.pop();
        ans += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }
    return ans;
  }
};

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, -1, 6, 7, -1, -1, -1, -1, 8};
  TreeNode *root = (TreeNode *)vecToBTree(arr);
  printf("%d", Solution::deepestLeavesSum(root));
}