/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // Count of each value should be even, except for at most 1.
    // Same as checking bit representation is a power of 2.
    // Use Kernighan's identity n&(n-1) removes the rightmost set bit.
    void dfs(TreeNode* node, unsigned int &rep, int &ans) {
        rep ^= 1 << node->val;
        if (!node->left && !node->right && !(rep&(rep-1))) ++ans;
        if (node->left) dfs(node->left, rep, ans);
        if (node->right) dfs(node->right, rep, ans);
        rep ^= 1 << node->val;
    }
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        unsigned int rep = 0;
        int ans = 0;
        dfs(root, rep, ans);
        return ans;
    }
};