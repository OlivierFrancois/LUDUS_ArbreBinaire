#include "arbre_binaire_de_recherche.h"

Noeud *CreationNoeud(int nValeur)
{
    Noeud* pNoeud = malloc(sizeof(Noeud));

    if (pNoeud == NULL)
		exit(EXIT_FAILURE);

    pNoeud->nValeur = nValeur;
    pNoeud->aDroit = NULL;
    pNoeud->aGauche = NULL;

    return pNoeud;
}

Noeud* InsertionArbreBinRecherche(Noeud* pRacine, int nValeur)
{
    if (pRacine == NULL) //Si l'arbre est vide
    {
        pRacine=CreationNoeud(nValeur);
    }
    else //Si l'arbre n'est pas vide on faire le test.
    {
        if (nValeur < pRacine->nValeur)
        {
            pRacine->aGauche = InsertionArbreBinRecherche(pRacine->aGauche,nValeur);
        }
        else
        {
            pRacine->aDroit = InsertionArbreBinRecherche(pRacine->aDroit,nValeur);
        }
    }
    return pRacine;
}

int RechercheArbreBin(Noeud* pRacine, int nValeur)
//BUT : Savoir si l'arbre contient cette valeur ou non.
//ENTREE : Une valeur et la racine de l'arbre binaire de recherche.
//SORTIE : 1 si l'arbre contient la valeur et 0 sinon.
{
    if(pRacine==NULL)
    {
        return 0;
    }
    else if (pRacine->nValeur==nValeur)
    {
        return 1;
    }
    else if (nValeur < pRacine->nValeur)
    {
        return RechercheArbreBin(pRacine->aGauche,nValeur);
    }
    else
    {
        return RechercheArbreBin(pRacine->aDroit,nValeur);
    }
}


void NettoyerArbreBin(Noeud *pRacine)
{
    if (pRacine == NULL)
		return;

	if (pRacine->aGauche!=NULL)
		NettoyerArbreBin(pRacine->aGauche);

	if (pRacine->aDroit!=NULL)
		NettoyerArbreBin(pRacine->aDroit);

	free(pRacine);
}
