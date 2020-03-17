#include "tree.h"


//**********************************************************
//Description : Création d'un arbre n-aire avec des paramètres
//Entree : L'arbre à créer
//          Son premier enfant
//          Son frère
//          La valeur stockée
//Sortie :
//**********************************************************
tTree *createTree(tTree *pNewChild, tTree *pNewSibling, int nValue) {
    tTree *pTree = malloc(sizeof(*pTree));

	if (pTree == NULL) {
		printf("Erreur d'allocation.\n");
		return NULL;
	}


    pTree->pChild = pNewChild;
    pTree->pSibling = pNewSibling;
    pTree->nData = nValue;

    return pTree;
}

//**********************************************************
//Description : Insertion en tant que premier enfant dans un arbre
//Entree : L'arbre parent
//         Nouveau premier enfant
//Sortie :
//**********************************************************
void insertFirstChildToParent(tTree *pParent, tTree *pNewChild) {
    if (pParent == NULL) {
        return NULL;
    }
    if (pParent->pChild != NULL) {
        pNewChild->pSibling = pParent->pChild;
    }
    pParent->pChild = pNewChild;
}

/*
void insertChildToParent(tTree *pParent, tTree *pNewChild, int nPos);

void removeFirstChildFromParent(*tTree *pParent);
void removeChildFromParent(*tTree *pParent, int nPos);

void clearTree(tTree *pTree);

void listTreeChild(tTree *pTree);
*/

//**********************************************************
//Description : Récupère la taille de l'arbre (le nombre de noeuds)
//Entree : L'arbre
//Sortie : La taille
//**********************************************************
int getSize(tTree *pTree) {
    if (pTree == NULL) {
        return 0;
    }

    int nSize = 1;

    tTree *pCurrentChild;

    //Pour noeud courant, jusqu'à ce que le noeud n'existe pas, aller de frère en frère et compter la taille
    for (pCurrentChild = pTree->pChild ; pCurrentChild != NULL ; pCurrentChild = pCurrentChild->pSibling) {
        nSize += getSize(pCurrentChild);
    }

    return nSize;
}

//**********************************************************
//Description : Récupère la hauteur de l'arbre (la distance entre la racine et le noeud le plus éloigné de la racine)
//Entree : L'arbre
//Sortie : La hauteur
//**********************************************************
int getHeight(tTree *pTree) {
    if (pTree == NULL) {
        return 0;
    }

    int nHeight = 1;
    int nDistanceMax = 0; //la plus grande hauteur stockée parmis les différents frères

    tTree *pCurrentChild;

    //Pour noeud courant, jusqu'à ce que le noeud n'existe pas, aller de frère en frère
    //Evaluer à chaque fois si la hauteur du noeud courant est supérieur à la distance stockée
    for (pCurrentChild = pTree->pChild ; pCurrentChild != NULL ; pCurrentChild = pCurrentChild->pSibling) {
        int nTemp = getHeight(pCurrentChild);
        if (nTemp > nDistanceMax ) {
            nDistanceMax = nTemp;
        }
    }
    nHeight += nDistanceMax;

    return nHeight;
}
