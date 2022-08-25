#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: is a pointer to the new root of the tree
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->left == NULL)
		return (NULL);
	new_root = tree->left;
	new_root->parent = tree->parent;
	tree->parent = new_root;
	tree->left = new_root->right;
	new_root->right ? new_root->right->parent = tree : NULL;
	new_root->right = tree;
	return (new_root);
}
