#include "binarytree.h"
#include "tree.h"
#include "style.h"

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
	ChangeColor(color_Blue, color_Black);
	printf("\n_________________________Fonctions n-aire_________________________\n");
	ChangeColor(color_White, color_Black);
	
	ChangeColor(color_Cyan, color_Black);
	printf("___________Constructions d'arbres\n");
	ChangeColor(color_White, color_Black);

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

	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction d'insertion d'enfant\n");
	ChangeColor(color_White, color_Black);

	InsertFirstChildToParent(tree_A, tree_B);
	InsertFirstChildToParent(tree_B, tree_D);
	InsertFirstChildToParent(tree_C, tree_F);
	InsertFirstChildToParent(tree_F, tree_G);
	printf("Done !\n");

	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de retrait d'enfant\n");
	ChangeColor(color_White, color_Black);

	printf("Taille de l'arbre A avant retrait : %d\n", GetTreeSize(tree_A));
	RemoveFirstChild(tree_A);
	printf("Taille de l'arbre A apres suppression du noeud B : %d\n", GetTreeSize(tree_A));
	RemoveFirstChild(tree_F);
	printf("Taille de l'arbre A apres suppression du noeud G : %d\n", GetTreeSize(tree_A));

	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de retrait de sibling\n");
	ChangeColor(color_White, color_Black);

	printf("Taille de l'arbre A avant retrait : %d\n", GetTreeSize(tree_A));
	RemoveSibling(tree_H);
	printf("Taille de l'arbre A apres suppression du sibling de H : %d\n", GetTreeSize(tree_A));
	printf("Suppression d'un sibling inexistant : \n");
	RemoveSibling(tree_C);


	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de taille\n");
	ChangeColor(color_White, color_Black);

	printf("Taille de l'arbre F : %d\n", GetTreeSize(tree_F));
	printf("Taille de l'arbre A : %d\n", GetTreeSize(tree_A));
	printf("Taille de l'arbre G : %d\n", GetTreeSize(tree_G));

	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de hauteur\n");
	ChangeColor(color_White, color_Black);

	printf("Hauteur de l'arbre F : %d\n", GetTreeHeight(tree_F));
	printf("Hauteur de l'arbre A : %d\n", GetTreeHeight(tree_A));
	printf("Hauteur de l'arbre B : %d\n", GetTreeHeight(tree_B));

	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de clear\n");
	ChangeColor(color_White, color_Black);

	printf("Taille de l'arbre A avant clear d'une feuille : %d\n", GetTreeSize(tree_A));
	ClearTree(tree_F);
	printf("Taille de l'arbre A apres clear d'une feuille : %d\n", GetTreeSize(tree_A));

	ChangeColor(color_Blue, color_Black);
	printf("\n_________________________Fonctions Binaire_________________________\n");
	ChangeColor(color_White, color_Black);
	
	ChangeColor(color_Cyan, color_Black);
	printf("___________Constructions d'arbres et jointure\n");
	ChangeColor(color_White, color_Black);

    BinaryTree *binaryTree = JoinTree(CreateBinaryTree(2), CreateBinaryTree(4), 6);
    printf("Arbres crees !\n\n");

    ChangeColor(color_Cyan, color_Black);
    printf("___________Affichage d'arbres\n");
    ChangeColor(color_White, color_Black);

    DisplayBinaryTree(binaryTree);

    ChangeColor(color_Cyan, color_Black);
    printf("\n___________Test de la fonction de taille\n");
    ChangeColor(color_White, color_Black);

    printf("L'arbre a %d noeuds\n\n", GetBinaryTreeSize(binaryTree));

    ChangeColor(color_Cyan, color_Black);
    printf("\n___________Test de la fonction de clear\n");
    ChangeColor(color_White, color_Black);
    
    ClearBinaryTree(binaryTree);
    printf("Arbre clear\n");

    return 0;
}
