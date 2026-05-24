#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree_element
{
    char name[20];
    int ftype; // 1 = directory, 2 = file
    int nc;    // number of children
    struct tree_element *link[5];
};

typedef struct tree_element node;

// Function to create directory tree
void create(node **root)
{
    int i;

    *root = (node *)malloc(sizeof(node));

    printf("\nEnter name of file/directory: ");
    scanf("%s", (*root)->name);

    printf("Enter 1 for Directory, 2 for File: ");
    scanf("%d", &(*root)->ftype);

    for (i = 0; i < 5; i++)
        (*root)->link[i] = NULL;

    if ((*root)->ftype == 1)
    {
        printf("Enter number of files/subdirectories inside %s (max 5): ", (*root)->name);
        scanf("%d", &(*root)->nc);

        for (i = 0; i < (*root)->nc; i++)
        {
            printf("\nCreating child %d of %s\n", i + 1, (*root)->name);
            create(&((*root)->link[i]));
        }
    }
    else
    {
        (*root)->nc = 0;
    }
}

// Function to display directory structure
void display(node *root, int level)
{
    int i;

    if (root != NULL)
    {
        for (i = 0; i < level; i++)
            printf("  "); // indentation

        if (root->ftype == 1)
            printf("[DIR] %s\n", root->name);
        else
            printf("[FILE] %s\n", root->name);

        for (i = 0; i < root->nc; i++)
        {
            display(root->link[i], level + 1);
        }
    }
}

int main()
{
    node *root = NULL;

    printf("Create Root Directory:\n");
    create(&root);

    printf("\n\nHierarchical Directory Structure:\n");
    display(root, 0);

    return 0;
}
