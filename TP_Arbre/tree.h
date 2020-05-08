#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "file.h"

//Structure d'arbre. Pointe vers le premier enfant (s'il existe) et le frère (s'il existe)
typedef struct Tree
{
	char value;
	struct Tree *sibling;
	struct Tree *child;
}Tree;

extern Tree *CreateTree(char value, Tree *child, Tree *sibling);
extern void ClearTree(Tree *treeToClear);

extern void InsertFirstChildToParent(Tree *parent, Tree *newChild);


extern int GetTreeSize(Tree *node);
extern int GetTreeHeight(Tree *tree);

extern void InsertSiblingToParent(Tree *parent, Tree *newSibling, int nPos);
extern void RemoveFirstChildFromParent(Tree *parent);
extern void RemoveChildFromParent(Tree *parent, int nPos);

extern int DepthFirstSearchTree(Tree *tree,char value);
extern int BreadthFirstSearchTree(Tree *tree,char value);

extern void ListTreeChild(Tree *tree);

/*
depthFirstSearchChild
breadthFirstSearchChild

-Fonction de tri et équilibre d'arbre
-Comparaison de tri entre un arbre et un tableau
*/


#endif // TREE_H_INCLUDED
