# Best Time to Buy and Sell Stock II

Given an array of stock prices over time. There may be many transactions, but only 1 stock can be held at a time. We need to find the maximum profit.

Example: $[7,1,5,3,6,4]$.

Whenever there is trough, buy, and whenever there is a peak, sell! This is like a greedy strategy but works. If we miss a trough, we lose on profit. So we should sell on every peak and buy on every trough.

For checking a trough or peak, we can use the neighboring numbers and compare.

I got to know about one more very simple solution from LeetCode. LeetCode named it **Simple One Pass**. The idea is to buy and sell whenever we find $prices[i] > prices[i - 1]$. We buy at timepoint $i - 1$, and sell at timepoint $i$. This is more cleaner, but essentially means that we are _only_ buying during _troughs_ and _only_ selling during _peaks_. At other timepoints, but only during the upward rise towards a peak, we are doing _both_, i.e. buying _and_ selling. Might seem impractical, but it solves the problem cleanly, as we do not have transaction fees and what not.