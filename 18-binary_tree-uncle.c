#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: is a pointer to the node to find the uncle
 * Return: is a pointer to the uncle or NULL if none
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grand_parent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	grand_parent = node->parent->parent;

	return (grand_parent->left != node->parent
					? grand_parent->left
					: grand_parent->right);
}
