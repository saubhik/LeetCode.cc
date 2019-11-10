//
// Created by saubhik on 2019/11/10.
//
#include <queue>
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

class Solution1 {
public:
  // using BFS with storing depth in queue.
  // O(|V|) time, O(|V|) space
  // 63.15% time, 5% memory
  static int maxDepth(Node *root) {
    if (!root)
      return 0;
    short depth = 0;
    queue<pair<Node *, short>> q;
    q.emplace(root, 1);
    while (!q.empty()) {
      auto pr = q.front();
      depth = max(depth, pr.second);
      q.pop();
      for (auto child : pr.first->children) {
        q.emplace(child, pr.second + 1);
      }
    }
    return depth;
  }
};

class Solution2 {
public:
  // using DFS
  // O(|V|) time, O(|V|) space
  // space is lesser than BFS solution above
  // as we are not storing depth
  static int maxDepth(Node *root) {
    if (!root)
      return 0;
    int depth = 1;
    for (auto child : root->children) {
      depth = max(depth, 1 + maxDepth(child));
    }
    return depth;
  }
};

int main() {
  Node *root = new Node(1, {new Node(3, {new Node(5, {}), new Node(6, {})}),
                            new Node(2, {}), new Node(4, {})});
  printf("%d\n", Solution1::maxDepth(root));
  printf("%d", Solution2::maxDepth(root));
}