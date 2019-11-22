//
// Created by saubhik on 2019/11/22.
//
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
  static TreeNode *bstFromPreorder(vector<int> &preorder) {
    vector<TreeNode *> ancestors;

    auto sentinel = new TreeNode(INT_MAX);
    sentinel->left = new TreeNode(preorder[0]);

    ancestors.push_back(sentinel);
    ancestors.push_back(sentinel->left);

    int i = 1, n = preorder.size();
    for (; i < n;) {
      auto grandParent = *(ancestors.rbegin() - 1);
      auto parent = *ancestors.rbegin();

      if (preorder[i] < grandParent->val) {
        if (preorder[i] < parent->val) {
          parent->left = new TreeNode(preorder[i++]);
          ancestors.push_back(parent->left);
        } else {
          parent->right = new TreeNode(preorder[i++]);
          ancestors.push_back(parent->right);
        }
      } else {
        ancestors.pop_back();
      }
    }

    return sentinel->left;
  }
};

int main() {
  TreeNode *ans;
  vector<int> preOrder = {8, 5, 1, 7, 10, 12};
  ans = Solution::bstFromPreorder(preOrder);
}
