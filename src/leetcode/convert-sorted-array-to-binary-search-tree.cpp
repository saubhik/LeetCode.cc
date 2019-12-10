//
// Created by saubhik on 2019/12/09.
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
public:
  // 87.66% run-time, 97.30% memory.
  // O(n) time, O(lgn) space.
  static TreeNode *sortedArrayToBST(vector<int> &nums) {
    return sortedArrayToBSTRec(nums, 0, nums.size() - 1);
  }

private:
  static TreeNode *sortedArrayToBSTRec(vector<int> &nums, int lo, int hi) {
    if (lo > hi)
      return nullptr;

    int mid = hi - (hi - lo) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBSTRec(nums, lo, mid - 1);
    root->right = sortedArrayToBSTRec(nums, mid + 1, hi);
    return root;
  }
};

int main() {
  vector<int> nums = {-10, -3, 0, 5, 9};
  TreeNode *ans = Solution::sortedArrayToBST(nums);
  showBTree((BinTree<int>::Node *)(ans));
}
