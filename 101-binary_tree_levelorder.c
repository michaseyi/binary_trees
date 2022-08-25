#include "binary_trees.h"
#define QUEUE_SIZE 40

/**
 * binary_tree_levelorder - goes through a binary tree using level order
 * traversal
 * @tree: is a pointer to the root node of tree to traverse
 * @func: is a pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *Queue[QUEUE_SIZE], *current;
	int start = 0, end = 0;

	Queue[end] = tree;
	end = (end + 1) % QUEUE_SIZE;

	while (start != end)
	{
		current = Queue[start];
		start = (start + 1) % QUEUE_SIZE;

		if (current)
		{
			func(current->n);
			Queue[end] = current->left;
			end = (end + 1) % QUEUE_SIZE;
			Queue[end] = current->right;
			end = (end + 1) % QUEUE_SIZE;
		}
	}
}

