#include "tree.h"
#include "file.h"

Tree *CreateTree(char value, Tree *child, Tree *sibling)
//Creer un arbre a� partir des parametres passes.
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

    //Si le parent a d�j� un child, il devient le sibling du nouveau child
    if (parent->child != NULL)
        newChild->sibling = parent->child;

    parent->child = newChild;
}


int GetTreeSize(Tree *node)
//Renvoie la taille (nombre de noeuds) d'un arbre a� partir du noeud donne en comptant la racine.
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
	//Si le frere n'existe pas, on remonte d'un niveau dans l'arbre puis on itere jusqu'a� parcourir tout l'arbre.
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

	//On commence par faire pointer l'enfant du parent vers l'enfant de l'�l�ment � retirer s'il existe
	if (nodeToRemove->child != NULL)
	{
		parent->child = nodeToRemove->child;
	}
	//Sinon, si l'�l�ment � retirer poss�de un sibling, ce dernier devient le child du parent et il n'y a rien d'autre � faire
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
	//Dans l'exemple du main, l'id�e est d'apr�s avoir retirer B, faire pointer le sibling de E vers C.
	//On commence par r�cup�rer le noeud vers lequel on veut faire pointer :
	Tree *siblingNode = nodeToRemove;
	while (siblingNode->sibling != NULL)
	{
		siblingNode = siblingNode->sibling;
	}

	//Si ce noeud est diff�rent de l'�l�ment que l'on retire (ie si l'�l�ment qu'on retire a bien au moins un sibling)
	if (siblingNode != nodeToRemove)
	{
		//On r�cup�re le noeud qu'on veut faire pointer :
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
	free(nodeToRemove); //On termine en lib�rant la m�moire de l'�l�ment � retirer
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

	//Si l'�l�ment que l'on retire a un sibling, ce sibling devient le sibling de node.
	if (nodeToRemove->sibling != NULL)
		node->sibling = nodeToRemove->sibling;
	//Sinon, le node n'a juste pas de sibling
	else
		node->sibling = NULL;

	//Si l'�l�ment � retirer n'a pas d'enfant, il n'y a rien d'autre � faire.
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

//**********************************************************
//Description : Inserer un frere � une position dans l'arbre
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
        InsertFirstChild(parent, newSibling);
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

//**********************************************************
//Description : Binariser un arbre n-aire
//Entree : L'arbre n-aire
//Sortie : Arbre binaire
//**********************************************************
BinaryTree* BinarizeTree(Tree* tree)
{
    if (tree == NULL)
        return 0;

    BinaryTree* binaryTree = CreateBinaryTree(tree->value);
    if (tree->child != NULL)
    {
        binaryTree->left = BinarizeTree(tree->child);
        binaryTree->left->parent = binaryTree;
    }

    if (tree->sibling != NULL)
    {
        binaryTree->right = BinarizeTree(tree->sibling);
        binaryTree->right->parent = binaryTree;
    }

    return binaryTree;
}
