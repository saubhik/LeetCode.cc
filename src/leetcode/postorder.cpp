//
// Created by saubhik on 2019/10/31.
//
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  vector<Node *> children;

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = std::move(_children);
  }
};

class Solution {
public:
  // recursive, O(V) time, O(1) space
  static vector<int> postorder(Node *root) {
    if (root == nullptr)
      return {};
    vector<int> nodes;
    for (auto child : root->children) {
      vector<int> temp = postorder(child);
      nodes.insert(nodes.end(), temp.begin(), temp.end());
    }
    nodes.push_back(root->val);
    return nodes;
  }

  static vector<int> postorderIterative1(Node *root) {
    if (root == nullptr)
      return {};
    stack<Node *> nodes;
    vector<int> res;
    nodes.push(root);
    while (!nodes.empty()) {
      Node *node = nodes.top();
      nodes.pop();
      for (Node *child : node->children)
        nodes.push(child);
      res.push_back(node->val);
    }
    reverse(res.begin(), res.end());
    return res;
  }

  static vector<int> postorderIterative2(Node *root) {
    if (root == nullptr)
      return {};
    stack<pair<Node *, int>> nodes;
    vector<int> res;
    nodes.emplace(root, 0);
    while (!nodes.empty()) {
      auto &pr = nodes.top();
      if (pr.second == pr.first->children.size()) {
        res.push_back(pr.first->val);
        nodes.pop();
      } else {
        nodes.emplace(pr.first->children[pr.second++], 0);
      }
    }
    return res;
  }
};

int main() {
  Node *root = new Node(1, {new Node(3, {new Node(5, {}), new Node(6, {})}),
                            new Node(2, {}), new Node(4, {})});
  vector<int> res = Solution::postorder(root);
  for (auto num : res)
    cout << num << " ";
  cout << "\n";

  res = Solution::postorderIterative1(root);
  for (auto num : res)
    cout << num << " ";
  cout << "\n";

  res = Solution::postorderIterative2(root);
  for (auto num : res)
    cout << num << " ";
}