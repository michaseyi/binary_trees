#include "binary_trees.h"

/**
 * balance - balances an avl tree
 * @tree: node to start balancing from
 * Return: is a pointer to the root node of the tree
 */

avl_t *balance(avl_t *tree)
{
	int balance_factor;
	avl_t *current = tree, *new_root = tree, *next;

	while (current)
	{
		next = current->parent;
		balance_factor = binary_tree_balance(current);
		if (balance_factor > 1)
			new_root = binary_tree_rotate_right(current);
		else if (balance_factor < -1)
			new_root = binary_tree_rotate_left(current);
		else
		{
			balance_factor = binary_tree_balance(next);
			if ((balance_factor > 1 || balance_factor < -1) &&
				(!current->right || next->n > current->right->n))
				new_root = !current->right
							   ? binary_tree_rotate_right(current)
						   : !current->left
							   ? binary_tree_rotate_left(current)
							   : current;
			else
				new_root = current;
		}

		if (next && next->left == current)
			next->left = new_root;
		else if (next && next->right == current)
			next->right = new_root;
		current = next;
	}
	return (new_root);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: is a double pointer to the root node of the avl tree
 * @value: is the value to be stored
 * Return: is a pointer to the new node or NULL if it fails
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new, *current;

	new = malloc(sizeof(avl_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->left = new->right = new->parent = NULL;
	if (*tree == NULL)
	{
		*tree = new;
		return (new);
	}
	current = *tree;
	while (current)
	{
		if (value < current->n && current->left)
			current = current->left;

		else if (value < current->n)
		{
			current->left = new;
			new->parent = current;
			*tree = balance(current);
			break;
		}
		else if (value > current->n && current->right)
			current = current->right;
		else if (value > current->n)
		{
			current->right = new;
			new->parent = current;
			*tree = balance(current);
			break;
		}
		else
		{
			free(new);
			return (NULL);
		}
	} return (new);
}
