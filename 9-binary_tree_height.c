#include "binary_trees.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * _binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * Return: is the height of the tree or 0 if the tree param is NULL
 */

size_t _binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (1 + MAX(_binary_tree_height(tree->left),
						 _binary_tree_height(tree->right)));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * Return: is the height of the tree or 0 if the tree param is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (_binary_tree_height(tree));
}
