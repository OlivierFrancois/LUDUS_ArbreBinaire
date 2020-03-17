#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
	/*
	CREATION D'UN ARBRE AYANT CETTE STRUCTURE :
			 A
		   /   \
		  B     C
		 / \    |
		D   E   F
			  / | \
			 G  H  I
	*/

	printf("___________Constructions d'arbres\n");
	Tree *tree_I = CreateTree('I', NULL, NULL);
	Tree *tree_H = CreateTree('H', NULL, tree_I);
	Tree *tree_G = CreateTree('G', NULL, tree_H);

	Tree *tree_F = CreateTree('F', tree_G, NULL);

	Tree *tree_E = CreateTree('E', NULL, NULL);
	Tree *tree_D = CreateTree('D', NULL, tree_E);

	Tree *tree_C = CreateTree('C', tree_F, NULL);
	Tree *tree_B = CreateTree('B', tree_D, tree_C);

	Tree *tree_A = CreateTree('A', tree_B, NULL);
	printf("Arbres crees !\n");

	printf("\n___________Test de la fonction de taille\n");
	printf("Taille de l'arbre F : %d\n", TreeSize(tree_F));
	printf("Taille de l'arbre A : %d\n", TreeSize(tree_A));
	printf("Taille de l'arbre B : %d\n", TreeSize(tree_B));
	printf("Taille de l'arbre G : %d\n", TreeSize(tree_G));

	printf("\n___________Test de la fonction de hauteur\n");
	printf("Hauteur de l'arbre F : %d\n", TreeHeight(tree_F));
	printf("Hauteur de l'arbre A : %d\n", TreeHeight(tree_A));
	printf("Hauteur de l'arbre B : %d\n", TreeHeight(tree_B));
	printf("Hauteur de l'arbre G : %d\n", TreeHeight(tree_G));

	return 0;
}
