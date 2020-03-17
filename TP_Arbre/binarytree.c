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
