#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree)
{
   int depth = 0;

   if (tree == NULL)
      return depth;

   while (tree->parent)
   {
      depth++;
      tree = tree->parent;
   }
   return depth;
}
