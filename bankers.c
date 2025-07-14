#include <stdio.h>

int main() {
    int n, m;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m];
    int available[m], work[m], finish[n], safesequence[n];
    int count = 0;

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("P%d Resource %d: ", i, j);
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input Max Matrix
    printf("\nEnter Max Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("P%d Resource %d: ", i, j);
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");
    for (int j = 0; j < m; j++) {
        printf("Resource %d: ", j);
        scanf("%d", &available[j]);
    }

    // Calculate Need Matrix = Max - Allocation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize Work = Available, Finish = 0
    for (int j = 0; j < m; j++) {
        work[j] = available[j];
    }
    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    // Safety Algorithm
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int flag = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    for (int k = 0; k < m; k++) {
                        work[k] += allocation[i][k];
                    }
                    safesequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("\nSystem is NOT in a safe state.\n");
            return 0;
        }
    }

    // Print Safe Sequence
    printf("\nSystem is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d", safesequence[i]);
        if (i < n - 1) printf(" -> ");
    }
    printf("\n");

    return 0;
}