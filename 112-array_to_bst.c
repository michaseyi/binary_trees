#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary search tree from an array
 * @array: is a pointer to the first element of the array to
 * be converted
 * @size: is the number of element in the array
 * Return: is a pointer to the root of the new Bst or NULL
 * if it fails
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
