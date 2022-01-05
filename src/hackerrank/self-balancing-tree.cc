/*
 * Balancing in AVL tree with distinct node values.
 * Self-balancing tree.
 */

typedef struct node {
  int val;
  struct node* left;
  struct node* right;
  int ht;
} node;

int updateHt(node* n) {
  if (!n) return -1;
  return n->ht = 1 + max(updateHt(n->left), updateHt(n->right));
}

node* rotateL(node* oldRoot) {
  node* newRoot = oldRoot->right;
  oldRoot->right = newRoot->left;
  newRoot->left = oldRoot;
  updateHt(newRoot);
  return newRoot;
}

node* rotateR(node* oldRoot) {
  node* newRoot = oldRoot->left;
  oldRoot->left = newRoot->right;
  newRoot->right = oldRoot;
  updateHt(newRoot);
  return newRoot;
}

node* insert(node* root, int val) {
  if (!root) {
    root = new node;
    root->val = val;
    root->left = nullptr;
    root->right = nullptr;
    root->ht = 0;
    return root;
  }

  if (root->val < val) {
    root->right = insert(root->right, val);
  } else {
    root->left = insert(root->left, val);
  }

  updateHt(root);

  int bal =
      (root->left ? root->left->ht : -1) - (root->right ? root->right->ht : -1);

  // RR
  if (bal <= -2 && val > root->right->val) {
    root = rotateL(root);
  }

  // LL
  if (bal >= 2 && val < root->left->val) {
    root = rotateR(root);
  }

  // RL
  if (bal <= -2 && val < root->right->val) {
    root->right = rotateR(root->right);
    root = rotateL(root);
  }

  // LR
  if (bal >= 2 && val > root->left->val) {
    root->left = rotateL(root->left);
    root = rotateR(root);
  }

  return root;
}
