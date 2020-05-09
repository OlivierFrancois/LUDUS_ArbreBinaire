#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

typedef struct ElementFile ElementFile;
struct ElementFile
{
    struct Tree *tree;
    ElementFile *next;
};


typedef struct File File;
struct File
{
    ElementFile *first;
};

extern File *initialiserFile();
extern void enfiler(File *file, Tree *tree);
extern Tree* defiler(File *file);
extern void afficherFile(File *File);


#endif // FILE_H_INCLUDED
