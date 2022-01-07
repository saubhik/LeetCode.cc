// Abusing the given vector<int> as stack<int>
// for constant extra space solution.
class Solution {
 public:
  bool verifyPreorder(vector<int>& preorder) {
    int i = -1;
    int lowerBound = -1;

    for (int node : preorder) {
      if (node < lowerBound) {
        return false;
      }

      while (i >= 0 && node > preorder[i]) {
        lowerBound = preorder[i--];
      }

      preorder[++i] = node;
    }

    return true;
  }
};
