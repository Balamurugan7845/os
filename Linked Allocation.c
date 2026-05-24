#include <stdio.h>
int main() {
    int f[50] = {0};
    int blocks[50], n, i, flag = 0;
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
        for (i = 0; i < n; i++) {
            f[blocks[i]] = 1;
        }

        printf("\n--- Linked Allocation ---\n");

        for (i = 0; i < n - 1; i++) {
            printf("%d -> %d\n", blocks[i], blocks[i + 1]);
        }

        printf("%d -> NULL\n", blocks[n - 1]);
    }

    return 0;
}