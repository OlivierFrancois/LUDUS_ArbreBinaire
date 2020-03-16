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

	printf("Construction d'un arbre");
	Tree *tree_I = CreateTree('I', NULL, NULL);
	Tree *tree_H = CreateTree('H', NULL, tree_I);
	Tree *tree_G = CreateTree('G', NULL, tree_H);

	Tree *tree_F = CreateTree('F', tree_G, NULL);

	Tree *tree_E = CreateTree('E', NULL, NULL);
	Tree *tree_D = CreateTree('D', NULL, tree_E);

	Tree *tree_C = CreateTree('C', tree_F, NULL);
	Tree *tree_B = CreateTree('B', tree_D, tree_C);

	Tree *tree_A = CreateTree('A', tree_B, NULL);

	return 0;
}
