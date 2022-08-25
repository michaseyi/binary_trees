#include "binary_trees.h"

size_t binary_tree_leaves(const binary_tree_t *tree)
{
   if (tree == NULL)
      return 0;

   return (!tree->right && !tree->left) + binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
}