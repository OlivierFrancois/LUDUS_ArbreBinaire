#include "binarytree.h"


BinaryTree *CreateBinaryTree(int value)
//Fonction qui prend en paramètre une valeur (la valeur d'un noeud, ici un int) et créer un arbre constitué d'un seul noeud
{
	BinaryTree *tree = malloc(sizeof(*tree));

	if (tree == NULL)
		exit(EXIT_FAILURE);

	tree->value = value;
	tree->left = NULL;
	tree->right = NULL;
	tree->parent = NULL;

	return tree;
}

void ClearBinaryTree(BinaryTree *tree)
//Fonction qui va free la mémoire allouée à l'arbre passé en paramètre, la fonction va être appelée de manière récursive pour free tous les noeuds de l'arbre
{
	//si on arrive sur un pointeur NULL, alors c'est que le noeud en question n'existe pas. du coup on return et on remonte on noeud d'au-dessus
	if (tree == NULL)
		return;
	//sinon on appelle la fonction de manière récursive sur l'arbre gauche de l'arbre en question
	if (tree->left!=NULL)
		ClearBinaryTree(tree->left);
	//puis le droit
	if (tree->right!=NULL)
		ClearBinaryTree(tree->right);
	//et du coup on free l'arbre

	free(tree);
}

BinaryTree *JoinTree(BinaryTree *left, BinaryTree *right, int indexRoot)
//Fonction qui va permettre de joindre 2 arbre à un 3ème
//On passe en paramètre l'arbre gauche à joindre, l'arbre droite à joindre, et la racine à laquelle on va joindre les deux arbres
{
	//du coup on créer un arbre de 1 noeud avec la racine
	BinaryTree *tree = CreateBinaryTree(indexRoot);
	//on assigne les pointeurs correspondant aux arbres
	tree->left = left;
	tree->right = right;
	//on assigne les parents
	if (left != NULL)
		left->parent = tree;

	if (right != NULL)
		right->parent = tree;
	//et on retourne l'arbre
	return tree;
}


BinaryTree *JoinTreeFromExistingRoot(BinaryTree *left, BinaryTree *right, BinaryTree *root)
//Fonction qui va permettre de joindre 2 arbre à un 3ème
//On passe en paramètre l'arbre gauche à joindre, l'arbre droite à joindre, et la racine à laquelle on va joindre les deux arbres
{

	//on assigne les pointeurs correspondant aux arbres
	root->left = left;
	root->right = right;
	//on assigne les parents
	if (left != NULL)
		left->parent = root;

	if (right != NULL)
		right->parent = root;
	//et on retourne l'arbre
	return root;
}

void DisplayBinaryTree(BinaryTree *tree)
//Fonction qui va afficher tous les noeuds de l'arbre (racine comprise)
{
	if (tree == NULL)
		return;
	//si la parent est NULL, alors c'est la racine, du coup on affiche que la valeur
	if (tree->parent == NULL)
		printf("(%d)\n", tree->value);
	//sinon on affiche le parent du noeud actuel, et sa valeur
	else
		printf("(%d) -> (%d)\n", tree->parent->value, tree->value);
	//on fait ça de manière récursive d'abord sur la gauche (parcours préfixe)
	if (tree->left != NULL)
		DisplayBinaryTree(tree->left);
	//puis sur la droite
	if (tree->right != NULL)
		DisplayBinaryTree(tree->right);
}

int GetBinaryTreeSize(BinaryTree *tree)
//Renvoie le nombre de noeuds actuel dans l'arbre passé en paramètre, racine comprise
{
	if (tree == NULL)
		return 0;

	return (GetBinaryTreeSize(tree->left) + GetBinaryTreeSize(tree->right) + 1);
}

//fonction qui va créer un tas-max sur l'arbre passé en paramètre
//on passe également le tableau de valeurs afin d'interchanger les valeurs dans le tableau pendant que l'on créer le tas-max
void CreateMaxHeap(BinaryTree *tree, int arr[], int arraySize)
{
	if (tree == NULL)
		return;
	//on considère que la première valeur est la plus grande au début
	int largest = tree->value;

	//si l'enfant de gauche n'est pas NULL donc il existe
	if (tree->left != NULL)
	{
		//si sa valeur est plus grande, alors on remplace les valeurs dans l'arbre, et on les interchange dans le tableau
		if(tree->left->value > largest)
		{
			int tempValueToReplace1 = SearchIndexOfValue(arr, largest, arraySize);
			int tempValueToReplace2 = SearchIndexOfValue(arr, tree->left->value, arraySize);
			tree->value = tree->left->value;
			tree->left->value = largest;
			largest = tree->value;
			InvertPlaceInArray(arr, tempValueToReplace1, tempValueToReplace2);
		}
	}
	//pareil pour la droite 
	if (tree->right != NULL)
	{
		if(tree->right->value > largest)
		{
			int tempValueToReplace1 = SearchIndexOfValue(arr, largest, arraySize);
			int tempValueToReplace2 = SearchIndexOfValue(arr, tree->right->value, arraySize);
			tree->value = tree->right->value;
			tree->right->value = largest;
			largest = tree->value;
			InvertPlaceInArray(arr, tempValueToReplace1, tempValueToReplace2);
		}
	}

	//et on répercute sur les enfants de gauche et droite
	if(tree->left != NULL)
		CreateMaxHeap(tree->left, arr, arraySize);
	if(tree->right != NULL)
		CreateMaxHeap(tree->right, arr, arraySize);
}

