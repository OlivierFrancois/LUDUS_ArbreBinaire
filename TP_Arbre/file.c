#include "file.h"

tFile *initialiserFile()
{
    tFile *pFile = malloc(sizeof(*pFile));
    pFile->pPremier = NULL;
    return pFile;
}

void enfiler(tFile *pFile, Tree *tree)
{
    tElementFile *pNouveau = malloc(sizeof(*pNouveau));
    if (pFile == NULL || pNouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    pNouveau->noeud = tree;
    pNouveau->pSuivant = NULL;

    if (pFile->pPremier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        tElementFile *pActuel = pFile->pPremier;
        while (pActuel->pSuivant != NULL)
        {
            pActuel = pActuel->pSuivant;
        }
        pActuel->pSuivant = pNouveau;
    }
    else /* La file est vide, notre élément est le pPremier */
    {
        pFile->pPremier = pNouveau;
    }
}

struct Tree* defiler(tFile *pFile)
{
    if (pFile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Tree* nDefile;

    /* On vérifie s'il y a quelque chose à défiler */
    if (pFile->pPremier != NULL)
    {
        tElementFile *pDefile = pFile->pPremier;

        nDefile = pDefile->noeud;
        pFile->pPremier = pDefile->pSuivant;
        free(pDefile);
    }
    return nDefile;
}

void afficherFile(tFile *pFile)
//BUT : Afficher les valeurs de la file.
{
    if (pFile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    tElementFile *pActuel = pFile->pPremier;
    while (pActuel != NULL)
    {
        printf("%d ", pActuel->noeud->value);
        pActuel = pActuel->pSuivant;
    }
    printf("\n");
}

