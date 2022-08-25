#include "binary_trees.h"
#include "limits.h"

/**
 * _binary_tree_is_bst - checks if a binary_tree is a valid bst
 * @tree: is a pointer to a bst node
 * @min: is the allowed minimum value for the node
 * @max: is the allowed maximum value for the node
 * Return: 1 if is bst else 0
 */
int _binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n >= min && tree->n <= max)
		return (_binary_tree_is_bst(tree->left, min, tree->n - 1) &&
				_binary_tree_is_bst(tree->right, tree->n + 1, max));
	return (0);
}

/**
 * binary_tree_is_bst - checks if a binary_tree is a valid bst
 * @tree: is a pointer to a bst node
 * Return: 1 if is bst else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (_binary_tree_is_bst(tree, INT_MIN, INT_MAX));
}
