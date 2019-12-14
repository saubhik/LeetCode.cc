//
// Created by saubhik on 2019/12/14.
//
#include "../utils/btree/bTreeUtils.h"
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  // 100% run-time (0ms), 100% memory (9.7MB).
  // using recursion.
  static bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q)
      return true;

    if (!p || !q)
      return false;

    if (p->val != q->val)
      return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

class Solution2 {
public:
  // 100% run-time (0ms), 75.00% memory (9.9MB).
  // using iteration.
  static bool isSameTree(TreeNode *p, TreeNode *q) {
    stack<TreeNode *> stP, stQ;
    stP.push(p), stQ.push(q);
    while (!stP.empty() && !stQ.empty()) {
      auto topP = stP.top(), topQ = stQ.top();
      stP.pop(), stQ.pop();

      if (!topP && !topQ)
        continue;

      if (!topP || !topQ || (topP->val != topQ->val))
        return false;

      stP.push(topP->left);
      stQ.push(topQ->left);
      stP.push(topP->right);
      stQ.push(topQ->right);
    }

    return !((stP.empty() && !stQ.empty()) || (!stP.empty() && stQ.empty()));
  }
};

int main() {
  vector<int> arrP, arrQ;

  arrP = {1, 2, 3}, arrQ = {1, 2, 3};
  printf("%d\n", Solution2::isSameTree((TreeNode *)vecToBTree(arrP),
                                       (TreeNode *)vecToBTree(arrQ)));

  arrP = {1, 2}, arrQ = {1, -1, 2};
  printf("%d\n", Solution2::isSameTree((TreeNode *)vecToBTree(arrP),
                                       (TreeNode *)vecToBTree(arrQ)));

  arrP = {1, 2, 1}, arrQ = {1, 1, 2};
  printf("%d", Solution2::isSameTree((TreeNode *)vecToBTree(arrP),
                                     (TreeNode *)vecToBTree(arrQ)));
}
