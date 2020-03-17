#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//Structure d'arbre. Pointe vers le premier enfant (s'il existe) et le frère (s'il existe)
typedef struct Tree
{
	int value;
	struct Tree *sibling;
	struct Tree *child;
}Tree;

extern Tree *CreateTree(char value, Tree *child, Tree *sibling);
extern void ClearTree(Tree *treeToClear);

extern int TreeSize(Tree *node);
extern int TreeHeight(Tree *node);

#endif // TREE_H_INCLUDED
