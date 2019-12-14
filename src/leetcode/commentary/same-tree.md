# Same Tree

We are given 2 binary trees, and we need to return if they are the same.

Recursive solution is straight-forward. But iterative solution requires a bit more thought.

We want to use a stack to simulate the recursion stack. We push the nodes one by one into the stack and keep popping the top from the stack, and check whether the values are equal are not.