We are given two strings, `A` and `B`.

A *shift on `A`* consists of taking string `A` and moving the leftmost character to the rightmost position. For example, if `A = 'abcde'`, then it will be `'bcdea'` after one shift on `A`. Return `True` if and only if `A` can become `B` after some number of shifts on `A`.

```
Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
```

**Note:**

- `A` and `B` will have length at most `100`.

There is a $O(n^2)$ time brute-force solution which is straight-forward. Now, let's search for a $O(n)$ time efficient solution. The problem with 2-pointer technique is illustrated by this example: `A='aab'` and `B='aba'`. The first elements match for both the pointers, and we increment both of them. Then, we find a dis-match. What should we do next? Suppose our strategy is to only increment the right one. Then, our `l` pointer points to location $1$ of `A` and `r` pointers points to location $2$ of `B`. Since they match, we start renew counting again & increment both pointers. Now `l` points to `A[2]` and `r` points to `B[0]`. They do not match. Increment only pointer `r`. Now they match. Increment both. They match again. Increment again. They match again. Now `count` equals `len(A) == len(B)`. So, we return `true`. But this algorithm might take $O(n^2)$ time in worst case.

Insights: We want to focus on the relative ordering of the letters. Suppose we have $a + 2b = 2a + b$. Then we must have $a=b$. Similary, if we have $a+2b+3c=b+2c+3a$, then $b+c=2a$, and we can have solutions. So this is not a good hashing of the letters.