//
// Created by saubhik on 2020/01/19.
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
public:
    // Runtime: 4 ms, faster than 99.48% of C++ online submissions for Diameter of Binary Tree.
    // Memory Usage: 19.7 MB, less than 92.59% of C++ online submissions for Diameter of Binary Tree.
    //
    // O(n) time, O(h) space (due to recursion stack).
    static int diameterOfBinaryTree(TreeNode *root) {
        int diameter = 0;
        getHeight(root, diameter);
        return diameter;
    }

    static int getHeight(TreeNode *root, int &diameter) {
        if (!root)
            return 0;
        int lh = getHeight(root->left, diameter);
        int rh = getHeight(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return max(lh, rh) + 1;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    auto *root = (TreeNode *) vecToBTree(arr);
    printf("%d\n", Solution::diameterOfBinaryTree(root));
}
