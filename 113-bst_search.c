#include "binary_trees.h"

/**
 * bst_search - searches for a value in a bst
 * @tree: is a pointer to the root node of the tree
 * @value: is the value to search in the tree
 * Return: is the node hold the value or NULL if not
 * found
 */

bst_t *bst_search(const bst_t *tree, int value)
{

	bst_t *current = tree;

	while (current)
	{
		if (current->n == value)
			return (current);
		else if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			break;
	}
	return (NULL);
}
