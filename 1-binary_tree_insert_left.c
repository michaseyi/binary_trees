#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * @parent: is a pointer to the node to insert the left child in
 * @value: is the value to store in the new node
 * Return: is a pointer to the newly created node or NULL if it fails
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	node->parent = parent;
	node->n = value;
	node->right = node->left = NULL;

	if (parent->left == NULL)
		parent->left = node;
	else
	{
		node->left = parent->left;
		parent->left->parent = node;
		parent->left = node;
	}
	return (node);
}
