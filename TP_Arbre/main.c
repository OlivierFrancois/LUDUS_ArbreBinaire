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
	Tree *tree_H = CreateTree('H', NULL, NULL);
	Tree *tree_G = CreateTree('G', NULL, NULL);
	Tree *tree_F = CreateTree('F', NULL, NULL);
	Tree *tree_E = CreateTree('E', NULL, NULL);
	Tree *tree_D = CreateTree('D', NULL, NULL);
	Tree *tree_C = CreateTree('C', NULL, NULL);
	Tree *tree_B = CreateTree('B', NULL, NULL);
	Tree *tree_A = CreateTree('A', NULL, NULL);
	printf("Arbres crees !\n");

	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction d'insertion d'enfants\n");
	ChangeColor(color_White, color_Black);
	InsertFirstChild(tree_A, tree_B);
	InsertFirstChild(tree_B, tree_D);
	InsertFirstChild(tree_C, tree_F);
	InsertFirstChild(tree_F, tree_G);
	InsertSiblingToParent(tree_F, tree_H, 2);
	InsertSiblingToParent(tree_F, tree_I, 3);
	InsertSiblingToParent(tree_B, tree_E, 2);
	InsertSiblingToParent(tree_A, tree_C, 2);
	printf("Done !\n");

	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction d'affichage des enfants\n");
    ChangeColor(color_White, color_Black);
    ListTreeChild(tree_A);

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
	printf("\n___________Test de la fonction de retrait d'enfants\n");
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
	printf("\n___________Test de la fonction de recherche en profondeur\n");
	ChangeColor(color_White, color_Black);
	printf("Est-ce que la valeur 'D' se trouve dans l'arbre : %d\n", DepthFirstSearchTree(tree_A,'D'));
	printf("Est-ce que la valeur 'J' se trouve dans l'arbre : %d\n", DepthFirstSearchTree(tree_A,'J'));
    
	ChangeColor(color_Cyan, color_Black);
    printf("\n___________Test de la fonction de recherche en largeur\n");
    ChangeColor(color_White, color_Black);
	printf("Est-ce que la valeur 'D' se trouve dans l'arbre : %d\n", BreadthFirstSearchTree(tree_A,'D'));
	printf("Est-ce que la valeur 'J' se trouve dans l'arbre : %d\n", BreadthFirstSearchTree(tree_A,'J'));

	ChangeColor(color_Cyan, color_Black);
    printf("\n___________Test de la fonction de binarisation\n");
    ChangeColor(color_White, color_Black);
    BinaryTree *treeBinarised = BinarizeTree(tree_A);
    DisplayBinaryTree(treeBinarised);
	
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de clear\n");
	ChangeColor(color_White, color_Black);
	printf("Taille de l'arbre A avant clear d'une feuille : %d\n", GetTreeSize(tree_A));
	ClearTree(tree_F);
	printf("Taille de l'arbre A apres clear d'une feuille : %d\n\n", GetTreeSize(tree_A));

    system("pause");
    system("cls");

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
