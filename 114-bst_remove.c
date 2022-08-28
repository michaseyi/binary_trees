#include "binary_trees.h"
#include <stdio.h>

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
 * bst_remove - removes a node from a bst
 * @root: is a pointer to the root of the bst
 * @value: is the value of the node to be removed
 * Return: is a pointer to the new root of the bst
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;
	int min;

	if (root == NULL)
		return (root);
	if (root->n == value)
	{
		if (!root->left && !root->right)
		{
			free(root);
			root = NULL;
		} else if (root->left && !root->right)
		{
			temp = root;
			root->left->parent = root->parent;
			root = root->left;
			free(temp);
		} else if (root->right && !root->left)
		{
			temp = root;
			root->right->parent = root->parent;
			root = root->right;
			free(temp);
		} else
		{
			min = min_node(root->right);
			root->n = min;
			root->right = bst_remove(root->right, min);
		}
	}
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	return (root);
}