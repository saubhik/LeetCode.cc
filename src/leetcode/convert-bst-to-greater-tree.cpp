//
// Created by saubhik on 2019/12/12.
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
private:
  int k = 0;

public:
  // 88.92% run-time, 100% memory.
  // O(n) time, O(lgn) avg space, O(n) worst case.
  TreeNode *convertBST(TreeNode *root) {
    if (!root)
      return nullptr;
    convertBST(root->right);
    root->val += k;
    k = root->val;
    convertBST(root->left);
    return root;
  }
};

int main() {
  vector<int> arr = {5, 2, 13};
  TreeNode *ans, *root = (TreeNode *)vecToBTree(arr);
  ans = Solution().convertBST(root);
  showBTree((BinTree<int>::Node *)(ans));
}
