#include "binary_trees.h"

/**
 * bst_insert - inserts a node in a bst
 * @tree: pointer to the root of the tree
 * @value: value of the new node
 * Return: pointer to the newly created node or NULL if it fails
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *current;

	new = malloc(sizeof(bst_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->left = new->right = new->parent = NULL;
	if (*tree == NULL)
	{
		*tree = new;
		return (new);
	} current = *tree;
	while (current)
	{
		if (value < current->n)
		{
			if (current->left)
				current = current->left;
			else
			{
				current->left = new;
				new->parent = current;
				break;
			}
		} else if (value > current->n)
		{
			if (current->right)
				current = current->right;
			else
			{
				current->right = new;
				new->parent = current;
				break;
			}
		} else
		{
			free(new);
			return (NULL);
		}
	} return (new);
}
