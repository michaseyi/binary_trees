#include "binary_trees.h"

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
   binary_tree_t *node;

   if (parent == NULL)
      return NULL;

   node = malloc(sizeof(binary_tree_t));

   if (node == NULL)
      return NULL;

   node->parent = parent;
   node->n = value;
   node->left = node->right = NULL;
   
   if (parent->right == NULL)
      parent->right = node;
   else
   {
      node->right = parent->right;
      parent->right = node;
   }

   return node;
}