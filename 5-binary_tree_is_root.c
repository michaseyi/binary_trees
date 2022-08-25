#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a given node is root
 * @node: is a pointer to the node to check
 * Return: 1 if the node is a root, otherwise 0
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	return (node && !node->parent);
}
