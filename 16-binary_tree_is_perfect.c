#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tee to check
 * Return: 1 if perfect or 0 if not
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/*all levels are completely filled with nodes*/
	/*and leaves nodes are at the same level*/
	int left_perfect = 0;
	int right_perfect = 0;

	if (tree == NULL)
		return (0);
	if (binary_tree_balance(tree) != 0)
		return (0);

	if ((tree->left != NULL) && (tree->right != NULL))
	{
		left_perfect = binary_tree_is_perfect(tree->left);
		right_perfect = binary_tree_is_perfect(tree->right);

		return (left_perfect &&  right_perfect);
	}
	return (1);
}

/**
 * binary_tree_balance - measures balance factor of binary tree
 * @tree: pointer to the root node of tree to be measured
 * Return: balance factor of tree, otherwise 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_height - measures thw height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of th tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_height = 0;
	size_t left_height = 0;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
