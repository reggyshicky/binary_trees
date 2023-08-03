#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_is_full - checks whether a tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if full , 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	/*each node in the tree has either 0 or 2 children*/
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (0);
}
