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
BinaryTree *JoinTreeFromExistingRoot(BinaryTree *left, BinaryTree *right, BinaryTree *root);
void DisplayBinaryTree(BinaryTree *tree);
int GetBinaryTreeSize(BinaryTree *tree);

void CreateArrayFromBinaryTree(BinaryTree *tree, int arr[], int *i);
void CreateMaxHeap(BinaryTree *tree, int arr[], int n);
int SearchBinaryTree(BinaryTree *tree, int value);
BinaryTree *CreateBinaryTreeFromArray(int arr[], BinaryTree* root, int i, int n);
int GetMaxValue(int arr[], int n);
void InvertPlaceInArray(int arr[], int indexToInvert1, int indexToInvert2);
int SearchIndexOfValue(int arr[], int value, int n);
BinaryTree *GetLastNode(BinaryTree *binaryTree, int value);
void InvertFirstAndLastNodeAndRemoveLastNode(BinaryTree *binaryTree, int arr[], int n);
#endif
