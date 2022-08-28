#include "binary_trees.h"

/**
 * array_to_avl - builds a avl tree from an array
 * @array: is a pointer to the first element of the array to
 * be converted
 * @size: is the number of element in the array
 * Return: is a pointer to the root of the new Bst or NULL
 * if it fails
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);
	return (root);
}
