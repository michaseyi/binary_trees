#include "binary_trees.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b));

size_t binary_tree_height(const binary_tree_t *tree)
{

   if (tree == NULL)
      return -1;

   return 1 + MAX(binary_tree_height(tree->left), binary_tree_height(tree->right));
}