#include <stdio.h>


#define BBS 0 // Run Bubblesort if set to 1
#define SS 0 // Run selection sort if set to 1
#define IS 1 // Run insertion sort if set to 1

typedef int bool;
#define true 1
#define false 0

#define test_assert(test, message)\
    if (test) {\
        printf("SUCCESS: %s\n", message);\
    } else {\
        printf("FAILURE: %s\n", message);\
    }

bool arrays_are_equal(int a[], int b[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void swap_elements_in_array(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void shift_and_insert_elements_in_array(int arr[], int starting_index, int ending_index) {
    int temp = arr[ending_index];
    while (ending_index > starting_index) {
        ending_index -= 1;
        arr[ending_index + 1] = arr[ending_index];
    }
    arr[starting_index] = temp;
}

void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int find_min_element_in_array(int arr[], int size, int starting_index) {
    int i;
    int index_of_min_element = starting_index;
    for (i = starting_index; i < size; i++) {
        if (arr[index_of_min_element] > arr[i]) {
            index_of_min_element = i;
        }
    }
    return index_of_min_element;
}

void bubblesort(int unsorted_array[], int size) {
    int i;
    bool swaps_were_made;
    do {
        i = 0;
        swaps_were_made = false;
        while ((i + 1) < size) {
            if (unsorted_array[i] > unsorted_array[i + 1]) {
                swap_elements_in_array(unsorted_array, i, (i + 1));
                swaps_were_made = true;
            }
            i += 1;
        }
        print_array(unsorted_array, size);
    } while (swaps_were_made);
}

void selectionsort(int unsorted_array[], int size) {
    int i = 0;
    int min_element_index;
    while (i < size) {
        min_element_index = find_min_element_in_array(unsorted_array, size, i);
        swap_elements_in_array(unsorted_array, min_element_index, i);
        i++;
        print_array(unsorted_array, size);
    }
}

void insertionsort(int unsorted_array[], int size) {
    int i = 0;
    int j;
    while (i < size) {
        // Check if there are elements to the left of this elements
        // We might have to take the current element and insert before those
        if (i > 0) {
            for (j = 0; j < i; j++) {
                // We insert the element i in front of any element j that
                // is greater than element i
                if (unsorted_array[i] < unsorted_array[j]) {
                    // Insert i in front of j by shifting elements left
                    shift_and_insert_elements_in_array(unsorted_array, j, i);
                }
            }
        }

        i++;
        print_array(unsorted_array, size);
    }
}

int main(void) {
    int unsorted_array[] = {4, 2, 6, 1, 9};
    int sorted_array[] = {1, 2, 4, 6, 9};
    int size = sizeof(unsorted_array)/sizeof(int);

    #if BBS
        bubblesort(unsorted_array, size);
        test_assert(arrays_are_equal(unsorted_array, sorted_array, size), "Arrays are equal after bubble sort.");
    #elif SS
        // test_assert(find_min_element_in_array(unsorted_array, size, 0) == 3, "Min element index found.");
        selectionsort(unsorted_array, size);
        test_assert(arrays_are_equal(unsorted_array, sorted_array, size), "Arrays are equal after selection sort.");
    #elif IS
        // int shifted_and_inserted_array[] = {1, 4, 2, 6, 9};
        // shift_and_insert_elements_in_array(unsorted_array, 0, 3);
        // test_assert(arrays_are_equal(unsorted_array, shifted_and_inserted_array, size), "Element were shifted and inserted correctly.");
        insertionsort(unsorted_array, size);
        test_assert(arrays_are_equal(unsorted_array, sorted_array, size), "Arrays are equal after insertion sort.")
    #endif

    return 0;
}
