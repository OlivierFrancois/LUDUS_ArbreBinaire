#include "binarytree.h"
#include "tree.h"
#include "style.h"
#include "arbre_binaire_de_recherche.h"

int NAry_Tree();
int Binary_Tree();
int Binary__Search_Tree();

int main()
{
	ChangeColor(color_Blue, color_Black);
	printf("\n_________________________Fonctions n-Aire_________________________\n");
	ChangeColor(color_White, color_Black);

	/*
	BASE SUR CET ARBRE :
			 A
		   /   \
		  B     C
		 / \    |
		D   E   F
			  / | \
			 G  H  I
	*/

	NAry_Tree();

	system("pause");
	system("cls");

	ChangeColor(color_Blue, color_Black);
	printf("\n_________________________Fonctions Binaire_________________________\n");
	ChangeColor(color_White, color_Black);

	Binary_Tree();

	system("pause");
	system("cls");

	ChangeColor(color_Blue, color_Black);
	printf("\n_________________________Fonctions Binaire de recherche_________________________\n");
	ChangeColor(color_White, color_Black);

	Binary__Search_Tree();

	return 0;
}

int NAry_Tree()
{
	//___________________________CREATION DE L'ARBRE___________________________//
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

	//___________________________INSERTION D'ENFANTS___________________________//
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

	//___________________________AFFICHAGE DE L'ARBRE___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction d'affichage des enfants\n");
	ChangeColor(color_White, color_Black);
	ListTreeChild(tree_A);
	printf("\n");

	//___________________________TAILLE DE L'ARBRE___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de taille\n");
	ChangeColor(color_White, color_Black);
	printf("Taille de l'arbre F : %d\n", GetTreeSize(tree_F));
	printf("Taille de l'arbre A : %d\n", GetTreeSize(tree_A));
	printf("Taille de l'arbre G : %d\n", GetTreeSize(tree_G));

	//___________________________HAUTEUR DE L'ARBRE___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de hauteur\n");
	ChangeColor(color_White, color_Black);
	printf("Hauteur de l'arbre F : %d\n", GetTreeHeight(tree_F));
	printf("Hauteur de l'arbre A : %d\n", GetTreeHeight(tree_A));
	printf("Hauteur de l'arbre B : %d\n", GetTreeHeight(tree_B));

	system("pause");
	system("cls");

	//___________________________SUPPRESSION D'ENFANTS___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de retrait d'enfants\n");
	ChangeColor(color_White, color_Black);
	printf("Taille de l'arbre A avant retrait : %d\n", GetTreeSize(tree_A));
	RemoveFirstChild(tree_A);
	printf("Taille de l'arbre A apres suppression du noeud B : %d\n", GetTreeSize(tree_A));
	RemoveFirstChild(tree_F);
	printf("Taille de l'arbre A apres suppression du noeud G : %d\n", GetTreeSize(tree_A));

	//___________________________SUPPRESSION DE SIBLING___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de retrait de sibling\n");
	ChangeColor(color_White, color_Black);
	printf("Taille de l'arbre A avant retrait : %d\n", GetTreeSize(tree_A));
	RemoveSibling(tree_H);
	printf("Taille de l'arbre A apres suppression du sibling de H : %d\n", GetTreeSize(tree_A));
	printf("Suppression d'un sibling inexistant : \n");
	RemoveSibling(tree_C);

	system("pause");
	system("cls");

	//___________________________RECHERCHE EN PROFONDEUR___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de recherche en profondeur\n");
	ChangeColor(color_White, color_Black);
	printf("Est-ce que la valeur 'D' se trouve dans l'arbre : %d\n", DepthFirstSearchTree(tree_A,'D'));
	printf("Est-ce que la valeur 'J' se trouve dans l'arbre : %d\n", DepthFirstSearchTree(tree_A,'J'));

	//___________________________RECHERCHE EN LARGEUR___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de recherche en largeur\n");
	ChangeColor(color_White, color_Black);
	printf("Est-ce que la valeur 'D' se trouve dans l'arbre : %d\n", BreadthFirstSearchTree(tree_A,'D'));
	printf("Est-ce que la valeur 'J' se trouve dans l'arbre : %d\n", BreadthFirstSearchTree(tree_A,'J'));

	system("pause");
	system("cls");

	//___________________________BINARISATION DE L'ARBRE___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de binarisation\n");
	ChangeColor(color_White, color_Black);
	BinaryTree *treeBinarised = BinarizeTree(tree_A);
	DisplayBinaryTree(treeBinarised);

	//___________________________CLEAR DE L'ARBRE___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de clear\n");
	ChangeColor(color_White, color_Black);
	printf("Taille de l'arbre A avant clear d'une feuille : %d\n", GetTreeSize(tree_A));
	ClearTree(tree_F);
	printf("Taille de l'arbre A apres clear d'une feuille : %d\n\n", GetTreeSize(tree_A));

	return 0;
}

