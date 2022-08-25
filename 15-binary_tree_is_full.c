#include "binary_trees.h"

/**
 * _binary_tree_is_full - checks if a binary tree is full
 * @tree: is a  pointer to the root node of the tree to check
 * Return: 1 if the tree is full else 0
 */

int _binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if ((tree->left && tree->right) || (!tree->left && !tree->right))
		return (_binary_tree_is_full(tree->left) &&
				  _binary_tree_is_full(tree->right));
	return (0);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: is a  pointer to the root node of the tree to check
 * Return: 1 if the tree is full else 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (_binary_tree_is_full(tree));
}
