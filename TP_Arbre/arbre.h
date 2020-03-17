#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct ArbreBinaire
{
    int nDonnee;
    struct ArbreBinaire *abGauche;
    struct ArbreBinaire *abDroit;
}ArbreBinaire;

ArbreBinaire* CreatArbreBinaire(int nDonnee);
ArbreBinaire* LiaisonArbreBinaire(ArbreBinaire* ArbreDroit,ArbreBinaire* ArbreGauche,int nDonnee);
void LibererArbreBinaire(ArbreBinaire* arbreB);
void AfficheArbrePrefix(ArbreBinaire* arbreB);
int GetTailleArbre(ArbreBinaire* arbreB);

#endif
