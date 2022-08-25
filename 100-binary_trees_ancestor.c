#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: is a pointer to the lowest common ancestor or NULL if none
 * exists
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
												 const binary_tree_t *second)
{
	binary_tree_t *i, *j;

	for (i = (binary_tree_t *)first; i; i = i->parent)
	{
		for (j = (binary_tree_t *)second; j; j = j->parent)
		{
			if (i == j)
				return (i);
		}
	}
	return (NULL);
}
