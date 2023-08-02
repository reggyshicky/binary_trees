#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a node as the left child of anoter nod
 * @parent: parent to inset into
 * @value: value to insert in the new node
 * Return: created node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	if (!parent)
		return (NULL);
	newnode = malloc(sizeof(binary_tree_t));

	if (!newnode)
		return (NULL);
	newnode->n = value;
	newnode->parent = parent;
	newnode->right = NULL;
	newnode->left = parent->left;
	parent->left = newnode;

	if (newnode->left)
		newnode->left->parent = newnode;
	return (newnode);
}
