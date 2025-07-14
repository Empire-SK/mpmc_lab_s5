#include <stdio.h>

int n, bt[30], wt[30], tat[30], rem_bt[30], total_wt = 0, total_tat = 0; 
float avg_wt, avg_tat;

void round_robin(int quantum) {
    int i, time = 0, completed = 0;

    for (i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
    }

    total_wt = 0;
    total_tat = 0;

    while (completed != n) {
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                if (rem_bt[i] > quantum) {
                    time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    tat[i] = wt[i] + bt[i];
                    total_wt += wt[i];
                    total_tat += tat[i];
                    rem_bt[i] = 0;
                    completed++;
                }
            }
        }
    }

    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;
}

void main() {
    int i, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    round_robin(quantum);

    printf("\nRound Robin Scheduling Algorithm\n");
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
																
    printf("\nTotal Waiting Time: %d", total_wt);
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nTotal Turnaround Time: %d", total_tat);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
}

