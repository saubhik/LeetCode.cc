//
// Created by saubhik on 2019/11/15.
//
#include "printBinTree.h"
#include <queue>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr){};
  explicit ListNode(int x, ListNode *node) : val(x), next(node){};
};

struct BTreeNode {
  int val;
  BTreeNode *left;
  BTreeNode *right;
  explicit BTreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};

BTreeNode *convertLinkListToBTree(ListNode *head) {
  queue<BTreeNode *> q;

  auto *root = new BTreeNode(head->val);
  q.push(root);
  head = head->next;

  while (head) {
    auto top = q.front();
    q.pop();

    if (head->val != -1) {
      top->left = new BTreeNode(head->val);
      q.push(top->left);
    }
    head = head->next;

    if (head) {
      if (head->val != -1) {
        top->right = new BTreeNode(head->val);
        q.push(top->right);
      }
      head = head->next;
    }
  }

  return root;
}

ListNode *vecToLinkList(vector<int> &arr) {
  auto *head = new ListNode(0);
  ListNode *curr = head;
  for (int num : arr) {
    curr->next = new ListNode(num);
    curr = curr->next;
  }
  return head->next;
}

BTreeNode *vecToBTree(vector<int> &arr) {
  return convertLinkListToBTree(vecToLinkList(arr));
}

void showBTree(vector<int> &arr) {
  BinTree<int> bt((BinTree<int>::Node *)(vecToBTree(arr)));
  bt.Dump();
}

void showBTree(BinTree<int>::Node *node) {
  BinTree<int> bt(node);
  bt.Dump();
}

// int main() {
//  vector<int> arr = {10, 12, 15, 25, 30, -1, 36};
//  showBTree(arr);
//}
