#include "tree.h"

Tree *CreateTree(char value, Tree *child, Tree *sibling)
//Creer un arbre a  partir des parametres passes.
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
//Vide l'arbre passe en parametre et libere la memoire de ce dernier.
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
		//Si tempTree possede un frere, on relance la fonction avec ce dernier
		if (tempTree->sibling != NULL)
			ClearTree(tempTree->sibling);

		break; //Permet de sortir de la boucle une fois que l'on est arrive sur un arbre ne psosedant ni frere ni enfant.
	}

	//Vidage de l'arbre
	treeToClear->child = NULL;
	treeToClear->sibling = NULL;
	treeToClear = NULL;

	//Liberation de la memoire
	free(treeToClear);
}


//**********************************************************
//Description : Insertion en tant que premier enfant dans un arbre
//Entree : L'arbre parent
//         Nouveau premier enfant
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
//Renvoie la taille (nombre de noeuds) d'un arbre a  partir du noeud donne en comptant la racine.
{
	if (node == NULL)
	{
		printf("ERREUR ARBRE VIDE\n");
		return -1;
	}

	int count = 1;

	//Boucle recursive. Part du premier enfant du noeud actuel.
	//Si cet enfant existe, on incremente avec la taille de l'arbre partant de cet enfant puis on regarde le frere de cet enfant.
	//Si le frere n'existe pas, on remonte d'un niveau dans l'arbre puis on itere jusqu'a  parcourir tout l'arbre.
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

//**********************************************************
//Description : Inserer un frere à une position dans l'arbre
//Entree : L'arbre
//         Le frere a inserer
//         Position dans l'arbre
//Sortie :
//**********************************************************
void InsertSiblingToParent(Tree *parent, Tree *newSibling, int nPos)
{
    if (parent == NULL)
        return NULL;

    if (nPos > 1)
    {
        int i;
        Tree *currentSibling;

        currentSibling = parent->child;
        for (i=1;i<nPos-1;i++)
        {
            currentSibling = currentSibling->sibling;
        }
        newSibling->sibling = currentSibling->sibling;
        currentSibling->sibling = newSibling;
    }
    else if (nPos == 1)
    {
        InsertFirstChildToParent(parent, newSibling);
    }
}

//**********************************************************
//Description : Enlever le premier enfant de l'arbre
//Entree : L'arbre
//Sortie :
//**********************************************************
void RemoveFirstChildFromParent(Tree *parent)
{
    if (parent == NULL)
        return NULL;

    Tree *firstChild;
    firstChild = parent->child;
    parent->child = firstChild->sibling;

    free(firstChild);
}

//**********************************************************
//Description : Enlever un enfant à une position dans l'arbre
//Entree : L'arbre
//         La position
//Sortie :
//**********************************************************
void RemoveChildFromParent(Tree *parent, int nPos)
{
    if (parent == NULL)
        return NULL;

    if (nPos > 1)
    {
        int i;
        Tree *currentSibling;
        Tree *previousSibling;

        currentSibling = parent->child;
        for (i=1;i<nPos;i++)
        {
            previousSibling = currentSibling;
            currentSibling = currentSibling->sibling;
        }
        previousSibling->sibling = currentSibling->sibling;

        free(currentSibling);

    }
    else if (nPos == 1)
    {
        RemoveFirstChildFromParent(parent);
    }
}
//**********************************************************
//Description : Recherche en profondeur d'une valeur dans l'arbre
//Entree : L'arbre
//         La valeur cherchee
//Sortie : 1 si la valeur a ete trouvee, sinon 0
//**********************************************************
int DepthFirstSearchTree(Tree *tree,char value)
{
    if (tree == NULL)
        return 0;

    int isFound = 0;
    if (tree->value == value)
        isFound = 1;

    Tree *currentChild = tree->child;

    while (currentChild != NULL && !isFound)
    {
        if (currentChild->value == value)
        {
            isFound = 1;
        }
        else
        {
            isFound = DepthFirstSearchTree(currentChild,value);
            currentChild = currentChild->sibling;
        }
    }
    return isFound;
}

//**********************************************************
//Description : Recherche en largeur d'une valeur dans l'arbre
//Entree : L'arbre
//         La valeur cherchee
//Sortie : 1 si la valeur a ete trouvee, sinon 0
//**********************************************************
int BreadthFirstSearchTree(Tree *tree, char value)
{
    int isFound = 0;
    File* file = initialiserFile();
    enfiler(file,tree);
    while (file->first != NULL && !isFound) {
        Tree *noeud = defiler(file);

        /* Visualiser l'ordre
        if (noeud != NULL)
            printf("%c",noeud->value);
        */

        if (noeud->value == value)
            isFound=1;

        if (noeud->sibling != NULL)
            enfiler(file,noeud->sibling);

        if (noeud->child != NULL)
            enfiler(file,noeud->child);
    }

    return isFound;
}

void ListTreeChild(Tree* tree)
//Affiche la valeur de la racine et des enfants
{
	if (tree == NULL)
	{
		printf("ERREUR ARBRE VIDE\n");
		exit(0);
	}
    printf("%c ",tree->value);

	Tree *currentNode = tree->child;
	while (currentNode != NULL)
	{
		ListTreeChild(currentNode);
		currentNode = currentNode->sibling;
	}
}

