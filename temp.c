#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int start, int end) {
    int pivot = arr[end], i = start -1;
    for(int j=start; j<end-1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[end]);
    return i+1;
}
void quickSort(int *arr, int start, int end) {
    if(start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}

void testFunction() {
    int size = 10000;
    int *arr = (int *)calloc(size, sizeof(int));

    for(int i=0; i<size; i++) {
        arr[i] = rand() % 1000;
    }

    printf("\nSorting Started.");
    clock_t start = clock();
    quickSort(arr, 0, size-1);
    clock_t end = clock();
    printf("\nSorting Done.");

    double time = ((double)(end-start)) / CLOCKS_PER_SEC;
    printf("\nQuick Sort Took %.8f sec to sort %d size of array.", time, size); 

}

int main() {
    srand(time(NULL)); //makes random element based on local time
    testFunction();
    return 0;
}