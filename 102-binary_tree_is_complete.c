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
