//
// Created by saubhik on 2019/12/02.
//
#include <cstdio>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  // 98.99% run-time, 80.77% memory
  // O(1) time, O(1) space
  static void deleteNode(ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};

class Solution2 {
public:
  // 80.93% run-time, 73.08% memory
  static void deleteNode(ListNode *node) { *node = *node->next; }
};

int main() {
  ListNode *head = new ListNode(4);
  head->next = new ListNode(5);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(9);

  Solution::deleteNode(head->next);

  ListNode *curr = head;
  while (curr) {
    printf("%d ", curr->val);
    curr = curr->next;
  }

  Solution2::deleteNode(head->next);

  printf("\n");

  curr = head;
  while (curr) {
    printf("%d ", curr->val);
    curr = curr->next;
  }
}
