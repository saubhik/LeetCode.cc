//
// Created by saubhik on 2019/11/10.
//
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  // Floyd's fast and slow pointer technique
  // 100% run-time, 100% memory
  static ListNode *middleNode(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
};

int main() {
  ListNode *ans, *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  ans = Solution::middleNode(head);
  printf("%d\n", ans->val);

  head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  ans = Solution::middleNode(head);
  printf("%d\n", ans->val);

  head = new ListNode(1);
  ans = Solution::middleNode(head);
  printf("%d\n", ans->val);

  head = new ListNode(1);
  head->next = new ListNode(2);
  ans = Solution::middleNode(head);
  printf("%d", ans->val);
}