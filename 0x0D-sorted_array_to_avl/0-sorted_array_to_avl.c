#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from sorted array without rotation
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL if failed
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (array == NULL || size < 1)
		return (NULL);

	tree = add_node_avl(array, size, &tree, 1);
	if (tree == NULL)
	{
		free_avl(&tree);
		return (NULL);
	}

	return (tree);
}


/**
 * add_node_avl - builds tree from sorted array, adding nodes recursively
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * @tree: double pointer to AVL tree
 * @add_left: flag to indicate if the new node will be a left child
 *
 * Return: pointer to root node of AVL tree, or NULL if failed
 */
avl_t *add_node_avl(int *array, size_t size, avl_t **tree, int add_left)
{
	size_t halfway = (size - 1) / 2;
	avl_t *new_node = NULL, *check = NULL;

	if (array == NULL || size < 1)
		return (*tree);

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = array[halfway];
	new_node->parent = (*tree);
	new_node->left = NULL;
	new_node->right = NULL;

	if ((*tree) == NULL)
		(*tree) = new_node;
	else if (add_left)
		(*tree)->left = new_node;
	else
		(*tree)->right = new_node;

	check = add_node_avl(array, halfway, &new_node, 1);
	if (check == NULL)
		return (NULL);

	halfway++;
	check = add_node_avl(&array[halfway], size - halfway, &new_node, 0);
	if (check == NULL)
		return (NULL);

	return (*tree);
}

/**
 * free_avl - frees AVL tree if later node creation failed
 *
 * @tree: double pointer to AVL tree
 *
 */
void free_avl(avl_t **tree)
{
	avl_t *left = NULL, *right = NULL;

	if (tree == NULL)
		return;

	left = (*tree)->left;
	right = (*tree)->right;

	free((*tree)->parent);
	free((*tree)->right);
	free((*tree)->left);
	free(*tree);

	free_avl(&left);
	free_avl(&right);
}
