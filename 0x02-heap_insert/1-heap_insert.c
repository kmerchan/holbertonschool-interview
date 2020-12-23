#include "binary_trees.h"

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
		new = swap_child(root, new);
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

/**
 * swap_child - swaps the new node with its parent
 * @root: double pointer to the root node of the max binary heap
 * @new: recently inserted node to swap
 *
 * Return: pointer to new node after switch
 */
heap_t *swap_child(heap_t **root, heap_t *new)
{
	int left = 0;
	heap_t *temp = new->parent, *temp_r = temp->right, *temp_l = temp->left;

	if (new->parent->left == new)
		left = 1;
	/* set 2 pointers: parent's right */
	new->parent->right = new->right;
	if (new->right)
		new->right->parent = new->parent;
	/* set 2 pointers: parent's left */
	new->parent->left = new->left;
	if (new->left)
		new->left->parent = new->parent;
	/* set 2 pointers: new sibling becomes child */
	if (left)
	{
		new->right = temp_r;
		if (temp_r)
			temp_r->parent = new;
	}
	else
	{
		new->left = temp_l;
		if (temp_l)
			temp_l->parent = new;
	}
	/* set 2 pointers: connection to grandparent */
	new->parent = temp->parent;
	if (temp->parent)
	{
		if (temp->parent->left == temp)
			temp->parent->left = new;
		else
			temp->parent->right = new;
	}
	else
		*root = new;
	/* sets 2 pointers: between new and parent */
	if (left)
		new->left = temp;
	else
		new->right = temp;
	temp->parent = new;
	return (new);
}
