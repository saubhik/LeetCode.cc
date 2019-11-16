//
// Created by saubhik on 2019/11/15.
//
#include "../utils/btree/bTreeUtils.h"
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left{};
  TreeNode *right{};
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // 100% run-time, 88.89% memory
  // worst case time: O(N), where N is the number of nodes.
  // worst case space: O(N) (due to recursion stack).
  // most other cases, space complexity is O(N/2) (due to queue), stack is
  // generally O(H) = O(logN).
  static bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    queue<int> leafValSeq;
    dfs(root1, leafValSeq, true);
    return dfs(root2, leafValSeq, false);
  }

  static bool dfs(TreeNode *root, queue<int> &q, bool push) {

    if (!root)
      return true;

    // leaf
    if (!root->left && !root->right) {
      if (push) {
        q.push(root->val);
        return true;
      } else {
        if (q.front() != root->val)
          return false;
        else {
          q.pop();
          return true;
        }
      }
    }

    return dfs(root->left, q, push) && dfs(root->right, q, push);
  }
};

class Solution2 {
public:
  // 100% run-time, 88.89% memory
  // no additional space for comparison
  // only DFS stack, O(H) space.
  // same time complexity as above, O(N).
  static bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    stack<TreeNode *> s1, s2;
    s1.push(root1);
    s2.push(root2);
    while (!s1.empty() && !s2.empty())
      if (dfs(s1) != dfs(s2))
        return false;
    return s1.empty() && s2.empty();
  }
  static int dfs(stack<TreeNode *> &s) {
    while (true) {
      TreeNode *node = s.top();
      s.pop();
      if (!node->left && !node->right)
        return node->val;
      if (node->left)
        s.push(node->left);
      if (node->right)
        s.push(node->right);
    }
  }
};

int main() {
  vector<int> tree1 = {3, 5, 1, 6, 2, 9, 8, -1, -1, 7, 4};
  vector<int> tree2 = {3, 5, 1, 6, 7, 4, 2, -1, -1, -1, -1, -1, -1, 9, 8};
  showBTree(tree1);
  showBTree(tree2);
  auto *root1 = (TreeNode *)vecToBTree(tree1);
  auto *root2 = (TreeNode *)vecToBTree(tree2);
  printf("%d\n", Solution2::leafSimilar(root1, root2));

  tree1 = {1};
  tree2 = {2};
  root1 = (TreeNode *)vecToBTree(tree1);
  root2 = (TreeNode *)vecToBTree(tree2);
  printf("%d", Solution2::leafSimilar(root1, root2));
}
