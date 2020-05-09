#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree
{
	int value;
	struct BinaryTree *left;
	struct BinaryTree *right;
	struct BinaryTree *parent;
}BinaryTree;

BinaryTree *CreateBinaryTree(int value);
void ClearBinaryTree(BinaryTree *tree);

BinaryTree *JoinTree(BinaryTree *left, BinaryTree *right, int indexRoot);
void DisplayBinaryTree(BinaryTree *tree);
int GetBinaryTreeSize(BinaryTree *tree);
#endif