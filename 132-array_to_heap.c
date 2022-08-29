#include "binary_trees.h"

/**
 * array_to_heap - builds a max binary tree from an array
 * @array: is a pointer to the first element fo the array to
 * be converted
 * @size: is the size of the array
 * Return: is a pointer to the root node of the heap or NULL
 * if it fails
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (!heap_insert(&root, array[i]))
			return (NULL);
	}
	return (root);
}
