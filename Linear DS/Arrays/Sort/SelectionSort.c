#include<assert.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size-1; i++) {
        int min_index = i;
        for (int j = i+1; j < size; j++) {
            if(arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        if(min_index != i) {
            swap(arr+i, arr+min_index);
        }
    }

}

void test() {
    const int size = 10000;
    // const int size = rand() % 500;  //0 to 499
    int *arr = (int *) calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        arr[i] = (rand() % 100) - 50;   //-50 to 49
    }

    printf("\nBefore sorting: ");
    display(arr, size);

    /* Start time measurement */
    clock_t start = clock();

    selectionSort(arr, size);

    /* End time measurement */
    clock_t end = clock();

    /* Calculate the time difference in seconds */
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nAfter sorting: ");
    display(arr, size);

    /* Print the time taken */
    printf("\nSelection sort took %.4f seconds to sort %d elements.\n", time_taken, size);

    /* we use assert to check if my array is sorted or not */
    for (int i = 0; i < size-1; i++) {
        assert(arr[i] <= arr[i+1]);
    }
    free(arr);
}

int main() {
    /* Initializes random number generator */
    srand(time(NULL));  //initialize random number generator
    test();
    return 0;
}