# Minimum Absolute Difference in BST

Given a BST with non-negative values. I need to find the minimum absolute difference between values of any 2 nodes.

I can always find the inorder traversal and then traverse over the sorted array and compare 2 consecutive values, and check the difference and store the minimum of such differences.

Maybe we can make the inorder traversal idea space optimised to only work with the 2 concerned variables.