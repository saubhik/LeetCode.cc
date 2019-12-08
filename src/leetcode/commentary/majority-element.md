# Majority Element

Problem: https://leetcode.com/problems/majority-element/

Wow! LeetCode did work hard to provide a good solution. Let's read through.

First, brute force. So I guess the idea is to traverse through the array and for each element, try to find it's count. Must be $O(n^2)$ time, $O(1)$ space algorithm.

Next, hash map. My solution. Keep the counts in a hash map, `unordered_map` in C++. Must be $O(n)$ time, $O(n)$ space algorithm.

Next, sorting. If we sort, the majority element will come in the ${(n/2)}^{th}$ place. Must be $O(nlogn)$ time, $O(1)$ space algorithm.

Next, divide and conquer. This takes $O(nlogn)$ time, and $O(logn)$ space due to the recursion stack.

Next, `Boyer-Moore Voting Algorithm`. We are looking for a suffix $suf$ of `nums` where $suf[0]$ is the majority element in that suffix. We maintain a count, which is incremented whenever we see an instance of our current candidate for majority element and decremented whenever we see anything else. Whenever `count` equals 0, we effectively forget about everything in `nums` up to the current index and consider the current number as the candidate for majority element.

Example: [7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7].

This is like some voodoo shit. We think the first one as the candidate whenever our count becomes 0. I think I got the hang of it. Upto some extent. This is a kind of recursively solving the problem, and throwing out prefixes of the array that we know does not help any more in finding a solution to the problem. Not to mention, this is a a first-class algorithm.

Next, and finally, we have the `bit manipulation` solution. Courtesy: *jianchao-li*.

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bits = 0;
            for (int num : nums) {
                if (num & mask) {
                    bits++;
                }
            }
            if (bits > nums.size() / 2) {
                majority |= mask;
            }
        }
        return majority;
    }
};
```

