#include "binary_trees.h"

size_t binary_tree_nodes(const binary_tree_t *tree)
{
   if (tree == NULL)
      return 0;

   return (tree->left || tree->right) + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
}