#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[50], at[50], ft[50], tat[50], wt[50];
    char p[50][5];
    float awt = 0, att = 0, sum_wt = 0, sum_tat = 0;

    printf("\nEnter Process Name and Burst Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%s %d", p[i], &bt[i]);
    }

    printf("\nEnter Arrival Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    // Calculating Finish Time, Turnaround Time, and Waiting Time correctly
    for(i = 0; i < n; i++) {
        if (i == 0) {
            // First process starts either at its arrival time
            ft[i] = at[i] + bt[i];
        } else {
            // If CPU sits idle waiting for a process to arrive
            if (at[i] > ft[i-1]) {
                ft[i] = at[i] + bt[i];
            } else {
                ft[i] = ft[i-1] + bt[i];
            }
        }
        tat[i] = ft[i] - at[i];
        wt[i] = tat[i] - bt[i];
        
        sum_wt += wt[i];
        sum_tat += tat[i];
    }

    // Displaying the Gantt Chart
    printf("\n\t\tGANTT CHART\n");
    printf(" ");
    for(i = 0; i < n; i++) {
        printf("------- ");
    }
    printf("\n|");
    for(i = 0; i < n; i++) {
        printf("  %s\t|", p[i]);
    }
    printf("\n ");
    for(i = 0; i < n; i++) {
        printf("------- ");
    }
    printf("\n0");
    for(i = 0; i < n; i++) {
        printf("\t%d", ft[i]);
    }
    
    // Printing Table Display 
    printf("\n\nFIRST COME FIRST SERVE SCHEDULING\n");
    printf("\nProcess\tBurst Time\tArrival Time\tFinish Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], at[i], ft[i], wt[i], tat[i]);
    }

    awt = sum_wt / n;
    att = sum_tat / n;

    printf("\nAverage Waiting Time: %.2f", awt);
    printf("\nAverage Turnaround Time: %.2f\n", att);

    return 0;
}