#include "tree.h"

Tree *CreateTree(char value, Tree *child, Tree *sibling)
//Créer un arbre à partir des paramètres passés.
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
//Vide l'arbre passé en paramètre et libère la mémoire de ce dernier.
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
		//Si tempTree possède un frère, on relance la fonction avec ce dernier
		if (tempTree->sibling != NULL)
			ClearTree(tempTree->sibling);

		break; //Permet de sortir de la boucle une fois que l'on est arrivé sur un arbre ne psosédant ni frère ni enfant.
	}

	//Vidage de l'arbre
	treeToClear->child = NULL;
	treeToClear->sibling = NULL;
	treeToClear = NULL;

	//Libération de la mémoire
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
//Renvoie la taille (nombre de noeuds) d'un arbre à partir du noeud donné en comptant la racine.
{
	if (node == NULL)
	{
		printf("ERREUR ARBRE VIDE\n");
		return -1;
	}

	int count = 1;

	//Boucle récursive. Part du premier enfant du noeud actuel.
	//Si cet enfant existe, on incrémente avec la taille de l'arbre partant de cet enfant puis on regarde le frère de cet enfant.
	//Si le frère n'existe pas, on remonte d'un niveau dans l'arbre puis on itère jusqu'à parcourir tout l'arbre.
	Tree *currentNode = node->child;
	while (currentNode != NULL)
	{
		count += GetTreeSize(currentNode);
		currentNode = currentNode->sibling;
	}

	return count;
}

//**********************************************************
//Description : R�cup�re la hauteur de l'arbre (la distance entre la racine et le noeud le plus �loign� de la racine)
//Entree : L'arbre
//Sortie : La hauteur
//**********************************************************
int GetTreeHeight(Tree *pTree)
{
    if (pTree == NULL)
        return 0;

    int nHeight = 1;
    int nDistanceMax = 0; //la plus grande hauteur stock�e parmis les diff�rents fr�res

    Tree *currentChild;

    //Pour noeud courant, jusqu'� ce que le noeud n'existe pas, aller de fr�re en fr�re
    //Evaluer � chaque fois si la hauteur du noeud courant est sup�rieur � la distance stock�e
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
