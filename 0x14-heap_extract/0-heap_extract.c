#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * function returns the value extracted, replaces with last level-order node,
 * and rebuilds Max Binary Heap, if needed
 *
 * @root: double pointer to the root node of the heap
 *
 * Return: value stored in extracted node, or 0 if failed
 */

int heap_extract(heap_t **root)
{
	int value = 0;
	size_t height = 0, level = 0;
	heap_t *left = NULL, *right = NULL, *last = NULL;

	/* NULL checks */
	if (root == NULL || *root == NULL)
		return (0);

	/* if not NULL, initialize variables with root node info */
	value = (*root)->n;
	left = (*root)->left;
	right = (*root)->right;

	/* find replacement node (last level-order node) */
	height = binary_tree_height(*root);
	for (level = 0; level < height; level++)
	{
		last = find_replacement(*root, level);
		if (last != NULL)
			break;
	}

	/* extract and reset root pointer if only node */
	if (last == *root)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	/* extracts root node and replaces with node found above */
	free(*root);
	if (last->parent->left == last)
		last->parent->left = NULL;
	else if (last->parent->right == last)
		last->parent->right = NULL;
	last->parent = NULL;
	*root = last;
	last->left = left;
	if (left)
		left->parent = last;
	last->right = right;
	if (right)
		right->parent = last;

	/* heapify (swap) to maintain Max Binary Heap */
	return (value);
}

/**
 * binary_tree_height - finds the height of completed binary tree
 * since the tree is completed, tallest on left side
 * @root: pointer to the root node of the tree
 *
 * Return: returns the height of the overall tree
 */

size_t binary_tree_height(heap_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + binary_tree_height(root->left));
}

/**
 * find_replacement - finds first location that does not have a right child
 * the location may be a leaf or only have left child
 * since level-order traversal, finds location of last node for complete tree
 * @root: pointer to the root node of the tree
 * @level: keeps track of the current level in the tree
 *
 * Return: location of last node in level order, which will replace root node
 */

heap_t *find_replacement(heap_t *root, size_t level)
{
	heap_t *location = NULL;

	if (root == NULL)
		return (NULL);
	if (level == 0 && root->right == NULL)
		return (root);
	else if (level == 0)
		return (NULL);
	location = find_replacement(root->left, level - 1);
	if (location != NULL)
		return (location);
	location = find_replacement(root->right, level - 1);
	return (location);
}
