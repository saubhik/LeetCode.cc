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
  /* BFS without sorting, O(n) time, O(n) space */
  vector<vector<int>> verticalOrder(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;
    unordered_map<int, vector<int>> mp;
    vector<vector<int>> ans;
    pair<TreeNode*, int> pr;

    if (!root) {
      return ans;
    }

    int col = 0;
    int minCol = INT_MAX;
    int maxCol = INT_MIN;

    q.emplace(root, col);

    while (!q.empty()) {
      pr = q.front();
      root = pr.first;
      col = pr.second;

      q.pop();

      mp[col].push_back(root->val);
      minCol = min(col, minCol);
      maxCol = max(col, maxCol);

      if (root->left) {
        q.emplace(root->left, col - 1);
      }

      if (root->right) {
        q.emplace(root->right, col + 1);
      }
    }

    for (int i = minCol; i <= maxCol; ++i) {
      ans.push_back(mp[i]);
    }

    return ans;
  }
};
