#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: is a pointer to the root node of the tree to count the
 * number of leaves
 * Return: is the number of leaves in the binary tree or 0 if the
 * tree param is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((!tree->right && !tree->left) +
			  binary_tree_leaves(tree->left) +
			  binary_tree_leaves(tree->right));
}
