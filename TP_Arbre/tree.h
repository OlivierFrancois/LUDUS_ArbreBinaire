#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct Tree
{
	int value;
	Tree *sibling;
	Tree *child;
}Tree;

#endif // TREE_H_INCLUDED
