/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
 public:
  Node* lowestCommonAncestor(Node* p, Node* q) {
    unordered_map<Node*, bool> visited;
    while (p && q) {
      if (p == q) return p;
      if (visited[p]) return p;
      if (visited[q]) return q;
      visited[p] = true;
      visited[q] = true;
      p = p->parent;
      q = q->parent;
    }

    Node* t = p ? p : q;
    while (t) {
      if (visited[t]) return t;
      t = t->parent;
    }

    return nullptr;
  }
};
