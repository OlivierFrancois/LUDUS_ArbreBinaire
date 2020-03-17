#include "tree.h"

int main()
{
    //Exemple d'arbre n-aire de taille 6 :
    /*              A
                   / \
                  B   C
                 /|\
                D E F
    */

    //Création de noeuds sans enfant
    tTree *F = createTree(NULL,NULL,6);
    tTree *E = createTree(NULL,F,5);
    tTree *D = createTree(NULL,E,4);

    tTree *C = createTree(NULL,NULL,3);
    tTree *B = createTree(NULL,C,2);

    tTree *A = createTree(NULL,NULL,1);

    //Insertion des premiers enfants
    insertFirstChildToParent(B,D);
    insertFirstChildToParent(A,B);

    printf("Taille de B : %d\n",getSize(B));
    printf("Taille de A : %d\n",getSize(A));

    printf("Hauteur de B : %d\n",getHeight(B));
    printf("Hauteur de A : %d\n",getHeight(A));

    return 0;
}
