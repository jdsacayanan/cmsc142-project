// 0-1 Knapsack Problem
// References:
//  - https://youtu.be/nLmhmB6NzcM

#include <stdio.h>
#include <stdlib.h>

// function to print matrix (for debugging purposes)
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to determine the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    // assume profit and weights are integers
    int p[] = {1, 2, 5, 6};     // defines the profit of each item
    int w[] = {2, 3, 4, 5};     // defines the weight of each item
    int m = 8;                  // defines the maximum weight of the knapsack

    // determine the number of items
    int n = sizeof(p) / sizeof(p[0]);

    // create a 2d array to store the maximum profit for each item and weight
    int **v = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        v[i] = (int *)malloc((m + 1) * sizeof(int));
    }

    // initialize everything to -1
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            v[i][j] = -1;
        }
    }

    // initialize the first row and column of the array
    for (int i = 0; i <= n; i++) {
        v[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        v[0][j] = 0;
    }

    // print the initial matrix (for debugging purposes)
    printf("Initial matrix:\n");
    printMatrix(v, n + 1, m + 1);
    printf("\n");

    // fill the matrix using dynamic programming
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (w[i - 1] > j) {
                v[i][j] = v[i - 1][j];
            } else {
                v[i][j] = max(v[i - 1][j], p[i - 1] + v[i - 1][j - w[i - 1]]);
            }
        }
    }

    // print the filled matrix (for debugging purposes)
    printf("Filled matrix:\n");
    printMatrix(v, n + 1, m + 1);
    printf("\n");

    // print the items included in the knapsack
    printf("Items included in the knapsack:\n");
    int j = m;      // start from the maximum profit
    for (int i = n; i > 0; i--) {
        if (v[i][j] != v[i - 1][j]) {
            printf("  - Item %d (profit: %d, weight: %d)\n", i, p[i - 1], w[i - 1]);
            j -= w[i - 1];
        }
    }
    printf("\n");
    printf("Total weight: %d\n", m - j);
    printf("Total profit: %d\n", v[n][m]);
}