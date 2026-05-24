#include<stdio.h>
#define MAX 25
int main()
{
    int frag[MAX], b[MAX], f[MAX];
    int i, j, nb, nf, temp, highest = 0;
    int bf[MAX] = {0}, ff[MAX] = {0};
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);
    printf("\nEnter the size of the blocks:\n");
    for(i = 0; i < nb; i++)
    {
        printf("Block %d: ", i+1);
        scanf("%d", &b[i]);
    }
    printf("\nEnter the size of the files:\n");
    for(i = 0; i < nf; i++)
    {
        printf("File %d: ", i+1);
        scanf("%d", &f[i]);
    }
    for(i = 0; i < nf; i++)
    {
        highest = -1;
        for(j = 0; j < nb; j++)
        {
            if(bf[j] != 1)
            {
                temp = b[j] - f[i];
                if(temp >= 0)
                {
                    if(highest < temp)
                    {
                        ff[i] = j;
                        highest = temp;
                    }
                }
            }
        }
        if(highest != -1)
        {
            frag[i] = highest;
            bf[ff[i]] = 1;
        }
        else
        {
            frag[i] = -1; // Not allocated
        }
    }
    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");
    for(i = 0; i < nf; i++)
    {
        if(frag[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                   i+1, f[i], ff[i]+1, b[ff[i]], frag[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i+1, f[i]);
    }
    return 0;
}
