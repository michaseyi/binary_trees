#include "binary_trees.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b));

size_t binary_tree_height(const binary_tree_t *tree)
{

   if (tree == NULL)
      return -1;

   return 1 + MAX(binary_tree_height(tree->left), binary_tree_height(tree->right));
}

size_t binary_tree_size(const binary_tree_t *tree)
{
   if (tree == NULL)
      return 0;
   return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

size_t pow(int base, int power)
{
   int val = 1;

   while (power)
   {
      val *= base;
      power--;
   }
   return val;
}

int binary_tree_is_perfect(const binary_tree_t *tree)
{
   size_t expected_size;

   if (tree == NULL)
      return 0;

   expected_size = pow(2, binary_tree_height(tree) + 1) - 1;
   return expected_size == binary_tree_size(tree);
}
