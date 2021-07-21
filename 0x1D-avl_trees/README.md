# 0x1D-avl_trees
This interview algorithm project determines if a given binary tree is a valid AVL tree.  An AVL tree is a self-balancing Binary Search Tree where the difference between heights of left and right subtrees cannot be more than one for all nodes.

[Is AVL](/0x1D-avl_trees/0-binary_tree_is_avl.c)
* Write a function in C `int binary_tree_is_avl(const binary_tree_t *tree)` that determines if a binary tree is an AVL tree:
  * `tree` is a pointer to the root node of the tree to check
  * returns 1 if the tree is a valid AVL tree and 0 otherwise
  * if `tree` is `NULL`, return 0
  * AVL Tree is
    * Binary Search Tree
    * difference between heights of left and right subtrees cannot be more than one
    * left and right subtree must also be a binary search tree

### test_files
The [test_files](/0x1D-avl_trees/test_files/) directory contains files used to test the output of the algorithm locally and all given source code, such as the binary tree struct.
