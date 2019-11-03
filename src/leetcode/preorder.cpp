//
// Created by saubhik on 2019/11/03.
//

#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Node {
public:
  int val{};
  vector<Node *> children;
  Node() = default;
  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = std::move(_children);
  }
};

class Solution {
public:
  // recursive
  static vector<int> preorder(Node *root) {
    if (!root)
      return {};
    vector<int> tmp, res;
    tmp.push_back(root->val);
    for (auto child : root->children) {
      res = preorder(child);
      tmp.insert(tmp.end(), res.begin(), res.end());
    }
    return tmp;
  }

  // more space-efficient recursive
  // use one vector<int> instead of multiple copies
  static vector<int> preorder2(Node *root) {
    vector<int> ans;
    helper(root, ans);
    return ans;
  }
  static void helper(Node *root, vector<int> &res) {
    if (!root)
      return;
    res.push_back(root->val);
    for (auto child : root->children)
      helper(child, res);
  }

  // iterative
  static vector<int> preorder3(Node *root) {
    if (!root)
      return {};
    vector<int> ans;
    stack<pair<Node *, int>> stk;
    ans.push_back(root->val);
    stk.emplace(root, 0);
    while (!stk.empty()) {
      auto &pr = stk.top();
      if (pr.second == pr.first->children.size()) {
        stk.pop();
      } else {
        auto &child = pr.first->children[pr.second++];
        ans.push_back(child->val);
        stk.emplace(child, 0);
      }
    }
    return ans;
  }
};

int main() {
  Node *root = new Node(1, {new Node(3, {new Node(5, {}), new Node(6, {})}),
                            new Node(2, {}), new Node(4, {})});
  vector<int> res;
  res = Solution::preorder(root);
  for (int elem : res)
    printf("%d ", elem);

  printf("\n");

  res = Solution::preorder2(root);
  for (int elem : res)
    printf("%d ", elem);

  printf("\n");

  res = Solution::preorder3(root);
  for (int elem : res)
    printf("%d ", elem);
}