//cette fonction retourne la valeur maximale du tableau passé en paramètre, et on passe la taille maximale du tableau
int GetMaxValue(int arr[], int arraySize)
{
	int i = 0;
	int max = arr[i];

	for (i = 0; i < arraySize; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return max;
}

//retourne 1 si on a trouvé la valeur, 0 sinon
int SearchBinaryTree(BinaryTree *tree, int value)
{
	//booleen qui va déterminer si on a trouvé la valeur ou non
	int hasBeenFound = 0;

	//si on a trouvé la valeur on place le booleen à 1
	if (tree->value == value)
		hasBeenFound = 1;
	//sinon on regarde l'enfant de gauche en premier (s'il n'est pas NULL) et si on n'a pas encore trouvé le chiffre
	if (tree->left != NULL && !hasBeenFound)
		hasBeenFound = SearchBinaryTree(tree->left,value);
	//pareil à droite
	if (tree->right != NULL && !hasBeenFound)
		hasBeenFound = SearchBinaryTree(tree->right,value);


	//inévitablement si on l'a trouvé on va retourner 1 vu que les tests ne seront plus effectués, sinon 0 sera retourné
	return hasBeenFound;
}

//cette fonction va créer un arbre binaire avec le tableau de valeur passé en paramètre
//elle prend i en paramètre car dans le tableau on peut déterminer qu'à un index i, les enfants sont situés à 2*i+1 et 2*i+2
BinaryTree *CreateBinaryTreeFromArray(int arr[], BinaryTree* root, int i, int arraySize)
{
	if (i < arraySize)
	{
		//on va créer un arbre avec la valeur arr[i]
		BinaryTree *temp = CreateBinaryTree(arr[i]);
		root = temp;
		//et on appelle récursivement la fonction sur la gauche puis sur la droite
		root->left = CreateBinaryTreeFromArray(arr,root->left,2*i+1,arraySize);
		root->right = CreateBinaryTreeFromArray(arr,root->right,2*i+2,arraySize);
		//et on lie le parent et ses enfants ensemble
		JoinTreeFromExistingRoot(root->left,root->right,root);
	}
	return root;
}

//cette fonction inverse 2 valeurs dans un tableau
void InvertPlaceInArray(int arr[], int indexToInvert1, int indexToInvert2)
{
	int temp = arr[indexToInvert1];
	arr[indexToInvert1] = arr[indexToInvert2];
	arr[indexToInvert2] = temp;
}

//cette fonction cherche l'index dans le tableau d'une valeur passée en paramètre
int SearchIndexOfValue(int arr[], int value, int arraySize)
{
	int index = 0;

	for (int i = 0; i < arraySize; i++)
	{
		if (arr[i] == value)
			index = i;
	}

	return index;
}

//cette fonction permet de retourner le dernier node (qui est la dernière valeur du tableau)
BinaryTree *GetLastNode(BinaryTree *binaryTree, int value)
{
	//on créer un arbre temporaire
	BinaryTree *tempTree = NULL;

	//si on le trouve, on lui passe la référence du noeud
	if (binaryTree->value == value)
		tempTree = binaryTree;

	//on appelle récursivement la fonction tant que l'on a pas trouvé le noeud
	if (binaryTree->left != NULL && tempTree == NULL)
		tempTree = GetLastNode(binaryTree->left,value);

	if (binaryTree->right != NULL && tempTree == NULL)
		tempTree = GetLastNode(binaryTree->right,value);


	//on retourne le dernier noeud
	return tempTree;
}

//Cette fonction va inverser le premier et le dernier noeud, et supprimer le dernier noeud
void InvertFirstAndLastNodeAndRemoveLastNode(BinaryTree *binaryTree, int arr[], int arraySize)
{
	//on récupère le premier noeud (forcément c'est celui passé en paramètre)
	BinaryTree *firstNode = binaryTree;
	//on utilise notre fonction pour récupérer le dernier noeud
    BinaryTree *lastNode = GetLastNode(binaryTree, arr[arraySize-1]);

    //on inverse les valeurs dans l'arbre binaire
    int tempValue = firstNode->value;
    firstNode->value = lastNode->value;
    lastNode->value = tempValue;

    //on inverse les places dans le tableau
    InvertPlaceInArray(arr,0, arraySize-1);


    //on récupère la référence du parent, et on supprime la référence sur l'enfant qui va être supprimer
    BinaryTree *previousNode = lastNode->parent;
    if(previousNode->left->value == lastNode->value)
    	previousNode->left = NULL;
    else
    	previousNode->right = NULL;

    //et on free la valeur supprimée
    ClearBinaryTree(lastNode);

}
