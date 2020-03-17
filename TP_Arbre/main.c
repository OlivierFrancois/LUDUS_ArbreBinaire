#include "arbre.h"

int main()
{
    ArbreBinaire* monArbreBinaire = LiaisonArbreBinaire(LiaisonArbreBinaire(CreatArbreBinaire(33),LiaisonArbreBinaire(CreatArbreBinaire(22),CreatArbreBinaire(11),66),55),CreatArbreBinaire(44),99);

    AfficheArbrePrefix(monArbreBinaire);

    printf("Mon arbre contient %d noeuds.\n",GetTailleArbre(monArbreBinaire));

    LibererArbreBinaire(monArbreBinaire);
    return 0;
}
