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
	//tableau d'entiers à partir duquel on va créer un arbre binaire
	int arr[9] = {6,4,12,7,82,132,93,35,28};
	int i = 0;
	int arraySize = sizeof(arr) / sizeof(arr[0]);
    BinaryTree *binaryTree = malloc(sizeof(*binaryTree));
    binaryTree = CreateBinaryTreeFromArray(arr,binaryTree,0,arraySize);
    printf("__________Affichage du tableau initial\n");
    for (int i = 0; i < arraySize; i++)
    {
    	printf("%d\n", arr[i] );
    }


    printf("Arbres crees !\n\n");

    printf("___________Affichage d'arbres\n");
    DisplayBinaryTree(binaryTree);

    printf("___________Test de la fonction de recherche\n");
    printf("Est-ce que la valeur 1 existe ? %d\n",SearchBinaryTree(binaryTree,1));
    printf("Est-ce que la valeur 7 existe ? %d\n",SearchBinaryTree(binaryTree,7));

    //tant qu'il ne reste pas 1 seul valeur dans le tableau
   	while(arraySize-i != 1)
   	{
   		printf("___________Iteration numero %d de la boucle\n",i);
   		//on récupère la valeur max dans le tableau, sachant qu'a chaque itération, passer arraySize-i car une fois qu'on a trié un chiffre, on ne veut pas le réincorporer dans la boucle
	    int max = GetMaxValue(arr,arraySize-i);
	    //tant que la valeur tout au dessus de l'arbre n'est pas égale à la valeur max, c'est à dire tant que l'on a pas créer un tas-max, on va rappeler la fonction CreateMaxHeap
	    while (binaryTree->value != max)
	    {
	    	CreateMaxHeap(binaryTree, arr, arraySize-i);
	    }
	    //on inverse le premier et le dernier noeud
	    InvertFirstAndLastNodeAndRemoveLastNode(binaryTree,arr,arraySize-i);
	    //et on l'affiche
	    DisplayBinaryTree(binaryTree);
	    //et on incrémente i
	    i++;
	}

    printf("__________Affichage du tableau apres tri \n");
    for (int i = 0; i < arraySize; i++)
    {
    	printf("%d\n", arr[i] );
    }

    printf("\n___________Test de la fonction de taille\n");
    printf("L'arbre a %d noeuds\n\n", GetBinaryTreeSize(binaryTree));


    printf("\n___________Test de la fonction de clear\n");
    ClearBinaryTree(binaryTree);
    printf("Arbre clear\n");

    return 0;
}
