//
// Created by saubhik on 2020/01/31.
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
private:
  static void inOrder(TreeNode *root, vector<int> &walk) {
    if (!root)
      return;
    inOrder(root->left, walk);
    walk.push_back(root->val);
    inOrder(root->right, walk);
  }

  static vector<int> getInOrderWalk(TreeNode *root) {
    vector<int> walk = {};
    inOrder(root, walk);
    return walk;
  }

  static vector<int> merge(vector<int> &left, vector<int> &right) {
    vector<int> ans(left.size() + right.size());
    auto l = left.begin(), r = right.begin(), a = ans.begin();
    while (l < left.end() && r < right.end()) {
      if (*l < *r)
        *a++ = *l++;
      else
        *a++ = *r++;
    }
    while (l < left.end())
      *a++ = *l++;
    while (r < right.end())
      *a++ = *r++;
    return ans;
  }

public:
  // Runtime: 268 ms, faster than 86.86% of C++ online submissions for All
  // Elements in Two Binary Search Trees. Memory Usage: 58.8 MB, less than
  // 100.00% of C++ online submissions for All Elements in Two Binary Search
  // Trees.
  //
  // O(n1 + n2) time, O(n1 + n2) space; where:
  // n1: number of nodes in tree 1
  // n2: number of nodes in tree 2
  static vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> walk1 = getInOrderWalk(root1), walk2 = getInOrderWalk(root2);
    return merge(walk1, walk2);
  }
};

int main() {
  vector<int> ans, tree1, tree2;
  tree1 = {2, 1, 4}, tree2 = {1, 0, 3};
  auto *root1 = (TreeNode *)vecToBTree(tree1);
  auto *root2 = (TreeNode *)vecToBTree(tree2);
  ans = Solution::getAllElements(root1, root2);
  for (int &num : ans)
    printf("%d ", num);

  printf("\n");

  tree1 = {0, -10, 10}, tree2 = {5, 1, 7, 0, 2};
  root1 = (TreeNode *)vecToBTree(tree1);
  root2 = (TreeNode *)vecToBTree(tree2);
  ans = Solution::getAllElements(root1, root2);
  for (int &num : ans)
    printf("%d ", num);

  printf("\n");

  tree2 = {5, 1, 7, 0, 2};
  root2 = (TreeNode *)vecToBTree(tree2);
  ans = Solution::getAllElements(nullptr, root2);
  for (int &num : ans)
    printf("%d ", num);

  printf("\n");

  tree1 = {0, -10, 10};
  root1 = (TreeNode *)vecToBTree(tree1);
  ans = Solution::getAllElements(root1, nullptr);
  for (int &num : ans)
    printf("%d ", num);

  printf("\n");

  tree1 = {1, -1, 8}, tree2 = {8, 1};
  root1 = (TreeNode *)vecToBTree(tree1);
  root2 = (TreeNode *)vecToBTree(tree2);
  ans = Solution::getAllElements(root1, root2);
  for (int &num : ans)
    printf("%d ", num);
}
