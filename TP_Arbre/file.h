#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

typedef struct tElementFile tElementFile;
struct tElementFile
{
    struct Tree *noeud;
    tElementFile *pSuivant;
};


typedef struct tFile tFile;
struct tFile
{
    tElementFile *pPremier;
};

extern tFile *initialiserFile();
extern void enfiler(tFile *pFile, struct Tree *noeud);
extern struct Tree* defiler(tFile *pFile);
extern void afficherFile(tFile *pFile);


#endif // FILE_H_INCLUDED
