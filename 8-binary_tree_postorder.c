#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using postorder traversal
 * @tree: is a pointer to the root node of the three to traverse
 * @func: is a poitner to a function to call for each node
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
}
