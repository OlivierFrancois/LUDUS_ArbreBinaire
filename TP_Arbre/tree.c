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
		return -1000;
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
