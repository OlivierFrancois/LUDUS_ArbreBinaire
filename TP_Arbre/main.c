#include "binarytree.h"
#include "tree.h"
#include "arbre_binaire_de_recherche.h"


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

    //Pour les arbres binaires de recherche :
    printf("Passons aux arbres binaires de recherche..\n");

    NoeudRacine=NULL;
    NoeudRacine=InsertionArbreBinRecherche(NoeudRacine,5);
    NoeudRacine=InsertionArbreBinRecherche(NoeudRacine,1);
    NoeudRacine=InsertionArbreBinRecherche(NoeudRacine,6);

    int nEntier;
    printf("Veuillez entrer un nombre pour savoir si il est dans l'arbre binaire de recherche.\n");
    fflush(stdin);
    scanf("%d",&nEntier);
    fflush(stdin);
    if (RechercheArbreBin(NoeudRacine,nEntier)==1)
    {
        printf("L'entier %d est bien dans l'arbre binaire de recherche.\n",nEntier);
    }
    else
    {
        printf("L'entier %d n'est pas dans l'arbre binaire de recherche.\n",nEntier);
    }
    NettoyerArbreBin(NoeudRacine);

    NoeudRacine=NULL;
    printf("Passons au tri d'un tableau avec cet arbre.\n");
    int tTable[10]={5,1,4,2,3,6,8,9,7,0};
    printf("Voici notre tableau : \n");
    for (int nI=0; nI<10;nI++)
    {
        printf("%d; ",tTable[nI]);
        NoeudRacine=InsertionArbreBinRecherche(NoeudRacine,tTable[nI]);
    }
    printf("\n");

    int *nIndexArbre=malloc(sizeof(int));
    (*nIndexArbre)=0;
    RenvoieTriArbreBin(NoeudRacine, tTable,nIndexArbre);

    printf("Voici notre tableau apres le tri: \n");
    for (int nI=0; nI<10;nI++)
    {
        printf("%d; ",tTable[nI]);
    }

    NettoyerArbreBin(NoeudRacine);

    return 0;
}
