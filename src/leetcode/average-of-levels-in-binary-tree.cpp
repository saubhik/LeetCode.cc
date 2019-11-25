//
// Created by saubhik on 2019/11/24.
//
#include "../utils/btree/bTreeUtils.h"
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // 90.76% run-time, 88.89% memory
  // using DFS, O(n) time, O(h) space.
  static vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    vector<int> count;
    dfs(root, ans, count, 0);
    for (int i = 0; i < ans.size(); ++i)
      ans[i] /= count[i];
    return ans;
  }

  static void dfs(TreeNode *root, vector<double> &ans, vector<int> &count,
                  int level) {
    if (!root)
      return;

    if (ans.size() < level + 1) {
      ans.push_back(root->val);
      count.push_back(1);
    } else {
      ans[level] += root->val;
      count[level] += 1;
    }

    dfs(root->left, ans, count, level + 1);
    dfs(root->right, ans, count, level + 1);
  }
};

class Solution2 {
public:
  // using BFS
  static vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      double levelSum = 0;
      int levelSize = q.size();
      for (int i = 0; i < levelSize; ++i) {
        auto node = q.front();
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
        q.pop();
        levelSum += node->val;
      }
      ans.push_back(levelSum / levelSize);
    }
    return ans;
  }
};

class Solution3 {
public:
  // 98.44% run-time, 77.78% memory
  // using BFS, but with nullptr to separate levels
  // nullptr is used like a sentinel
  static vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);

    double levelSum = 0;
    int levelSize = 0;

    while (!q.empty()) {
      auto node = q.front();

      if (node) {
        levelSum += node->val;
        ++levelSize;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      } else {
        ans.push_back(levelSum / levelSize);
        levelSum = 0;
        levelSize = 0;
        if (q.size() > 1)
          q.push(nullptr);
      }

      q.pop();
    }

    return ans;
  }
};

int main() {
  vector<int> nodes = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root = (TreeNode *)vecToBTree(nodes);

  auto ans = Solution::averageOfLevels(root);
  for (auto elem : ans)
    printf("%f ", elem);

  printf("\n");

  ans = Solution2::averageOfLevels(root);
  for (auto elem : ans)
    printf("%f ", elem);

  printf("\n");

  ans = Solution3::averageOfLevels(root);
  for (auto elem : ans)
    printf("%f ", elem);
}
