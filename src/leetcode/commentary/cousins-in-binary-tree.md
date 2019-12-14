# Cousins in Binary Tree

We are given a binary tree with unique values, and two nodes and we need to check if those nodes are cousins. This means we need to check if these nodes have the same depth, but have different parents.

One way is to do BFS. Another solution could involve DFS.

Using DFS, the idea is to search for the node, and if found, note its depth and note its parent. How do we note its parent? Maybe in the call to a node's children.

`dfs(node->left, depth, node->val)`

Is it not possible to do recursive DFS with returning the depth and parent?