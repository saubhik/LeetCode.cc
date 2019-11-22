//
// Created by saubhik on 2019/11/22.
//
#include "../utils/btree/bTreeUtils.h"
#include <stack>
#include <tuple>
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
  // 83.42% run-time, 100% memory
  // O(n) time, O(h) space.
  // Hint: think in terms of l & r bounds whenever there is BST.
  static TreeNode *bstFromPreorder(vector<int> &preorder) {
    stack<tuple<TreeNode *, int, int>> st;
    auto root = new TreeNode(preorder[0]);
    st.emplace(root, INT_MIN, INT_MAX);
    int i = 1, n = preorder.size();
    for (; i < n;) {
      auto tup = st.top();

      auto node = get<0>(tup);
      auto l = get<1>(tup);
      auto r = get<2>(tup);

      if (l < preorder[i] && preorder[i] < r) {
        if (preorder[i] < node->val) {
          node->left = new TreeNode(preorder[i++]);
          st.emplace(node->left, l, node->val);
        } else {
          node->right = new TreeNode(preorder[i++]);
          st.emplace(node->right, node->val, r);
        }
      } else {
        st.pop();
      }
    }
    return root;
  }
};

class Solution2 {
public:
  // recursive, by Lee
  int i = 0;
  TreeNode *bstFromPreorder(vector<int> &A, int bound = INT_MAX) {
    if (i == A.size() || A[i] > bound)
      return NULL;
    TreeNode *root = new TreeNode(A[i++]);
    root->left = bstFromPreorder(A, root->val);
    root->right = bstFromPreorder(A, bound);
    return root;
  }
};

int main() {
  TreeNode *ans;
  vector<int> preOrder = {8, 5, 1, 7, 10, 12};
  ans = Solution::bstFromPreorder(preOrder);
  showBTree((BinTree<int>::Node *)(ans));
}
