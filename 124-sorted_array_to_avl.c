#include "binary_trees.h"

/**
 * _sorted_array_to_avl - builds an avl tree from an array
 * @array: is a pointer to the first element of the array to be
 * converted
 * @size: is the number of the element in the array
 * @parent: is a pointer to root node of the current node
 * Return: is a pointer to the root of the avl tree
 */
avl_t *_sorted_array_to_avl(int *array, int size, avl_t *parent)
{
	int middle;
	avl_t *node;

	if (size < 1)
		return (NULL);

	middle = (size - 1) / 2;
	node = binary_tree_node(parent, array[middle]);
	if (node == NULL)
		return (NULL);
	node->left = _sorted_array_to_avl(array, middle, node);
	node->right = _sorted_array_to_avl(array + middle + 1,
												  size - middle - 1, node);
	return (node);
}

/**
 * sorted_array_to_avl - builds an avl tree from an array
 * @array: is a pointer to the first element of the array to be
 * converted
 * @size: is the number of the element in the array
 * Return: is a pointer to the root of the avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (_sorted_array_to_avl(array, (int)size, NULL));
}
