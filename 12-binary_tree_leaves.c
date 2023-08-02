#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count no of leaves
 * Return: number of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t no_of_leaves = 0;

	if (tree == NULL)
		return (0);
	/*condition that the recursive calls will be looking at*/
	if (tree->left == NULL && tree->right == NULL)
	{
		no_of_leaves++;
	}
	no_of_leaves += binary_tree_leaves(tree->left);
	no_of_leaves += binary_tree_leaves(tree->right);

	return (no_of_leaves);
}
