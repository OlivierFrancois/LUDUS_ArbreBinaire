#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

//Structure contenant les arbres
typedef struct Tree
{
	int value;
	Tree *sibling;
	Tree *child;
}Tree;

#endif // TREE_H_INCLUDED