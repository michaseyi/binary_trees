#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least child in a binary tree
 * @tree: is a pointer to the root node of the tree to count the number of
 * nodes
 * Return: is the number of nodes with at least 1 child else 0 if the tree
 * param is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((tree->left || tree->right) +
			  binary_tree_nodes(tree->left) +
			  binary_tree_nodes(tree->right));
}
