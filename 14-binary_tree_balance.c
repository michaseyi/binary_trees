#include "binary_trees.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * _binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * Return: is the height of the tree or 0 if the tree param is NULL
 */

int _binary_tree_height(const binary_tree_t *tree)
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

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: is a pointer to the rot node of the tree to measure the balance
 * factor
 * Return: is the balance factor of the tree or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)binary_tree_height(tree->left) -
			  (int)binary_tree_height(tree->right));
}
