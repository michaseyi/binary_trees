#include "binary_trees.h"
#define QUEUE_SIZE 40

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: is a pointer to the root node of the tree
 * Return: 1 if the tree is complete else 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	node_wrapper_t Queue[QUEUE_SIZE], current, temp;
	int start = 0, end = 0, node_count = -1;

	if (tree == NULL)
		return (0);
	temp.node = tree;
	temp.position = 0;
	Queue[end] = temp;
	end = (end + 1) % QUEUE_SIZE;

	while (start != end)
	{
		current = Queue[start];
		start = (start + 1) % QUEUE_SIZE;
		if (current.node)
		{
			node_count++;
			if (node_count != current.position)
				return (0);
			temp.position = 2 * current.position + 1;
			temp.node = current.node->left;
			Queue[end] = temp;
			end = (end + 1) % QUEUE_SIZE;
			temp.position = 2 * current.position + 2;
			temp.node = current.node->right;
			Queue[end] = temp;
			end = (end + 1) % QUEUE_SIZE;
		}
	}
	return (1);
}

/**
 * _binary_tree_is_heap - checks if a binary tree is a valid
 * max binary heap
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if the binary tree is valid heap
 */
int _binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if ((!tree->left || tree->n > tree->left->n) &&
		 (!tree->right || tree->n > tree->right->n))
		return (_binary_tree_is_heap(tree->left) &&
				  _binary_tree_is_heap(tree->right));
	return (0);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid
 * max binary heap
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if the binary tree is valid heap
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (_binary_tree_is_heap(tree) && binary_tree_is_complete(tree));
}
