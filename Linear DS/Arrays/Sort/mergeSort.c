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

/*
    @brief Perform merge of segments.
    @param a array to sort
    @param l left index for merge
    @param r right index for merge
    @param n total number of elements in the array
 */
void merge(int *a, int l, int r, int n)
{
    int *b = (int *)malloc(n * sizeof(int)); /* dynamic memory must be freed */
    if (b == NULL)
    {
        printf("Can't Malloc! Please try again.");
        exit(EXIT_FAILURE);
    }
    int c = l;
    int p1, p2;
    p1 = l;
    p2 = ((l + r) / 2) + 1;
    while ((p1 < ((l + r) / 2) + 1) && (p2 < r + 1)) {
        if (a[p1] <= a[p2]) {
            b[c++] = a[p1];
            p1++;
        } else {
            b[c++] = a[p2];
            p2++;
        }
    }

    if (p2 == r + 1) {
        while ((p1 < ((l + r) / 2) + 1)) {
            b[c++] = a[p1];
            p1++;
        }
    } else {
        while ((p2 < r + 1)) {
            b[c++] = a[p2];
            p2++;
        }
    }

    for (c = l; c < r + 1; c++) a[c] = b[c];

    free(b);
}

/*  Merge sort algorithm implementation
    @param a array to sort
    @param n number of elements in the array
    @param l index to sort from
    @param r index to sort till
*/
void merge_sort(int *a, int n, int l, int r) {
    if (r - l == 1) {
        if (a[l] > a[r])
            swap(&a[l], &a[r]);
    } else if (l != r) {
        merge_sort(a, n, l, (l + r) / 2);
        merge_sort(a, n, ((l + r) / 2) + 1, r);
        merge(a, l, r, n);
    }

    /* no change if l == r */
}

void test() {
    const int size = 100000;
    int *arr = (int *) calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  //-50 to 49
    }

    printf("\nSorting started!");
    clock_t start = clock();
    
    merge_sort(arr, size, 0, size-1);
    
    clock_t end = clock();
    printf("\nSorting Done.");
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nMerge sort took %.4f seconds to sort %d elements.\n", time_taken, size);

    for (int i = 0; i < size-1; i++) {
        assert(arr[i] <= arr[i+1]);
    }
    free(arr);
}

int main() {
    srand(time(NULL));  //initialize random number generator
    test();
    return 0;
}

/*
//Merge two subarrays of arr[]
//first subarray is arr[l..m]
//second subarray is arr[m+1..r]
void merge(int* arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid-left + 1;

    int n2 = right-mid;

    //Create temp arrays
    int L[n1], R[n2];

    //Copy data to temp array L[] and R[]
    for(i=0; i<n1; i++) {
        L[i] = arr[left+i];
    }
    for(j=0; j<n2; j++) {
        R[j] = arr[mid+1+j];
    }

    //Merge the temp arrays back into arr[l..r]
    i=0, j=0, k=left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //Copy the remaining elements of L[], if there are any
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int left, int right) {
    if(left < right) {
        //Same as (l+r)/2, but avoids overflow for large left and right
        int mid = (left + right)/2;

        //Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        //Merge the sorted halves
        merge(arr, left, mid, right);
    }
}
*/
/*
class Solution {
public:
    // Insertion Sort for small arrays
    void insertionSort(vector<int>& nums, int start, int end) {
        for (int i = start + 1; i <= end; ++i) {
            int key = nums[i];
            int j = i - 1;
            while (j >= start && nums[j] > key) {
                nums[j + 1] = nums[j];
                --j;
            }
            nums[j + 1] = key;
        }
    }

    // Optimized merge function using pre-allocated temporary array
    void merge(vector<int>& nums, vector<int>& temp, int start, int mid, int end) {
        int i = start;
        int j = mid + 1;
        int k = start;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        while (j <= end) {
            temp[k++] = nums[j++];
        }

        for (int l = start; l <= end; ++l) {
            nums[l] = temp[l];
        }
    }

    // Optimized mergeSort with insertion sort for small arrays
    void mergeSort(vector<int>& nums, vector<int>& temp, int start, int end) {
        if (end - start <= 15) { // Use insertion sort for small subarrays
            insertionSort(nums, start, end);
            return;
        }

        int mid = (start + end) / 2;
        mergeSort(nums, temp, start, mid);
        mergeSort(nums, temp, mid + 1, end);
        if (nums[mid] <= nums[mid + 1]) return; // Skip merge if already sorted
        merge(nums, temp, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> temp(size); // Pre-allocate temporary array
        mergeSort(nums, temp, 0, size - 1);
        return nums;
    }
};

*/