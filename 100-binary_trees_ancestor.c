#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestorr of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: point to the LCA
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *node1 = (binary_tree_t *)first;
	binary_tree_t *node2 = (binary_tree_t *)second;
	int first_count = 0;
	int second_count = 0;

	while (first != NULL)
	{
		first = first->parent;
		first_count++;
	}
	while (second != NULL)
	{
		second = second->parent;
		second_count++;
	}

	while (first_count > second_count)
	{
		node1 = node1->parent;
		first_count--;
	}
	while (second_count > first_count)
	{
		node2 = node2->parent;
		second_count--;
	}
	while (node1 != node2)
	{
		node1 = node1->parent;
		node2 = node2->parent;
	}
	return (node1);
}
