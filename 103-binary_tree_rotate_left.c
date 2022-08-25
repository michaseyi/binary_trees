#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: is a pointer to the new root of the tree
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	new_root = tree->right;
	new_root->parent = tree->parent;
	tree->parent = new_root;
	tree->right = new_root->left;
	new_root->left = tree;
	return (new_root);
}
