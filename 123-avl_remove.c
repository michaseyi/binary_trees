#include "binary_trees.h"
/**
 * is_balance_avl - checks if a tree is balanced
 * @tree: is a pointer to the root of the tree
 * Return: is 1 if tree is balanced else 0
 */

int is_balance_avl(avl_t *tree)
{
	int balance_factor = binary_tree_balance(tree);

	return (balance_factor >= -1 &&
			  balance_factor <= 1);
}

/**
 * balance_avl - balances an avl tree
 * @tree: is a pointer to the root node of the avl tree
 * Return: is a pointer to the new root node
 */

avl_t *balance_avl(avl_t *tree)
{
	int balance_factor;
	avl_t *next;

	if (tree == NULL)
		return (NULL);

	next = tree->parent;

	balance_factor = -binary_tree_balance(tree);
	if (balance_factor > 1)
		tree = binary_tree_rotate_left(tree);
	else if (balance_factor < -1)
		tree = binary_tree_rotate_right(tree);
	else if (next && !is_balance_avl(tree) && balance_factor < 0 &&
				tree->n > next->n)
		tree = binary_tree_rotate_right(tree);
	else if (next && !is_balance_avl(next) && balance_factor > 0 &&
				tree->n < next->n)
		tree = binary_tree_rotate_left(tree);

	return (tree);
}
/**
 * min_node - finds the min value in a tree
 * @root: is a pointer to the root of the tree
 * Return: is the min value in the tree
 */

int min_node(bst_t *root)
{
	while (root->left)
		root = root->left;
	return (root->n);
}

/**
 * avl_remove - removes a node from a avl tree
 * @root: is a pointer to the root of the bst
 * @value: is the value of the node to be removed
 * Return: is a pointer to the new root of the bst
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;
	int min;

	if (root == NULL)
		return (root);
	if (root->n == value)
	{
		if (!root->left && !root->right)
		{
			free(root);
			root = NULL;
		}
		else if (root->left && !root->right)
		{
			temp = root;
			root->left->parent = root->parent;
			root = root->left;
			free(temp);
		}
		else if (root->right && !root->left)
		{
			temp = root;
			root->right->parent = root->parent;
			root = root->right;
			free(temp);
		} else
		{
			min = min_node(root->right);
			root->n = min;
			root->right = avl_remove(root->right, min);
		}
	} else if (value < root->n)
	{
		root->left = avl_remove(root->left, value);
		!root->left ? root->right = balance_avl(root->right) : NULL;
	} else if (value > root->n)
	{
		root->right = avl_remove(root->right, value);
		!root->right ? root->left = balance_avl(root->left) : NULL;
	} return (balance_avl(root));
}
