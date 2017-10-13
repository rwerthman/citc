// https://www.youtube.com/watch?v=8LusJS5-AGo
// Algorithms to be implemented: min edit distance, 0/1 knapsack
// Total weight 7: (item weight: 1, item value: 1), (3,4), (4,5), (5,7)
// Final answer is the value 9
#include <stdio.h>

#define num_items 4
#define num_weights 8 /* Weights 0 - 7 */

void test_assert(int test, char message[]) {
    if (test) {
        printf("SUCCESS: %s\n", message);
    } else {
        printf("FAILURE: %s\n", message);
    }
}

int max_of_two_numbers(int x, int y) {
    if (x >= y) {
        return x;
    } else {
        return y;
    }
}

void print_matrix(int M[num_items][num_weights]) {
    unsigned int i, j;
    for (i = 0; i < num_items; i++) {
        for (j = 0; j < num_weights; j++) {
            printf("%d", M[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    unsigned int i, j, x, y;
    // Matrix of subproblems
    // Rows are the items, columns are the available knapsack weight at the time
    // Initialize the matrix to all -1 so I can print it out
    int M[num_items][num_weights];
    for (i = 0; i < num_items; i++) {
        for (j = 0; j < num_weights; j++) {
            M[i][j] = -1;
        }
    }

    // Values of the individual items
    unsigned int v[] = {1, 4, 5, 7};
    // Weights of the individual items
    unsigned int w[] = {1, 3, 4, 5};

    // Initialize the column with available weight 0 to all 0's.
    // This means no items can be chosen if knapsack weight is 0.
    for (i = 0; i < num_items; i++) {
        M[i][0] = 0;
    }

    // Initialize the row of the first item to 1  if the item's
    // weight is less than or equal to the weight in knapsack otherwise set it
    // to 0 meaning that item cannot go in the knapsack
    for (j = 0; j < num_weights; j++) {
        if (w[0] <= j) {
            M[0][j] = 1;
        } else {
            M[0][j] = 0;
        }
    }

    // Go through each of the items
    for (i = 1; i < num_items; i++) {
        // Go through each of the knapsack weights
        for (j = 1; j < num_weights; j++) {
            // If the weight of the item is greater than the knapsack weight
            // then we can't include the item in the knapsack
            if (w[i] > j) {
                M[i][j] = M[i - 1][j];
            } else {
                // Previous highest value for the the given knapsack weight
                x = M[i - 1][j];
                // The value of the current item plus the highest value
                // of the items of the remaining weight after subtracting
                // the weight of the current item
                y = M[i - 1][j - w[i]] + v[i];
                M[i][j] = max_of_two_numbers(x, y);
            }
        }
    }

    print_matrix(M);
    test_assert(M[num_items - 1][num_weights - 1] == 9, "Knapsack code works correctly.");

}
