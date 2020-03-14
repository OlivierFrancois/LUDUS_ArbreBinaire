#include "tree.h"

int main()
{
	printf("Creating new tree...\n");
    Tree *tree = join_tree(new_tree(2),new_tree(4),6);
    printf("...new tree created.\n");
    printf("Displaying tree's values : \n");
    printf("------------\n");
    display_tree(tree);
    printf("------------\n");
    printf("The tree has %d nodes\n", count_nodes(tree));
    printf("Free-ing tree...\n");
    free_tree(tree);
    printf("...tree freed.\n");

    return 0;
}
