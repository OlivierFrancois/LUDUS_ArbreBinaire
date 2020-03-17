#include "arbre.h"


ArbreBinaire* CreatArbreBinaire(int nDonnee)
//BUT : Initialiser un arbre binaire.
//ENTREE : La donnée à mettre dans le noeud.
//SORTIE : L'arbre initialisé avec son noeud.
{
	ArbreBinaire *arbreB = malloc(sizeof(ArbreBinaire*));

	if (arbreB==NULL)
	{
		printf("Erreur lors de la creation d'un arbre binaire.\n");
		exit(EXIT_FAILURE);
	}

	arbreB->nDonnee = nDonnee;
	arbreB->abDroit = NULL;
	arbreB->abGauche = NULL;

	//Debug :
	printf("Creation de %d\n", arbreB->nDonnee);

	return arbreB;
}

void LibererArbreBinaire(ArbreBinaire* arbreB)
//BUT : Vider un arbre binaire.
//ENTREE : Un arbre binaire.
//SORTIE : L'arbre binare vide.
{
    if(arbreB!=NULL)
    {
        if (arbreB->abDroit!=NULL)
            LibererArbreBinaire(arbreB->abDroit);
        if (arbreB->abGauche!=NULL)
            LibererArbreBinaire(arbreB->abGauche);

        //Debug :
        printf("Suppression de %d\n", arbreB->nDonnee);
        free(arbreB);
    }
}

ArbreBinaire* LiaisonArbreBinaire(ArbreBinaire* ArbreDroit,ArbreBinaire* ArbreGauche,int nDonnee)
//BUT : Lier un noeud d'arbre binaire à deux autres noeuds.
//ENTREE : Les deux noeuds à accrocher au notre qui contient sa valeur.
//SORTIE : Un noeud possédant deux branches pointant sur les noeuds donnés.
{
    ArbreBinaire* arbreB = CreatArbreBinaire(nDonnee);

    arbreB->abDroit = ArbreDroit;
    arbreB->abGauche = ArbreGauche;

    return arbreB;
}

void AfficheArbrePrefix(ArbreBinaire* arbreB)
//BUT : Afficher le contenu de la racine aux feuilles en prenant les éléments à gauche en priorité.
//ENTREE : Notre arbre binaire.
//SORTIE : Le contenu de l'arbre.
{
    if (arbreB != NULL)
    {
        printf("(%d)\n",arbreB->nDonnee);
        if (arbreB->abGauche != NULL)
            AfficheArbrePrefix(arbreB->abGauche);
        if (arbreB->abDroit != NULL)
            AfficheArbrePrefix(arbreB->abDroit);
    }
    else
    {
        printf("Arbre vide.\n");
    }
}

int GetTailleArbre(ArbreBinaire* arbreB)
//BUT : Afficher le nombre de noeuds de notre arbre.
//ENTREE : Notre arbre binaire.
//SORTIE : Le nombre de noeuds en tant qu'entier.
{
    if (arbreB != NULL)
    {
        return(GetTailleArbre(arbreB->abDroit)+GetTailleArbre(arbreB->abGauche)+1);
    }
    else
    {
        return 0;
    }
}
