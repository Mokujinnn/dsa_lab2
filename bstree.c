#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

#include "bstree.h"


bstree *bstree_create(char *key, int value)
{
	bstree *node;
	
	node = malloc(sizeof(*node));
	if(node != NULL)
	{
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
	}
	
	return node;
}

void bstree_add(bstree *tree, char *key, int value)
{
	if (tree == NULL)
	{
		return;
	}
	
	bstree *parent, *node;
	
	while (tree != NULL)
	{
		parent = tree;
		if (strcmp(key, tree->key) < 0)
		{
			tree = tree->left;
		}
		else if (strcmp(key, tree->key) > 0)
		{
			tree = tree->right;
		}
		else
		{
			return;
		}
	}
	
	node = bstree_create(key, value);
	if (strcmp(key, parent->key) < 0)
	{
		parent->left = node;
	}
	else
	{
		parent->right = node;
	}
}

bstree *bstree_lookup(bstree *tree, char *key)
{
	while (tree != NULL)
	{
		if (strcmp(key, tree->key) == 0)
		{
			return tree;
		}
		else if (strcmp(key, tree->key) < 0)
		{
			tree = tree->left;
		}
		else
		{
			tree = tree->right;
		}
	}
	return tree;
}

bstree *bstree_delete(bstree *tree, char *key)
{
	
}

bstree *bstree_min(bstree *tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	
	while (tree->left != NULL)
	{
		tree = tree->left;
	}
	return tree;
}

bstree *bstree_max(bstree *tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	
	while (tree->right != NULL)
	{
		tree = tree->right;
	}
	return tree;
}

























