#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

/* INCLUDED LIBRARIES */
#include <stddef.h>
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
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

/* FUNCTION PROTOTYPES */

/* Given function to print binary tree */
void binary_tree_print(const binary_tree_t *);

/* Function that extracts the root node of a Max Binary Heap */
int heap_extract(heap_t **root);

#endif /* _BINARY_TREES_H_ */
