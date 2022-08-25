#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: is a pointer to the node to measure the depth
 * Return: is the depth of the node in the tree or 0 if the tree
 * param is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;

	if (tree == NULL)
		return (depth);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
