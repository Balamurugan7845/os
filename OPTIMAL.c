#include <stdio.h>
int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;

    int frames[capacity];
    int i, j, k, pos;
    int faults = 0;
    // Initialize frames
    for(i = 0; i < capacity; i++) {
        frames[i] = -1;
    }
    for(i = 0; i < n; i++) {
        int found = 0;
        // Check if page already in frame
        for(j = 0; j < capacity; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        // If not found → page fault
        if(!found) {
            int farthest = i;
            pos = -1;
            // Find page with farthest future use
            for(j = 0; j < capacity; j++) {
                int found_future = 0;

                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        found_future = 1;
                        break;
                    }
                }
                // If page not used again → replace immediately
                if(!found_future) {
                    pos = j;
                    break;
                }
            }
            // If all pages will be used, replace farthest
            if(pos == -1)
                pos = 0;
            frames[pos] = pages[i];
            faults++;
        }
    }
    printf("Total Page Faults = %d\n", faults);
    return 0;
}
