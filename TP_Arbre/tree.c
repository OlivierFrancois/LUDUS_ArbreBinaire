#include "tree.h"

Tree *CreateTree(char value, Tree *child, Tree *sibling)
//CrÃ©er un arbre Ã  partir des paramÃ¨tres passÃ©s.
{
	Tree *tempTree = malloc(sizeof(*tempTree));

	if (tempTree == NULL)
	{
		printf("ERREUR DANS L'ALLOCATION : l'arbre n'a pas pu etre cree.\n");
		return NULL;
	}

	tempTree->value = value;
	tempTree->child = child;
	tempTree->sibling = sibling;

	return tempTree;
}


void ClearTree(Tree *treeToClear)
//Vide l'arbre passÃ© en paramÃ¨tre et libÃ¨re la mÃ©moire de ce dernier.
{
	if (treeToClear == NULL)
	{
		printf("ERREUR : l'arbre est deja vide !\n");
		return NULL;
	}

	Tree *tempTree = treeToClear;
	//Si un enfant existe, on se place sur ce dernier.
	if (tempTree->child != NULL)
		tempTree = tempTree->child;

	while (tempTree != NULL)
	{
		//Si tempTree possÃ¨de un frÃ¨re, on relance la fonction avec ce dernier
		if (tempTree->sibling != NULL)
			ClearTree(tempTree->sibling);

		break; //Permet de sortir de la boucle une fois que l'on est arrivÃ© sur un arbre ne psosÃ©dant ni frÃ¨re ni enfant.
	}

	//Vidage de l'arbre
	treeToClear->child = NULL;
	treeToClear->sibling = NULL;
	treeToClear = NULL;

	//LibÃ©ration de la mÃ©moire
	free(treeToClear);
}


//**********************************************************
//Description : Insertion en tant que premier enfant dans un arbre
//Entree : L'arbre parent
//         Nouveau premier enfant
//Sortie :
//**********************************************************
void InsertFirstChildToParent(Tree *parent, Tree *newChild)
{
    if (parent == NULL)
        return NULL;

    if (parent->child != NULL)
        newChild->sibling = parent->child;

    parent->child = newChild;
}


int GetTreeSize(Tree *node)
//Renvoie la taille (nombre de noeuds) d'un arbre Ã  partir du noeud donnÃ© en comptant la racine.
{
	if (node == NULL)
	{
		printf("ERREUR ARBRE VIDE\n");
		return -1;
	}

	int count = 1;

	//Boucle rÃ©cursive. Part du premier enfant du noeud actuel.
	//Si cet enfant existe, on incrÃ©mente avec la taille de l'arbre partant de cet enfant puis on regarde le frÃ¨re de cet enfant.
	//Si le frÃ¨re n'existe pas, on remonte d'un niveau dans l'arbre puis on itÃ¨re jusqu'Ã  parcourir tout l'arbre.
	Tree *currentNode = node->child;
	while (currentNode != NULL)
	{
		count += GetTreeSize(currentNode);
		currentNode = currentNode->sibling;
	}

	return count;
}

//**********************************************************
//Description : Récupère la hauteur de l'arbre (la distance entre la racine et le noeud le plus éloigné de la racine)
//Entree : L'arbre
//Sortie : La hauteur
//**********************************************************
int GetTreeHeight(Tree *pTree)
{
    if (pTree == NULL)
        return 0;

    int nHeight = 1;
    int nDistanceMax = 0; //la plus grande hauteur stockée parmis les différents frères

    Tree *currentChild;

    //Pour noeud courant, jusqu'à ce que le noeud n'existe pas, aller de frère en frère
    //Evaluer à chaque fois si la hauteur du noeud courant est supérieur à la distance stockée
    for (currentChild = pTree->child; currentChild != NULL; currentChild = currentChild->sibling)
    {
        int nTemp = GetTreeHeight(currentChild);
        if (nTemp > nDistanceMax )
            nDistanceMax = nTemp;
    }

    nHeight += nDistanceMax;
    return nHeight;
}

/*
void insertChildToParent(Tree *parent, Tree *newChild, int nPos);

void removeFirstChildFromParent(*Tree *parent);
void removeChildFromParent(*Tree *parent, int nPos);

void clearTree(Tree *pTree);

void lisTreeChild(Tree *pTree);
*/
