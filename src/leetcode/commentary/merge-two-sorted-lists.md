# Merge Two Sorted Lists

Suppose we have 2 lists. One is `1->2->4` and the other is `1->3->4`. We need to return a merged list. We can use the basic idea of merge sort, maintaining two pointers, one for each list. We will start with an empty list, and return it. This is $O(m+n)$ time algorithm, with $O(1)$ additional space.

If we want to solve this using in-place, then we can do something like this:

```cpp
ListNode* dummy(0);
ListNode* tail = &dummy;
while (l1 && l2) {
  ListNode*& node = l1->val < l2->val ? l1 : l2;
  tmp = tmp->next = node;
  node = node->next;
}
tail->next = l1 ? l1 : l2;
return dummy->next;
```

The beauty of the above solution lies in the fact that we can reference any of the two lists at one step and increment that reference.