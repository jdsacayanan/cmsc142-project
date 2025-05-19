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


// -----------------------------------------------------------Global Variables

// Weight of respective Items (Item index corresponds to Item Value Index)
int WEIGHTS[] = {7,3,5,3,18, 2};

// Value of respective Items (Item index corresponds to Item Weight Index)

int VALUES[] = {300, 200, 400, 500, 700, 700};

// Max capacity of the knapsack without exceeding the weight limit
// (i.e., the maximum weight of the knapsack)
int capacity = 19;
// ------------------------------------------------------------


// ------------------------------------------------------------Function Prototypes

// -------------------------------------------Knapsack function

// The function relys on recursion to find all the possible combinations of items and compares it with the best array of items. It can even have only one item in the knapsack
// and even if there are other items that can be added to the knapsack, it will still be considered as a valid combination without the need to add more allowable 
// items to the knapsack.
void knapsack_brute_force(int capacity, int n, int current[], int best[], int curr_value, int *max_value) {

    // If all items have been considered, then check if the current array's curr_value is better than the best array which contains the max value
    if (n == 0 || capacity == 0) {
        if (curr_value > *max_value) {
            *max_value = curr_value;
            // Copy current[] to best[]
            int total_items = sizeof(VALUES) / sizeof(VALUES[0]);

            // Make sure to copy the current array to the best array if current value is greater
            // than the max value
            for (int i = 0; i < total_items; i++) {
                best[i] = current[i];
            }
        }
        return;
    }

    // Exclude current item (WHat if we don't include the current item for the combination)
    current[n - 1] = 0;
    knapsack_brute_force(capacity, n - 1, current, best, curr_value, max_value);

    // Include current item (if it fits in the current capacity left) 
    if (WEIGHTS[n - 1] <= capacity) {
        current[n - 1] = 1;
        knapsack_brute_force(capacity - WEIGHTS[n - 1], n - 1, current, best,
                              curr_value + VALUES[n - 1], max_value);
    }
}   
// ---------------------------------------------

// ------------------------------------------------------------Main Function
// Main function to initiate values, call the knapsack function, and print results (Maximum value and selected items)
int main() {

    int n = sizeof(VALUES) / sizeof(VALUES[0]);
    int current[n];
    int best[n];

    // Initializes values using a flag to indicate whether the item is included in the knapsack
    // 1 indicates the item is included, 0 indicates it is not included
    for (int i=0; i<n; i++){
        current[i]=0;
        best[i]= 0;
    }

    // Initialize the maximum value to 0
    // This variable will store the maximum value of the knapsack
    int max_value =0;

   
    // Call the knapsack function
    knapsack_brute_force(capacity, n, current, best, 0, &max_value);


    // Print the results
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
// ------------------------------------------------------------

