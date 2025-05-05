/**
 * File: bruteforce.c
 * Description: Implementation of a brute force algorithm for knapsack algorithm.
 * Authors: Jadon Sacayanan, Mar Paul Palacio
 * Date: 05/03/2025
 * Source: https://www.w3schools.com/dsa/dsa_ref_knapsack.php
 * Description of a maximum knapsack algorithm: Given n items where each item has some weight 
 * and profit associated with it and also given a bag with capacity W, [i.e., the bag can hold 
 * at most W weight in it]. The task is to put the items into the bag such that the sum of profits 
 * associated with them is the maximum possible. 
 */

#include <stdio.h>
#include <stdlib.h>



int WEIGHTS[] = {7,3,5,3,18, 2};
int VALUES[] = {300, 200, 400, 500, 700, 700};
int capacity = 19;

void knapsack_brute_force(int capacity, int n, int current[], int best[], int curr_value, int *max_value) {
    if (n == 0 || capacity == 0) {
        if (curr_value > *max_value) {
            *max_value = curr_value;
            // Copy current[] to best[]
            int total_items = sizeof(VALUES) / sizeof(VALUES[0]);
            for (int i = 0; i < total_items; i++) {
                best[i] = current[i];
            }
        }
        return;
    }

    // Exclude current item
    current[n - 1] = 0;
    knapsack_brute_force(capacity, n - 1, current, best, curr_value, max_value);

    // Include current item (if it fits)
    if (WEIGHTS[n - 1] <= capacity) {
        current[n - 1] = 1;
        knapsack_brute_force(capacity - WEIGHTS[n - 1], n - 1, current, best,
                              curr_value + VALUES[n - 1], max_value);
    }
}   

int main() {

    int n = sizeof(VALUES) / sizeof(VALUES[0]);
    int current[n];
    int best[n];

    // Initializes values
    for (int i=0; i<n; i++){
        current[i]=0;
        best[i]= 0;
    }

    int max_value =0;

   
    knapsack_brute_force(capacity, n, current, best, 0, &max_value);

    printf("Maximum value: %d\n", max_value);
    printf("Selected items (indices starting from 0): ");
    for (int i = 0; i < n; i++) {
        if (best[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("Maximum value: %d\n", max_value);
    return 0;
}