int Binary_Tree()
{
	//___________________________CONSTRUCTION DE L'ARBRE___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Constructions d'arbres et jointures\n");
	ChangeColor(color_White, color_Black);
	int arr[9] = {6, 4, 12, 7, 82, 132, 93, 35, 28}; //tableau d'entiers à partir duquel on va créer un arbre binaire
	int i = 0;
	int arraySize = sizeof(arr) / sizeof(arr[0]);
	BinaryTree *binaryTree = malloc(sizeof(*binaryTree));
	binaryTree = CreateBinaryTreeFromArray(arr, binaryTree, 0, arraySize);
	printf("Arbres crees !\n");

	//___________________________AFFICHAGE DE L'ARBRE___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Affichage d'arbres\n");
	ChangeColor(color_DarkYellow, color_Black);
	printf("Affichage du tableau initial : \n");
	ChangeColor(color_White, color_Black);
	for (int i = 0; i < arraySize; i++) //Affichage du tableau
	{
		printf("[%d] ", arr[i] );
	}
	DisplayBinaryTree(binaryTree); //Affichage de l'arbre

	//___________________________TAILLE DE L'ARBRE___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de taille\n");
	ChangeColor(color_White, color_Black);
	printf("L'arbre a %d noeuds\n\n", GetBinaryTreeSize(binaryTree));

	//___________________________FONCTION DE RECHERCHE___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de recherche\n");
	ChangeColor(color_White, color_Black);
	printf("Est-ce que la valeur 1 existe ? %d\n", SearchBinaryTree(binaryTree, 1));
	printf("Est-ce que la valeur 7 existe ? %d\n", SearchBinaryTree(binaryTree, 7));

	system("pause");
	system("cls");

	//___________________________TRI PAR TAS___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de tri par tas\n");
	ChangeColor(color_White, color_Black);

	while(arraySize-i != 1) //tant qu'il ne reste pas 1 seul valeur dans le tableau
	{
		ChangeColor(color_DarkYellow, color_Black);
		printf("______Iteration numero %d de la boucle\n",i);
		ChangeColor(color_White, color_Black);

		//on récupère la valeur max dans le tableau, sachant qu'a chaque itération, passer arraySize-i car une fois qu'on a trié un chiffre, on ne veut pas le réincorporer dans la boucle
		int max = GetMaxValue(arr,arraySize-i);

		//tant que la valeur tout au dessus de l'arbre n'est pas égale à la valeur max, c'est à dire tant que l'on a pas créer un tas-max, on va rappeler la fonction CreateMaxHeap
		while (binaryTree->value != max)
		{
			CreateMaxHeap(binaryTree, arr, arraySize-i);
		}

		InvertFirstAndLastNodeAndRemoveLastNode(binaryTree,arr,arraySize-i); //on inverse le premier et le dernier noeud
		DisplayBinaryTree(binaryTree); //on l'affiche
		i++; //et on incrémente i
	}

	ChangeColor(color_DarkYellow, color_Black);
	printf("\nAffichage du tableau apres tri :\n");
	ChangeColor(color_White, color_Black);
	for (int i = 0; i < arraySize; i++)
	{
		printf("[%d] ", arr[i] );
	}
	printf("\n");

	//___________________________CLEAR DE L'ARBRE___________________________//
	ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de clear\n");
	ChangeColor(color_White, color_Black);
	ClearBinaryTree(binaryTree);
	printf("Arbre clear\n");


	return 0;
}

int Binary__Search_Tree()
{
    //___________________________CREATION DE L'ARBRE___________________________//
    ChangeColor(color_Cyan, color_Black);
	printf("\n___________Creation de l'arbre binaire de recherche\n");
	ChangeColor(color_White, color_Black);

    NoeudRacine = NULL;
    NoeudRacine = InsertionArbreBinRecherche(NoeudRacine, 5);
    NoeudRacine = InsertionArbreBinRecherche(NoeudRacine, 1);
    NoeudRacine = InsertionArbreBinRecherche(NoeudRacine, 6);
    printf("Arbres crees !\n");

    //___________________________FONCTION DE RECHERCHE___________________________//
    ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de recherche\n");
	ChangeColor(color_White, color_Black);
    printf("Est-ce que la valeur 1 existe ? %d\n", RechercheArbreBin(NoeudRacine, 1));
	printf("Est-ce que la valeur 7 existe ? %d\n", RechercheArbreBin(NoeudRacine, 7));
    NettoyerArbreBin(NoeudRacine);
    NoeudRacine=NULL;

    //___________________________FONCTION DE TRI___________________________//
    ChangeColor(color_Cyan, color_Black);
	printf("\n___________Test de la fonction de tri\n");
	ChangeColor(color_White, color_Black);
    int tTable[10] = {5, 1, 4, 2, 3, 6, 8, 9, 7, 0};
    ChangeColor(color_DarkYellow, color_Black);
	printf("Affichage du tableau initial : \n");
	ChangeColor(color_White, color_Black);
    for (int nI=0; nI<10;nI++)
    {
        printf("[%d] ",tTable[nI]);
        NoeudRacine=InsertionArbreBinRecherche(NoeudRacine,tTable[nI]);
    }
    printf("\n");

    int *nIndexArbre=malloc(sizeof(int));
    (*nIndexArbre)=0;
    RenvoieTriArbreBin(NoeudRacine, tTable,nIndexArbre);

    ChangeColor(color_DarkYellow, color_Black);
	printf("Tableau apres le tri : \n");
	ChangeColor(color_White, color_Black);
    for (int nI=0; nI<10;nI++)
    {
        printf("[%d] ",tTable[nI]);
    }
    printf("\n");

    NettoyerArbreBin(NoeudRacine);

    return 0;
}
