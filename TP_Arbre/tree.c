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

int TreeSize(Tree *node)
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
		count += TreeSize(currentNode);
		currentNode = currentNode->sibling;
	}

	return count;
}

int TreeHeight(Tree *node)
//Renvoie la hauteur (nombre de noeud séparant la racine du bout de l'arbre), en incluant le noeud actuel (la hauteur d'une feuille est donc 1).
{
	if (node == NULL)
	{
		printf("ERREUR ARBRE VIDE\n");
		return -1;
	}

	int currentHeight = 1; //Hauteur retenue dans ce passage de la fonction.
	int heightMax = 0; //Stockera la plus grande hauteur

	Tree *currentNode = node->child; //On part de l'enfant du noeud donné en paramètre puis on parcours ses frères.
	while (currentNode != NULL)
	{
		int tempHeight = TreeHeight(currentNode); //Appel récursif de la fonction pour aller vers l'enfant du noeud courant.
		//Si la récursivité s'est répétée assez de fois,
		//tempHeight (qui finalement compte le nombre de fois où la fonction arrive à rentrer dans un enfant)
		//contient un nombre plus grand que heightMax puisque heightMax est la hauteur maximale rencontrée jusque là)
		if (tempHeight > heightMax)
			heightMax = tempHeight;

		currentNode = currentNode->sibling; //Passage au frère du noeud
	}

	currentHeight += heightMax; //On incrémente currentHeight avec la valeur de heightMax retenue

	return (currentHeight);
}
