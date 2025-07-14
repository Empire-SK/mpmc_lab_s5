#include <stdio.h>

void main() {
    int bt[50], wt[50], tat[50], process[20], priority[30];
    int i, j, p, temp;
    float wtavg = 0, tatavg = 0;  // Initialize averages to 0

    printf("Enter the number of processes: ");
    scanf("%d", &p);
    
    // Input burst time and priority for each process
    for(i = 0; i < p; i++) {
        printf("Enter burst time and the priority of process %d: ", i + 1);
        scanf("%d", &bt[i]);
        scanf("%d", &priority[i]);
        process[i] = i + 1;  // Process numbers start from 1
    }

    // Sort processes based on priority (ascending order of priority)
    for(i = 0; i < p; i++) {
        for(j = i + 1; j < p; j++) {    
            if(priority[i] > priority[j]) {
                // Swap priorities
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                // Swap burst times
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process numbers
                int tempProcess = process[i];
                process[i] = process[j];
                process[j] = tempProcess;
            }
        }
    }

    // Waiting time for the first process is 0
    wt[0] = 0;

    // Calculate waiting time and turnaround time for each process
    for(i = 1; i < p; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  // Waiting time = sum of burst times of previous processes
        tat[i] = wt[i] + bt[i];  // Turnaround time = waiting time + burst time
        wtavg += wt[i];  // Sum of waiting times
        tatavg += tat[i];  // Sum of turnaround times
    }

    // Display the results
    printf("\n\n\nPNO.\t PT\t BT\t WT\t TAT\n");        
    for(i = 0; i < p; i++) {
        printf("%d\t %d\t %d\t %d\t %d\n", process[i], priority[i], bt[i], wt[i], tat[i]);
    }

    // Display average waiting time and turnaround time
    printf("AVG WT: %.2f\n", wtavg / p);
    printf("AVG TAT: %.2f\n", tatavg / p);
}

