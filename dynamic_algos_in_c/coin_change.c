// Minimum # of coins to make change c
// or number of ways to make change c
// keep track of which coins were used
#include <stdio.h>
#include <math.h>

#define num_coins 4
#define change 31 /* Really the change is 30 but for the for loops we need 31 */

void test_assert(int test, char message[]) {
    if (test) {
        printf("SUCCESS: %s\n", message);
    } else {
        printf("FAILURE: %s\n", message);
    }
}

int minimum_of_two_numbers(int x, int y) {
    if (x <= y) {
        return x;
    } else {
        return y;
    }
}

void print_matrix(int M[num_coins][change]) {
    unsigned int i, j;
    for (i = 0; i < num_coins; i++) {
        for (j = 0; j < change; j++) {
            printf("%d", M[i][j]);
        }
        printf("\n");
    }
}

int minimum_number_of_coins_to_make_change() {
    unsigned int i, j;
    // Values of the coins
    int v[] = {1, 5, 10, 25};
    int M[num_coins][change];
    for (i = 0; i < num_coins; i++) {
        for (j = 0; j < change; j++) {
            M[i][j] = -1;
        }
    }

    // Initialize column with change = 0 to all 0's
    // no coins can be used if there is no change
    for (i = 0; i < num_coins; i++) {
        M[i][0] = 0;
    }

    // Initialize first row (first coin) to how manys coins it will take to
    // make that change with that single coin
    for (j = 0; j < change; j++) {
        if (v[0] <= j) {
            M[0][j] = (int) floor(j/v[0]);
        }
    }

    for (i = 1; i < num_coins; i++) {
        for (j = 1; j < change; j++) {
            if (v[i] > j) {
                M[i][j] = M[i - 1][j];
            } else {
                int number_of_times_coin_goes_into_change = (int) floor(j/v[i]);
                int change_remaining = j - number_of_times_coin_goes_into_change * v[i];
                int best_solution_to_remaining_change = M[i - 1][change_remaining];
                M[i][j] = minimum_of_two_numbers(M[i - 1][j], number_of_times_coin_goes_into_change + best_solution_to_remaining_change);
            }
        }
    }


    print_matrix(M);

    return M[num_coins - 1][change - 1];
}

int main(void) {
    int solution = minimum_number_of_coins_to_make_change();
    test_assert(solution == 2, "The minimum number of coins is correct.");
}
