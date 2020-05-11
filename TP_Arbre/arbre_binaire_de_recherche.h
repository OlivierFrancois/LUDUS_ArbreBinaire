#ifndef ARBRE_BINAIRE_DE_RECHERCHE_H_INCLUDED
#define ARBRE_BINAIRE_DE_RECHERCHE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud
{
	int nValeur;
	struct Noeud *aGauche;
	struct Noeud *aDroit;
}Noeud;

struct Noeud* NoeudRacine; //Pour garder la racine.

Noeud *CreationNoeud(int nValeur);
Noeud* InsertionArbreBinRecherche(Noeud* pRacine, int nValeur);

int RechercheArbreBin(Noeud* pRacine, int nValeur);

void NettoyerArbreBin(Noeud *pRacine);

#endif
