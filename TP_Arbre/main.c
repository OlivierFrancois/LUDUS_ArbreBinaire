#include "binarytree.h"
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
	printf("\n_________________________Fonction n-aire_________________________\n");
	printf("___________Constructions d'arbres\n");
	Tree *tree_I = CreateTree('I', NULL, NULL);
	Tree *tree_H = CreateTree('H', NULL, tree_I);
	Tree *tree_G = CreateTree('G', NULL, tree_H);

	Tree *tree_F = CreateTree('F', NULL, NULL);

	Tree *tree_E = CreateTree('E', NULL, NULL);
	Tree *tree_D = CreateTree('D', NULL, tree_E);

	Tree *tree_C = CreateTree('C', NULL, NULL);
	Tree *tree_B = CreateTree('B', NULL, tree_C);

	Tree *tree_A = CreateTree('A', NULL, NULL);
	printf("Arbres crees !\n");

	printf("\n___________Test de la fonction d'insertion d'enfant\n");
	InsertFirstChildToParent(tree_A, tree_B);
	InsertFirstChildToParent(tree_B, tree_D);
	InsertFirstChildToParent(tree_C, tree_F);
	InsertFirstChildToParent(tree_F, tree_G);


	printf("\n___________Test de la fonction de taille\n");
	printf("Taille de l'arbre F : %d\n", GetTreeSize(tree_F));
	printf("Taille de l'arbre A : %d\n", GetTreeSize(tree_A));
	printf("Taille de l'arbre B : %d\n", GetTreeSize(tree_B));
	printf("Taille de l'arbre G : %d\n", GetTreeSize(tree_G));

	printf("\n___________Test de la fonction de hauteur\n");
	printf("Hauteur de l'arbre F : %d\n", GetTreeHeight(tree_F));
	printf("Hauteur de l'arbre A : %d\n", GetTreeHeight(tree_A));
	printf("Hauteur de l'arbre B : %d\n", GetTreeHeight(tree_B));
	printf("Hauteur de l'arbre G : %d\n", GetTreeHeight(tree_G));

	printf("\n___________Test de la fonction de clear\n");
	printf("Taille de l'arbre A avant clear d'une feuille : %d\n", GetTreeSize(tree_A));
	ClearTree(tree_F);
	printf("Taille de l'arbre A apres clear d'une feuille : %d\n", GetTreeSize(tree_A));


	printf("\n_________________________Fonction Binaire_________________________\n");
	printf("___________Constructions d'arbres et jointure\n");
    BinaryTree *binaryTree = JoinTree(CreateBinaryTree(2), CreateBinaryTree(4), 6);
    printf("Arbres crees !\n\n");

    printf("___________Affichage d'arbres\n");
    DisplayBinaryTree(binaryTree);

    printf("\n___________Test de la fonction de taille\n");
    printf("L'arbre a %d noeuds\n\n", GetBinaryTreeSize(binaryTree));

    printf("\n___________Test de la fonction de clear\n");
    ClearBinaryTree(binaryTree);
    printf("Arbre clear\n");
    
    return 0;
}
