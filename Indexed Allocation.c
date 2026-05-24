#include <stdio.h>
int main() {
    int f[50] = {0};
    int index, blocks[50], n, i, flag = 0;
   printf("Enter index block: ");
    scanf("%d", &index);
    if (f[index] == 1) {
        printf("Index block already allocated!\n");
        return 0;
    }
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    printf("Enter block numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &blocks[i]);

        if (f[blocks[i]] == 1) {
           printf("Block %d already allocated!\n", blocks[i]);
            flag = 1;
        }
    }

    if (flag == 0) {
        f[index] = 1;
        for (i = 0; i < n; i++) {
            f[blocks[i]] = 1;
        }
        printf("\n--- Indexed Allocation ---\n");
        for (i = 0; i < n; i++) {
            printf("%d -> %d\n", index, blocks[i]);
        }
    }
    return 0;
}