# Maximize Sum of Array After K Negations

First we sort the array, and then:

1. If we encounter negative numbers, keep negating them one by one.
2. If we encounter 0, drop K to 0, since we can negate it as multiple times.
3. If we encounter positive numbers, then ?

Suppose we have the array `-2, 7` and `K=4`. We can reduce this to the case when `K=0`. Suppose we have the array `-15, 3` and `K=4`. We can make this `15, -3` and `K=0`. Basically, when we have even `K`, we can re-assign the negatives to the smaller absolute values. We must reduce ourselves to the case when we have one negative value, and some remaining `K`. If `K` is even, then make the negative value go to the smallest absolute value number. If `K` is odd, then make the negative value disappear.

We can compare $M$, the number of negative numbers and $K$, the number of inversions to be done.

If $M < K$, then invert the $M$ negative numbers to positives, and then check the parity of $K-M$. If $K - M$ is even, nothing to do. If $K-M$ is odd, then we can invert the smallest non-negative number we have in the array.

The other case where $M \geq K$ is straightforward: just invert the $K$ smallest negatives.

Observe that we do not need a full sort. We can do with a partial sort. But since `A.length` and `K` are in the same order, we can ignore the improvement.