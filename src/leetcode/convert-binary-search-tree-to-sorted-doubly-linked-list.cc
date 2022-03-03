/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
 public:
  Node* treeToDoublyList(Node* root) {
    if (!root) return nullptr;

    Node* ht[2];
    dfs(root, ht);

    ht[0]->left = ht[1];
    ht[1]->right = ht[0];

    return ht[0];
  }

 private:
  // Suppose I have already solved the problem in the left
  // and the right subtree. How do I solve it for the
  // current node?
  // This is thinking in a postorder way.
  void dfs(Node* node, Node** ht) {
    Node* lhead = node;
    Node* ltail = node;
    Node* rhead = node;
    Node* rtail = node;
    Node* tmp[2];

    if (node->left) {
      dfs(node->left, tmp);
      lhead = tmp[0];
      ltail = tmp[1];
      ltail->right = node;
      node->left = ltail;
    }
    // Now: lhead<->...<->ltail<->node

    if (node->right) {
      dfs(node->right, tmp);
      rhead = tmp[0];
      rtail = tmp[1];
      node->right = rhead;
      rhead->left = node;
    }

    // Now: lhead<->...<->ltail<->node<->rhead<->...<->rtail
    ht[0] = lhead;
    ht[1] = rtail;
  }
};
