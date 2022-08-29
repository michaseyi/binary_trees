#include "binary_trees.h"
#include <stdio.h>
#define QUEUE_SIZE 40
#define MAX(a, b) ((b->n) > (a->n) ? (b) : (a))

/**
 * get_last_node - gets the last node in a heap
 * @root: is a pointer to the root node of the heap
 * Return: is a pointer to the last node of the heap
 */

heap_t *get_last_node(heap_t *root)
{
	heap_t *Queue[QUEUE_SIZE], *current = NULL, *last = root;
	int start = 0, end = 0;

	Queue[end] = root;
	end = (end + 1) % QUEUE_SIZE;

	while (start != end)
	{
		current = Queue[start];
		start = (start + 1) % QUEUE_SIZE;

		if (current)
		{
			last = current;
			Queue[end] = current->left;
			end = (end + 1) % QUEUE_SIZE;
			Queue[end] = current->right;
			end = (end + 1) % QUEUE_SIZE;
		}
	}
	return (last);
}

/**
 * swap - swaps the value of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 */

void swap(heap_t *first, heap_t *second)
{
	int temp;

	temp = first->n;
	first->n = second->n;
	second->n = temp;
}

/**
 * bubble_down - bubbles down the root node till the max heap
 * requirement is met
 * @node: is a pointer to the node to bubble down
 */

void bubble_down(heap_t *node)
{
	heap_t *max;

	if (node == NULL)
		return;

	while (node &&
				 ((node->left && (node->n < node->left->n)) ||
					(node->right && (node->n < node->right->n))))
	{

		if (node->left &&
				node->right &&
				node->n < node->left->n &&
				node->n < node->right->n)
		{
			max = MAX(node->left, node->right);
			swap(node, max);
			node = max;
		}

		else if (node->left && node->n < node->left->n)
		{
			swap(node, node->left);
			node = node->left;
		}
		else
		{
			swap(node, node->right);
			node = node->right;
		}
	}
}

/**
 * heap_extract - extracts the root node of a max binary heap
 * @root: is a double pointer to the root node of the heap
 * Return: is the value of the node that was removed
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node;
	int ret;

	if (!root || *root == NULL)
		return (0);

	ret = (*root)->n;
	last_node = get_last_node(*root);
	swap(*root, last_node);

	if (last_node == *root)
	{
		if (last_node)
			free(last_node);
		*root = NULL;
		return (ret);
	}

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);
	bubble_down(*root);
	return (ret);
}
