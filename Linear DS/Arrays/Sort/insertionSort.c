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

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int j = i-1;
        int key = arr[i];
        //move all elements greater than key to one position
        // while(j >= 0 && arr[j] > key) {
        //     arr[j+1] = arr[j];
        //     j = j-1;
        // }
        while(j >= 0) {
            if(arr[j] > key) {
                arr[j+1] = arr[j];
            }
            else break;
            j--;
        }
        //find a correct position for key
        arr[j+1] = key;
    }
}

void test() {
    const int size = 10000;
    int *arr = (int *) calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        // arr[i] = (rand() % 100) - 50;   //-50 to 49
        arr[i] = rand() %100;
    }

    // printf("\nBefore sorting: ");
    // display(arr, size);

    printf("\nSorting started!");
    clock_t start = clock();

    insertionSort(arr, size);
    
    clock_t end = clock();
    printf("\nSorting Done.");
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; //calculating time taken by the algo sort values
    
    // printf("\nAfter sorting: ");
    // display(arr, size);

    printf("\nInsertion sort took %.4f seconds to sort %d elements.\n", time_taken, size);

    for (int i = 0; i < size-1; i++) {
        assert(arr[i] <= arr[i+1]); //checking if array is perfectly sorted or not (if not then it (assert) will return error)
    }
    free(arr);
}

int main() {
    srand(time(NULL)); //initialize the random elements
    test();
    return 0;
}