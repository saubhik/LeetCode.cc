//
// Created by saubhik on 2019/11/25.
//
#include <cstdio>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  // 98.92% run-time, 77.75% memory
  // O(n) time, O(n) space
  // recursive
  static ListNode *reverseList(ListNode *head) {
    if (!head)
      return nullptr;
    if (!head->next)
      return head;
    auto node = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return node;
  }
};

class Solution2 {
public:
  // 98.92% run-time, 100% memory
  // O(n) time, O(1) space
  // iterative
  static ListNode *reverseList(ListNode *head) {
    ListNode *pre = new ListNode(-1), *curr = head, *tmp;
    pre->next = head;
    while (curr && curr->next) {
      tmp = curr->next->next;
      curr->next->next = pre->next;
      pre->next = curr->next;
      curr->next = tmp;
    }
    return pre->next;
  }
};

class Solution3 {
public:
  // 98.92% run-time, 100% memory
  // O(n) time, O(1) space
  // iterative version 2
  static ListNode *reverseList(ListNode *head) {
    ListNode *pre = nullptr, *tmp;
    while (head) {
      tmp = head->next;
      head->next = pre;
      pre = head;
      head = tmp;
    }
    return pre;
  }
};

int main() {
  ListNode *head = new ListNode(1), *ans;
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ans = Solution::reverseList(head);
  while (ans) {
    printf("%d ", ans->val);
    ans = ans->next;
  }

  printf("\n");

  head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ans = Solution2::reverseList(head);
  while (ans) {
    printf("%d ", ans->val);
    ans = ans->next;
  }

  printf("\n");

  head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ans = Solution3::reverseList(head);
  while (ans) {
    printf("%d ", ans->val);
    ans = ans->next;
  }
}
