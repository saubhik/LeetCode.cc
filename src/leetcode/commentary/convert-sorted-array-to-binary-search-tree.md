# Convert Sorted Array to BST

We are given a sorted array. Example: $[-10, -3, 0, 5, 9]$. We need to convert it to height-balanced BST.

One way is to take the mid element as the root, and recursively construct the left & right sub-trees from the left and right sub-arrays respectively.

For the example above, $mid=2$. So $0$ is our root. The mid of the left sub-array is $-3$, which becomes our root for the left sub-tree. Notice that we took the definition of mid as `mid = hi - (hi - lo) / 2`. The mid of the right sub-array is $9$, which becomes our root for the right sub-tree. We can implement this logic recursively to solve the problem.

This algorithm is linear time, $O(depth) = O(lg(n))$ space. The space is due to the recursion stack.

This is going to be height balanced. If it is not, then for some node, the left subtree and the right subtree differ by more than 1 in terms of depth. If we take the inorder traversal of this tree rooted at the node, then we will find that the root is not one of the middle elements of the sorted array. Contradicts our construction.

Also this will be a BST because the left subtree is always smaller or equal to root which is smaller or equal to right subtree, since array is sorted.