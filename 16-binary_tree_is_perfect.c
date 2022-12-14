#include "binary_trees.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * Return: is the height of the tree or 0 if the tree param is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (1 + MAX(binary_tree_height(tree->left),
						 binary_tree_height(tree->right)));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the size
 * Return: is the size of the binary tree or 0 if the tree param is
 * NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * raise_pow - returns the result of base^power
 * @base: base
 * @power: power
 * Return: base^power
 */

size_t raise_pow(int base, int power)
{
	int val = 1;

	while (power)
	{
		val *= base;
		power--;
	}
	return (val);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect else 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t expected_size;

	if (tree == NULL)
		return (0);
	expected_size = raise_pow(2, binary_tree_height(tree) + 1) - 1;
	return (expected_size == binary_tree_size(tree));
}
