I have an array $nums$ of integers. We need to find the maximum possible sum of elements of the array that is divisible by $3$.

For $[3,6,5,1,8]$, it will be $3+6+1+8=18$.

For $[1,2,3,4,4]$, it will be $1+3+4+4=12$.

This appeared in this week's Weekly Contest. And I had to solve it in around 30 minutes, so there was some time pressure. I felt it is a `DP` problem.

Let's think about $1$ iterator. So, what will $dp[i]$ represent?

Some candidates:

1. Maximum possible sum of elements divisible by 3, considering till position $i$ of $nums$? This seems a bit vague.
2. Same *(sub)*problem, considering till <u>and</u> including position $i$ of $nums$?

$$
\begin{align}
dp[i] &= max(dp[i-1] + nums[i], dp[i-2] + nums[i], ..., dp[0] + nums[i]\\
&= max(dp[i-1], dp[i-2], ..., dp[0]) + nums[i]\\
\end{align}
$$

What if we store the max encountered so far in a variable $maxSoFar$?

Then, $dp[i] = maxSoFar + nums[i]$. And update it after that, $maxSoFar \leftarrow max(maxSoFar, dp[i])$.

Indeed, the final $maxSoFar$ is what we are looking for.

Let's try it using one example. Let's take $[1,2,3,4,4]$.

**I just realized I forgot to take care of divisibility by $3$.** The above approach will not work. We cannot reuse $dp[i-k]$ to solve $dp[i]$, with the current interpretation. Because, we do not need the previous sum to be divisible by $3$ to make the sum with $nums[i]$ to be divisible by $3$. We could dig deeper into modulos. We can maintains $3$ DP arrays, $dp0[..], dp1[...], dp2[...]$. 

Actually, we can only store $maxSoFar0, maxSoFar1, maxSoFar2$. Then, we can use the right $maxSoFar$ to add it to $nums[i]$ based on $nums[i] \% 3$. At the end, we will need the final value of $maxSoFar0$.

*Solving for our example:* 

We represent with a tuple $(msf0, msf1, msf2)$.
$$
i=0, nums[i]=1: (0,1,0)\\
i=1, nums[i]=2: (3,1,2)\\
i=2, nums[i]=3: (6,4,5)\\
i=3, nums[i]=4: (9,10,8)\\
i=4, nums[i]=4: (12,13,14)\\
$$
So, our answer is $12$.

Implementing this:

```c++
#include <vector>
using namespace std;

class Solution {
public:
  static int maxSumDivThree(vector<int> &nums) {
    vector<int> dp(3, 0), tmp(3);
    for (auto num : nums) {
      tmp = dp;
      for (auto i : tmp)
        dp[(num + i) % 3] = max(num + i, dp[(num + i) % 3]);
    }
    return dp[0];
  }
};
```

---



