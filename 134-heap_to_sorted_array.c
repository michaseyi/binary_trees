#include "binary_trees.h"

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
	return (1 +
			  binary_tree_size(tree->left) +
			  binary_tree_size(tree->right));
}

/**
 * heap_to_sorted_array - converts a binary max heap to a sorted
 * array of integers
 * @heap: is a pointer to the root node of th heap
 * @size: is an address to store the size of the array
 * Return: is a poitner to the new array
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array, i = 0;

	if (heap == NULL || size == NULL)
		return (NULL);
	*size = binary_tree_size((const binary_tree_t *)heap);
	array = malloc(sizeof(int) * *size);
	if (array == NULL)
		return (NULL);

	while (heap)
		array[i++] = heap_extract(&heap);
	return (array);
}
