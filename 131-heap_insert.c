#include "binary_trees.h"
#define QUEUE_SIZE 40

/**
 * bubble_up - bubbles up a node
 * @node: Is a pointer to the node to bubble up
 * Return: is a pointer to the new posistion of
 * the bubbled node
 */

heap_t *bubble_up(heap_t *node)
{
	int temp;

	while (node && node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - inserts a value in max binary heap
 * @root: is a double pointer to the root node of the heap
 * @value: is the value to store
 * Return: is a pointer to the new node or NUll if if
 * fails
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *Queue[QUEUE_SIZE], *current, *new;
	int start = 0, end = 0;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		if (*root == NULL)
			return (NULL);
		return (*root);
	}
	Queue[end] = *root;
	end = (end + 1) % QUEUE_SIZE;
	while (start != end)
	{
		current = Queue[start];
		start = (start + 1) % QUEUE_SIZE;

		if (current)
		{
			if (!current->left || !current->right)
			{
				new = binary_tree_node(current, value);
				if (new == NULL)
					return (NULL);
				if (!current->left)
					current->left = new;
				else
					current->right = new;
				return (bubble_up(new));
			}
			Queue[end] = current->left;
			end = (end + 1) % QUEUE_SIZE;
			Queue[end] = current->right;
			end = (end + 1) % QUEUE_SIZE;
		}
	}
	return (NULL);
}
