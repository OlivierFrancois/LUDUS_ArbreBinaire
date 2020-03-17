#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//Structure d'arbre n-aire
typedef struct tTree {
    struct tTree *pSibling; //Frère
    struct tTree *pChild; //Premier enfant
    int nData;
}tTree;

tTree *createTree(tTree *pNewChild, tTree *pNewSibling, int nValue);

extern void insertFirstChildToParent(tTree *pParent, tTree *pNewChild);
extern void insertChildToParent(tTree *pParent, tTree *pNewChild, int nPos);

extern void removeFirstChildFromParent(tTree *pParent);
extern void removeChildFromParent(tTree *pParent, int nPos);

extern int getSize(tTree *pTree);
extern int getHeight(tTree *pTree);

extern void clearTree(tTree *pTree);

extern void listTreeChild(tTree *pTree);

/*
Recherches largeur et profondeur

depthFirstSearch
breadthFirstSearch

depthFirstSearchChild
breadthFirstSearchChild
*/



#endif // TREE_H_INCLUDED
