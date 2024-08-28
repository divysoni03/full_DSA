// #include<assert.h>
// #include<stdbool.h>
// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>

// void display(const int* arr, int n) {
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void swap(int* first, int* second) {
//     int temp = *first;
//     *first = *second;
//     *second = temp;
// }

// /*
// Partition method which selects a pivot
// and places each element  which is less than pivot value to its left
// and the elements greater than the pivot value to its right
// */
// int partition(int arr[], int lower, int upper) {
//     int i = (lower - 1);

//     int pivot = arr[upper]; //select last element as pivot

//     int j;
//     for (j = lower; j < upper; j++) {
//         if(arr[j] <= pivot) {
//             //if current element is smaller than pivot
//             i++;    //inc the index of smaller element
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i+1], &arr[upper]);   //places the last element i.e., the pivot
//                                     //to its correct position

//     return(i+1);
// }

// /*
// This is where the sorting of the array takes place
// */
// void quickSort(int arr[], int lower, int upper) {
//     if(upper > lower) {
//         //partitioning index is returned by the partition method, partition
//         // element is at its correct position

//         int partitionIndex = partition(arr, lower, upper); //partition index is just pivot in other words (which is just position of the elements which is in the right position)

//         //sorting elements before and after the partition index
//         quickSort(arr, lower, partitionIndex - 1);
//         quickSort(arr, partitionIndex + 1, upper);
//     }
// }

// void test() {
//     // const int size = rand() % 500;  //0 to 499
//     const int size =  50000; 
//     int *arr = (int *) calloc(size, sizeof(int));

//     for (int i = 0; i < size; i++) {
//         arr[i] = rand() % 100;
//     }

//     printf("\nSorting started!");
//     clock_t start = clock();
    
//     quickSort(arr, 0, size-1);
    
//     clock_t end = clock();
//     printf("\nSorting Done.");
    
//     double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

//     printf("\nQuick sort took %.4f seconds to sort %d elements.\n", time_taken, size);

//     for (int i = 0; i < size-1; i++) {
//         assert(arr[i] <= arr[i+1]);
//     }
//     free(arr);
// }

// int main() {
//     srand(time(NULL));  //initialize random number generator
//     test();
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>

void display(int arr[], int size) {
    printf("\n\nArray : [");
    for(int i=0; i<size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b\b]");
}

int swap(int* a,int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end], i = start-1;
    for(int j=start; j< end-1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[end]);
    return i+1;
}

void QuickSort(int arr[], int start, int end) {
    if(start < end) {
        int pivot = partition(arr, start, end);

        QuickSort(arr, start, pivot-1);
        QuickSort(arr, pivot+1, end);
    }
}

/*
    @brief Perform test on the quick sort algorithm
    @param size size of the array
    @param arr arr with size elements
*/
void test() {
    const int size = 100000;
    int *arr = (int *)calloc(size, sizeof(int));
    //generating random elements
    for(int i=0;i<size;i++) {
        arr[i] = rand() % 500;
    }

    // display(arr, size);

    printf("\nStarting the Sorting.");
    clock_t start = clock();
    QuickSort(arr, 0, size-1);
    clock_t end = clock();
    printf("\nSorting Done.");
    // display(arr, size);

    double time = ((double)(end-start)) / CLOCKS_PER_SEC;
    printf("\n\nQuickSort Sorted Array with size %d in %.8f Sec.",size, time);
    
    
}

int main() {
    srand(time(NULL));
    test();
    return 0;
}