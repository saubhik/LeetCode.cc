//
// Created by saubhik on 2019/12/18.
//
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  // 98.92%, 4ms run-time; 82.79%, 8.9MB memory.
  // O(m+n) time, O(1) additional space.
  static ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode mgd(0);
    ListNode *tmp = &mgd;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        tmp = tmp->next = l1;
        l1 = l1->next;
      } else {
        tmp = tmp->next = l2;
        l2 = l2->next;
      }
    }
    tmp->next = l1 ? l1 : l2;
    return mgd.next;
  }
};

int main() {
  ListNode *ans, *l1, *l2;

  l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);

  l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  ans = Solution::mergeTwoLists(l1, l2);

  while (ans)
    printf("%d ", ans->val), ans = ans->next;
}
