#include "tree.h"

Tree *CreateTree(char value, Tree *child, Tree *sibling)
//Creer un arbre a  partir des parametres passes.
{
	Tree *tempTree = malloc(sizeof(*tempTree));

	if (tempTree == NULL)
	{
		ChangeColor(color_Red, color_Black);
		printf("ERREUR DANS L'ALLOCATION : l'arbre n'a pas pu etre cree.\n");
		ChangeColor(color_White, color_Black);
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
		ChangeColor(color_Red, color_Black);
		printf("ERREUR : l'arbre est deja vide !\n");
		ChangeColor(color_White, color_Black);
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
//Entree : L'arbre parent, le nouvel premier enfant
//**********************************************************
void InsertFirstChild(Tree *parent, Tree *newChild)
{
    if (parent == NULL)
        return NULL;

    //Si le parent a déjà un child, il devient le sibling du nouveau child
    if (parent->child != NULL)
        newChild->sibling = parent->child;

    parent->child = newChild;
}


int GetTreeSize(Tree *node)
//Renvoie la taille (nombre de noeuds) d'un arbre a  partir du noeud donne en comptant la racine.
{
	if (node == NULL)
	{
		ChangeColor(color_Red, color_Black);
		printf("ERREUR ARBRE VIDE\n");
		ChangeColor(color_White, color_Black);

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

void RemoveFirstChild(Tree *parent)
{
	if (parent == NULL)
	{
		ChangeColor(color_Red, color_Black);
		printf("ERREUR : le parent passe en parametre n'existe pas !\n");
		ChangeColor(color_White, color_Black);
		return NULL;
	}

	Tree *nodeToRemove = parent->child;

	//On commence par faire pointer l'enfant du parent vers l'enfant de l'élément à retirer s'il existe
	if (nodeToRemove->child != NULL)
	{
		parent->child = nodeToRemove->child;
	}
	//Sinon, si l'élément à retirer possède un sibling, ce dernier devient le child du parent et il n'y a rien d'autre à faire
	else if (nodeToRemove->sibling != NULL)
	{
		parent->child = nodeToRemove->sibling;
		nodeToRemove->sibling = NULL;
		nodeToRemove->child = NULL;
		free(nodeToRemove);
		return NULL;
	}
	//S'il n'a ni child ni sibling, on peut l'effacer directement.
	else
	{
		parent->child = NULL;
		nodeToRemove->sibling = NULL;
		nodeToRemove->child = NULL;
		free(nodeToRemove);
		return NULL;
	}

	//On associe maintenant les sibling.
	//Dans l'exemple du main, l'idée est d'après avoir retirer B, faire pointer le sibling de E vers C.
	//On commence par récupérer le noeud vers lequel on veut faire pointer :
	Tree *siblingNode = nodeToRemove;
	while (siblingNode->sibling != NULL)
	{
		siblingNode = siblingNode->sibling;
	}

	//Si ce noeud est différent de l'élément que l'on retire (ie si l'élément qu'on retire a bien au moins un sibling)
	if (siblingNode != nodeToRemove)
	{
		//On récupére le noeud qu'on veut faire pointer :
		Tree *nodeToLink = nodeToRemove->child;

		while (nodeToLink->sibling != NULL)
		{
			nodeToLink = nodeToLink->sibling;
		}

		//On lie les deux noeuds
		nodeToLink->sibling = siblingNode;
	}

	nodeToRemove->sibling = NULL;
	nodeToRemove->child = NULL;
	free(nodeToRemove); //On termine en libèrant la mémoire de l'élément à retirer
}

void RemoveSibling(Tree *node)
{
	if (node == NULL)
	{
		ChangeColor(color_Red, color_Black);
		printf("ERREUR : le noeud passe en parametre n'existe pas !\n");
		ChangeColor(color_White, color_Black);
		return NULL;
	}

	Tree *nodeToRemove = node->sibling;

	if (nodeToRemove == NULL)
	{
		ChangeColor(color_Red, color_Black);
		printf("ERREUR : le noeud passe en parametre n'a pas de sibling !\n");
		ChangeColor(color_White, color_Black);
		return NULL;
	}

	//Si l'élément que l'on retire a un sibling, ce sibling devient le sibling de node.
	if (nodeToRemove->sibling != NULL)
		node->sibling = nodeToRemove->sibling;
	//Sinon, le node n'a juste pas de sibling
	else
		node->sibling = NULL;

	//Si l'élément à retirer n'a pas d'enfant, il n'y a rien d'autre à faire.
	if (nodeToRemove->child == NULL)
	{
		free(nodeToRemove);
		return NULL;
	}
	//Sinon, il faut link le premier enfant de nodeToRemove en tant que sibling du dernier enfant de node.
	else if (node->child == NULL)
	{
		node->child = nodeToRemove->child;
	}
	else
	{
		Tree *nodeToLink = node->child;
		while (nodeToLink->sibling != NULL)
		{
			nodeToLink = nodeToLink->sibling;
		}

		nodeToLink->sibling = nodeToRemove->child;
	}

	free(nodeToRemove);
}

/*
void insertChildToParent(Tree *parent, Tree *newChild, int nPos)
{

}

void lisTreeChild(Tree *pTree)
{

}*/
