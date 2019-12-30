# Minimum Moves to Equal Array Elements

We have a non-empty integer array of size $n$. We need to find the minimum number of moves required to make all array elements equal. In each move, we can increment $n-1$ elements by $1$.

We do not want to increase the maximum element much. So we take everything else except the maximum in each step. 

$[0,2,2] \rightarrow [1,3,2] \rightarrow [2,3,3] \rightarrow [3,4,3] \rightarrow [4,4,4]$.

Difference between the lowest and the highest elements?

$[0,2,4] \rightarrow [1,3,4] \rightarrow [2,4,4] \rightarrow [3,5,4] \rightarrow [4,5,5] \rightarrow [5,6,5] \rightarrow [6,6,6]$.

$[0,2,3] \rightarrow [1,3,3] \rightarrow [2,3,4] \rightarrow [3,4,4] \rightarrow [4,4,5] \rightarrow [5,5,5]$.

Let's rethink. Some possible things that might be related are differences between the elements. There is obviously the brute force way, but each time working with the entire array (to add $1$ to every element) could be in-efficient. And this would be done as many times as the number of moves.

Looking at the `Discuss` section tells me that it is a math question. So there must be a very clever answer to this problem.

Let's note the insights. Denote by $k$ , the number of moves required.

1. $k$ is atleast the difference between the first & last elements.
2. $k=\sum{a_i} - n\cdot min(a_i)$.

The second insight nails it. Let's apply this to our examples. For $[0,2,3]$, our $k=5-3\cdot 0=5$. For $[0,2,4]$, our $k=6-3\cdot0=6$. For $[0,2,2]$, our $k=4-3\cdot0=4$.

Now, the code is super easy to write.