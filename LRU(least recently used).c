#include <stdio.h>
int main() {
    int n, capacity, i, j, k;

    // Manual input
    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &capacity);

    int frames[capacity], time[capacity];
    int counter = 0, faults = 0;

    // Initialize frames
    for(i = 0; i < capacity; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    // Table for horizontal output
    int table[capacity][n];
    char status[n]; // F or H

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check hit
        for(j = 0; j < capacity; j++) {
            if(frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                status[i] = 'H';
                break;
            }
        }	

        // Page fault
        if(!found) {
            int pos = 0;

            // Find least recently used
            for(j = 1; j < capacity; j++) {
                if(time[j] < time[pos])
                    pos = j;
            }

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
            status[i] = 'F';
        }

        // Store in table
        for(j = 0; j < capacity; j++) {
            table[j][i] = frames[j];
        }
    }

    // ===== Horizontal Output =====
    printf("\n--- LRU Page Replacement ---\n\n");

    printf("Pages:   ");
    for(i = 0; i < n; i++)
        printf("%3d", pages[i]);

    printf("\n---------------------------------------------\n");

    for(i = 0; i < capacity; i++) {
        printf("Frame%d:  ", i+1);
        for(j = 0; j < n; j++) {
            if(table[i][j] == -1)
                printf("   ");   // hide -1
            else
                printf("%3d", table[i][j]);
        }
        printf("\n");
    }

    printf("---------------------------------------------\n");

    printf("Status:  ");
    for(i = 0; i < n; i++)
        printf("%3c", status[i]);

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}
