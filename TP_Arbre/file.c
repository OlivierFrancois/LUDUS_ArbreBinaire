#include "file.h"

File *initialiserFile()
{
    File *file = malloc(sizeof(*file));
    file->first = NULL;
    return file;
}

void enfiler(File *file, Tree *tree)
{
    ElementFile *new = malloc(sizeof(*new));
    if (file == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }

    new->tree = tree;
    new->next = NULL;

    if (file->first != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        ElementFile *current = file->first;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new;
    }
    else /* La file est vide, notre élément est le first */
    {
        file->first = new;
    }
}

struct Tree* defiler(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Tree* nDefile;

    /* On vérifie s'il y a quelque chose à défiler */
    if (file->first != NULL)
    {
        ElementFile *defile = file->first;

        nDefile = defile->tree;
        file->first = defile->next;
        free(defile);
    }
    return nDefile;
}

void afficherFile(File *file)
//BUT : Afficher les valeurs de la file.
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    ElementFile *current = file->first;
    while (current != NULL)
    {
        printf("%d ", current->tree->value);
        current = current->next;
    }
    printf("\n");
}

