//
// Created by saubhik on 2020/02/27.
//
#include <vector>

class Solution {
private:
  static bool dfs(int n, std::vector<int> &leftChild,
                  std::vector<int> &rightChild, std::vector<bool> &visited) {
    if (n == -1)
      return true;
    if (visited[n])
      return false;
    visited[n] = true;
    bool leftIsBTree = dfs(leftChild[n], leftChild, rightChild, visited);
    if (!leftIsBTree)
      return false;
    bool rightIsBTree = dfs(rightChild[n], leftChild, rightChild, visited);
    return rightIsBTree;
  }

public:
  // Runtime: 44 ms, faster than 98.19% of C++ online submissions for Validate
  // Binary Tree Nodes. Memory Usage: 11.3 MB, less than 100.00% of C++ online
  // submissions for Validate Binary Tree Nodes.
  //
  // O(n) time, O(n) space.
  static bool validateBinaryTreeNodes(int n, std::vector<int> &leftChild,
                                      std::vector<int> &rightChild) {
    std::vector<bool> visited(n, false);
    bool isBTree = dfs(0, leftChild, rightChild, visited);
    if (!isBTree)
      return false;
    for (bool b : visited)
      if (!b)
        return false;
    return true;
  }
};

int main() {
  std::vector<int> leftChild = {1, -1, 3, -1};
  std::vector<int> rightChild = {2, -1, -1, -1};
  printf("%d\n", Solution::validateBinaryTreeNodes(4, leftChild, rightChild));

  leftChild = {1, -1, 3, 1};
  rightChild = {2, 3, -1, -1};
  printf("%d\n", Solution::validateBinaryTreeNodes(4, leftChild, rightChild));

  leftChild = {1, 0};
  rightChild = {-1, -1};
  printf("%d\n", Solution::validateBinaryTreeNodes(2, leftChild, rightChild));

  leftChild = {1, -1, -1, 4, -1, -1};
  rightChild = {2, -1, -1, 5, -1, -1};
  printf("%d", Solution::validateBinaryTreeNodes(6, leftChild, rightChild));
}