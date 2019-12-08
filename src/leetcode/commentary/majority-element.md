# Majority Element

Problem: https://leetcode.com/problems/majority-element/

Wow! LeetCode did work hard to provide a good solution. Let's read through.

First, brute force. So I guess the idea is to traverse through the array and for each element, try to find it's count. Must be $O(n^2)$ time, $O(1)$ space algorithm.

Next, hash map. My solution. Keep the counts in a hash map, `unordered_map` in C++. Must be $O(n)$ time, $O(n)$ space algorithm.

Next, sorting. If we sort, the majority element will come in the ${(n/2)}^{th}$ place. Must be $O(nlogn)$ time, $O(1)$ space algorithm.

Next, divide and conquer. This takes $O(nlogn)$ time, and $O(logn)$ space due to the recursion stack.