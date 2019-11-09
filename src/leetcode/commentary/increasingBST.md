# Living with increasingBST
I am trying to solve this problem, and spent a lot of time trying
to think, but I am finding it difficult to contemplate through layers 
of deep recursion.
Part of the cause is due to lack of proper sleep, caused by my 
increasing amount of caffeine intake at work last week.

I found out that I need to keep thinking about it, and I did not want
to use pen and paper, and I am trying to improve my typing, so I will 
try to think louder by typing here. Not to mention it feels very eco
friendly.

#### Understanding the recursion
I have a BST. I need to create an increasing BST, inplace. That means
I have to perform re-linking of the existing nodes.

Consider the tree like this:
```
   5
 /   \
3     6
```
I think it would be a good task to pretty print a tree from some walk
of the tree.

This can be taken as the foundational example for this problem. Any
thing more would be just repetition. Let us build our recursion from
here.

We would like to have this as our output tree:
```
3
 \
  5
   \
    6
```
The first thing that comes to mind is "inorder".
```oclight
void inOrder(TreeNode *root, TreeNode *curr) {
    if (!root)
        return;
    inOrder(root->left, curr);
    curr->left = nullptr;
    curr->right = root;
    curr = curr->right;
    inOrder(root->right, curr);
}
```
Suppose `curr` was initialised with `TreeNode(-1)`, some fake root.
Let's manually run the code for our simple case. Recursion stack:
`inOrder((5), fakeRoot)` gets called.
`inOrder((3), fakeRoot)` gets called.
`inOrder(nullptr, fakeRoot)` gets called and returns back up.
`fakeRoot->right = (3)` and now curr points to `(3)`.
`inOrder(nullptr, fakeRoot)` gets called and returns back up.
We are now in `(5)`'s call. `(3)->right=(5)`, and curr points to `(5)`.
`inOrder((6), (5))` gets called.
`(5)->right=(6)`, and `curr` now points to `(6)`.
So looks fine.

Mind blown by another solution.
Who thinks of this stuff?
Let's break it down.