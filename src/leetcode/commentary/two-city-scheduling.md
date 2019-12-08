# Two City Scheduling

Problem: https://leetcode.com/problems/two-city-scheduling

So, I was looking at votrubac's code, and found something new. In his words:

> Actually, we do not need to perfectly sort all cost differences, we just need the biggest savings (to fly to A) to be in the first half of the array. So, we can use the quick select algorithm (`nth_element` in C++) and use the middle of the array as a pivot.

There are many things I do not understand. We do not need to sort the complete array. Yes, I understand it. Once I have found the ${(n/2)}^{th}$ element, I am done. There is no need of the additional knowledge of ordering amongst the first half and the second half of the elements. Super cool!

So now the problem is: how do I find the $k^{th}$ smallest element in an array of numbers?

For this, we use the `nth_element` function in C++. Reference: https://en.cppreference.com/w/cpp/algorithm/nth_element.

Awesomeness.