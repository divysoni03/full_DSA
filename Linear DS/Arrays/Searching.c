#include<stdio.h>
#include<stdlib.h>

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

// Searching methods
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int target) {
    int start = 0, end = size - 1, mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

// recursive way of binary search
// int binarySearch(int *arr, int low, int high, int target) {
//     // O(log n) -> time complexity
//     // O(1) -> space complexity (if recursive without optimization O(log n))

//     // Recursive Approach
//     if(high >= low) {
//         int mid = (low + high) / 2;

//         if(arr[mid] == target) {
//             return mid;
//         }
        
//         if(arr[mid] > target) {
//             return binarySearch(arr, low, mid-1, target);
//         } else {
//             return binarySearch(arr, mid+1, high, target);
//         }
//     }
//     return -1;
// }

// Printing array
void printArray(int arr[], int size) {
    printf("\nArray elements: { ");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b }\n");
}

// Generating random elements for array
int* generateArray(int size) {
    // int* arr = (int*)malloc(size * sizeof(int));
    int* arr = (int*)calloc(size, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

// Driver code
int main() {
    int size;
    printf("\nEnter size of the array: ");
    scanf("%d", &size);

    int* arr = generateArray(size);
    int target;
    insertionSort(arr, size);
    printArray(arr, size);

    printf("\nEnter target: ");
    scanf("%d", &target);

    int linearResult = linearSearch(arr, size, target);
    if (linearResult != -1) {
        printf("Target %d found at Index %d using Linear Search\n", target, linearResult);
    } else {
        printf("Target %d not found using Linear Search\n", target);
    }

    int binaryResult = binarySearch(arr, size, target);
    if (binaryResult != -1) {
        printf("Target %d found at Index %d using Binary Search\n", target, binaryResult);
    } else {
        printf("Target %d not found using Binary Search\n", target);
    }

    free(arr);

    return 0;
}
