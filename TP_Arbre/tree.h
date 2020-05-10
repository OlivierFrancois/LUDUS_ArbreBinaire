#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "style.h"

//Structure d'arbre. Pointe vers le premier enfant (s'il existe) et le frère (s'il existe)
typedef struct Tree
{
	int value;
	struct Tree *sibling;
	struct Tree *child;
}Tree;

extern Tree *CreateTree(char value, Tree *child, Tree *sibling);
extern void ClearTree(Tree *treeToClear);

extern void InsertFirstChild(Tree *parent, Tree *newChild);


extern int GetTreeSize(Tree *node);
extern int GetTreeHeight(Tree *tree);

extern void RemoveFirstChild(Tree *parent);
extern void RemoveSibling(Tree *node);
//TO DO
extern void InsertSiblingToParent(Tree *parent, Tree *newSibling, int nPos);
extern void ListTreeChild(Tree *tree);

/*
Recherches largeur et profondeur

depthFirstSearch
breadthFirstSearch

depthFirstSearchChild
breadthFirstSearchChild
*/


#endif // TREE_H_INCLUDED
