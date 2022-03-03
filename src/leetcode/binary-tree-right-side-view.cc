/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    // bfs with level markers
    if (!root) return {};
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    while (true) {
      TreeNode* n = q.front();
      q.pop();
      if (!n) {
        if (q.empty()) break;
        q.push(nullptr);
        continue;
      }
      if (!q.front()) ans.push_back(n->val);
      if (n->left) q.push(n->left);
      if (n->right) q.push(n->right);
    }
    return ans;
  }
};
