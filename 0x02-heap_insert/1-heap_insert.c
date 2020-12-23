#include "binary_trees.h"

size_t binary_tree_height(heap_t *root);
heap_t *find_location(heap_t *root, size_t level);

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * Max Binary Heap must be complete tree with max as root node
 * @root: a double pointer to the root node of the Heap
 * @value: the value to store in the inserted node
 *
 * Return: pointer to the newly inserted node, or NULL if failed
 */

heap_t *heap_insert(heap_t **root, int value)
{
	size_t level = 0, height = 0;
	heap_t *location = NULL, *new = NULL;
	int temp = 0;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		new = binary_tree_node(*root, value);
		*root = new;
		return (new);
	}
	height = binary_tree_height(*root);
	for (level = 0; level < height; level++)
	{
		location = find_location(*root, level);
		if (location != NULL)
			break;
	}
	new = binary_tree_node(location, value);
	if (!location->left)
		location->left = new;
	else
		location->right = new;
	while (new->parent && new->n > new->parent->n)
	{
		temp = new->parent->n;
		new->parent->n = new->n;
		new->n = temp;
		new = new->parent;
	}
	return (new);
}

/**
 * binary_tree_height - finds the height of completed binary tree
 * since the tree is completed, talled on left side
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
 * find_location - finds first location that does not have a right child
 * the location may be a leaf or only have left child
 * since level-order traversal, will find location to add for complete tree
 * @root: pointer to the root node of the tree
 * @level: keeps track of the current level in the tree
 *
 * Return: location to insert new node off of, or NULL if has two children
 */
heap_t *find_location(heap_t *root, size_t level)
{
	heap_t *location = NULL;

	if (root == NULL)
		return (NULL);
	if (level == 0 && root->right == NULL)
		return (root);
	else if (level == 0)
		return (NULL);
	location = find_location(root->left, level - 1);
	if (location != NULL)
		return (location);
	location = find_location(root->right, level - 1);
	return (location);
}
