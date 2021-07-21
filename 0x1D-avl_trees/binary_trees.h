#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>

/* STRUCTS AND DEFINITIONS */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
/* typedef for binary tree struct */
typedef struct binary_tree_s binary_tree_t;
/* typedef for AVL tree struct */
typedef struct binary_tree_s avl_t;

/* FUNCTION PROTOTYPES */
/* given function to print binary tree */
void binary_tree_print(const binary_tree_t *tree);
/* function that checks if binary tree is a valid AVL tree */
int binary_tree_is_avl(const binary_tree_t *tree);

#endif
