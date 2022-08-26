#include "binary_trees.h"
#include "limits.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) >= 0 ? (a) : (-a))

/**
 * _binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * Return: is the height of the tree or 0 if the tree param is NULL
 */
int _binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + MAX(_binary_tree_height(tree->left),
						 _binary_tree_height(tree->right)));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: is a pointer to the rot node of the tree to measure the balance
 * factor
 * Return: is the balance factor of the tree or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (_binary_tree_height(tree->left) -
			  _binary_tree_height(tree->right));
}

/**
 * _binary_tree_is_avl - checks if a binary_tree_is_a_valid avl tree
 * @tree: is a pointer to the root node of the tree
 * @min: is the allowed minimum value for the node
 * @max: is the allowed maximum value for the node
 * Return: is 1 if the tree is avl else 0
 */

int _binary_tree_is_avl(const binary_tree_t *tree, int min, int max)
{
	int balance_factor;

	if (tree == NULL)
		return (1);

	balance_factor = ABS(binary_tree_balance(tree));
	if (tree->n >= min && tree->n <= max && balance_factor < 2)
		return (_binary_tree_is_avl(tree->left, min, tree->n - 1) &&
				  _binary_tree_is_avl(tree->right, tree->n + 1, max));
	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary_tree_is_a_valid avl tree
 * @tree: is a pointer to the root node of the tree
 * Return: is 1 if the tree is avl else 0
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (_binary_tree_is_avl(tree, INT_MIN, INT_MAX));
}
