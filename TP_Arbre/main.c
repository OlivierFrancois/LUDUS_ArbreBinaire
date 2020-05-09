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
	Tree *tree_H = CreateTree('H', NULL, NULL);
	Tree *tree_G = CreateTree('G', NULL, NULL);

	Tree *tree_F = CreateTree('F', NULL, NULL);

	Tree *tree_E = CreateTree('E', NULL, NULL);
	Tree *tree_D = CreateTree('D', NULL, NULL);

	Tree *tree_C = CreateTree('C', NULL, NULL);
	Tree *tree_B = CreateTree('B', NULL, NULL);

	Tree *tree_A = CreateTree('A', NULL, NULL);
	printf("Arbres crees !\n");

	printf("\n___________Test de la fonction d'insertion d'enfant\n");
	InsertFirstChildToParent(tree_A, tree_B);
	InsertFirstChildToParent(tree_B, tree_D);
	InsertFirstChildToParent(tree_C, tree_F);
	InsertFirstChildToParent(tree_F, tree_G);

	InsertSiblingToParent(tree_F,tree_H,2);
	InsertSiblingToParent(tree_F,tree_I,3);

	InsertSiblingToParent(tree_B,tree_E,2);
	InsertSiblingToParent(tree_A,tree_C,2);

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

	printf("\n___________Test de la fonction de recherche en profondeur\n");
	printf("Est-ce que la valeur 'I' se trouve dans l'arbre : %d\n",DepthFirstSearchTree(tree_A,'I'));
	printf("Est-ce que la valeur 'J' se trouve dans l'arbre : %d\n",DepthFirstSearchTree(tree_A,'J'));
    printf("\n___________Test de la fonction de recherche en largeur\n");
	printf("Est-ce que la valeur 'I' se trouve dans l'arbre : %d\n",BreadthFirstSearchTree(tree_A,'I'));
	printf("Est-ce que la valeur 'J' se trouve dans l'arbre : %d\n",BreadthFirstSearchTree(tree_A,'J'));

    printf("\n___________Test de la fonction de binarisation\n");
    BinaryTree *treeBinarised = BinarizeTree(tree_A);
    DisplayBinaryTree(treeBinarised);

    printf("\n___________Test de la fonction de suppression d'enfant\n");
	printf("Taile de l'arbre A avant suppression du premier enfant de F : %d\n", GetTreeSize(tree_A));
	RemoveFirstChildFromParent(tree_F);
	printf("Taile de l'arbre A apres suppression du premier enfant de F : %d\n", GetTreeSize(tree_A));
	RemoveChildFromParent(tree_F,2);
	printf("Taile de l'arbre A apres suppression d'un enfant de F : %d\n", GetTreeSize(tree_A));

	printf("\n___________Test de la fonction de clear\n");
	printf("Taille de l'arbre A avant clear d'une feuille : %d\n", GetTreeSize(tree_A));
	ClearTree(tree_F);
	printf("Taille de l'arbre A apres clear d'une feuille : %d\n", GetTreeSize(tree_A));

	printf("\n___________Test de la fonction d'affichage des enfants\n");
    ListTreeChild(tree_A);

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
