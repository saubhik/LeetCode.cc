//
// Created by saubhik on 2019/12/12.
//
#include "../utils/btree/bTreeUtils.h"
#include <string>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // 98.45% run-time, 100% memory.
  // O(n) time, O(n) worst-case space.
  static string tree2str(TreeNode *t) {
    string s = "";
    tree2strRec(t, s);
    return s;
  }

private:
  static void tree2strRec(TreeNode *t, string &s) {
    if (!t)
      return;

    s += to_string(t->val);

    if (t->left) {
      s += "(";
      tree2strRec(t->left, s);
      s += ")";
    }

    if (t->right) {
      if (!t->left)
        s += "()";
      s += "(";
      tree2strRec(t->right, s);
      s += ")";
    }
  }
};

int main() {
  vector<int> arr = {1, 2, 3, 4};
  TreeNode *t = (TreeNode *)vecToBTree(arr);
  printf("%s\n", Solution::tree2str(t).c_str());

  arr = {1, 2, 3, -1, 4};
  t = (TreeNode *)vecToBTree(arr);
  printf("%s", Solution::tree2str(t).c_str());
}
