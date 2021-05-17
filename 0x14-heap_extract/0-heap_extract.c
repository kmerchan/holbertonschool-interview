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
	for (level = 0; level <= height; level++)
		find_replacement(*root, level, &last);

	/* extract root and replace with found last level order node */
	free_and_replace(root, &left, &right, &last);

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
 * @last: double pointer to current last node,
 * updates while moving through level order
 *
 * Return: location of last node in level order, which will replace root node
 */

void find_replacement(heap_t *root, size_t level, heap_t **last)
{
	if (root == NULL)
		return;
	if (level == 0)
		(*last) = root;
	find_replacement(root->left, level - 1, last);
	find_replacement(root->right, level - 1, last);
}

/**
 * free_and_replace - extracts and frees the root node, then
 * replaces the root of the heap with last level order node
 *
 * @root: double pointer to root node to extract
 * @left: double pointer to root node's left child or NULL
 * @right: double pointer to root node's right child or NULL
 * @last: double pointer to last node from level order traversal
 */

void free_and_replace(heap_t **root, heap_t **left,
		      heap_t **right, heap_t **last)
{
	/* extract and reset root pointer if only node */
	if (*last == *root)
	{
		free(*root);
		*root = NULL;
		*last = NULL;
		return;
	}
	/* extracts root node and replaces with node found above */
	free(*root);
	if ((*last)->parent->left == (*last))
		(*last)->parent->left = NULL;
	else if ((*last)->parent->right == (*last))
		(*last)->parent->right = NULL;
	(*last)->parent = NULL;
	*root = *last;
	if ((*left) != (*last))
		(*last)->left = (*left);
	if (*left)
		(*left)->parent = (*last);
	if ((*right) != (*left))
		(*last)->right = (*right);
	if (*right)
		(*right)->parent = (*last);
}

/**
 * heapify - swaps nodes to maintain Max Binary Heap
 * @root: double pointer to root node of heap
 * @last: double pointer to current node
 * @check: int pointer to flag if need to continue swapping
 */

void heapify(heap_t **root, heap_t **last)
{
	int last_is_left_child = 0;
	heap_t *temp = (*last)->parent, *left = (*last)->left;
	heap_t *right = (*last)->right;

	if (temp->left == (*last))
		last_is_left_child = 1;
	(*last)->parent = temp->parent;
	if (temp->parent == NULL)
		*root = (*last);
	else if (temp->parent->left == temp)
		temp->parent->left = (*last);
	else if (temp->parent->right == temp)
		temp->parent->right = (*last);
	if (left)
		left->parent = temp;
	temp->left = left;
	if (right)
		right->parent = temp;
	temp->right = right;
	if (last_is_left_child)
	{
		(*last)->right = temp->right;
		if (temp->right)
			temp->right->parent = (*last);
		(*last)->left = temp;
		temp->parent = (*last);
	}
	else
	{
		(*last)->left = temp->left;
		if (temp->left)
			temp->left->parent = (*last);
		(*last)->right = temp;
		temp->parent = (*last);
	}
}
