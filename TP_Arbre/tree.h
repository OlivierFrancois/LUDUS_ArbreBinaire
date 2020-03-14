#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
	int value;
	struct Tree *left;
	struct Tree *right;
	struct Tree *parent;
}Tree;

Tree *new_tree(int value);
void free_tree(Tree *tree);
Tree *join_tree(Tree *left, Tree *right, int root);
void display_tree(Tree *tree);
int count_nodes(Tree *tree);
#endif
