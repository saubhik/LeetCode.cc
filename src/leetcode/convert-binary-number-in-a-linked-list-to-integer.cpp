//
// Created by saubhik on 2019/12/19.
//
#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  // 100%, 0ms run-time; 100%, 8.4MB memory.
  // O(n) time, O(1) additional space.
  static int getDecimalValue(ListNode *head) {
    int ans = 0;
    while (head) {
      ans = 2 * ans + head->val;
      head = head->next;
    }
    return ans;
  }
};

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(0);
  head->next->next = new ListNode(1);
  printf("%d", Solution::getDecimalValue(head));
}
