#include "binary_trees.h"

/**
 * _binary_tree_is_heap - checks if a binary tree is a valid
 * max binary heap
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if the binary tree is valid heap
 */
int _binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if ((!tree->left || tree->n > tree->left->n) &&
		 (!tree->right || tree->n > tree->right->n))
		return (_binary_tree_is_heap(tree->left) &&
				  _binary_tree_is_heap(tree->right));
	return (0);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid
 * max binary heap
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if the binary tree is valid heap
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);
	return (_binary_tree_is_heap(tree));
}
