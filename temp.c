#include <stdio.h>
 
#include <time.h>


void bubbleSort(int array[], int size) {
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
   
      
    time_t now = time(NULL);
    struct tm *currentDateTime = localtime(&now);

    
    printf("Enrollment Number:230130107107 \nName: Pattani divy \n");    printf("Current Date: %d-%d-%d\n", currentDateTime->tm_year + 1900, currentDateTime->tm_mon + 1, currentDateTime->tm_mday);
    printf("Current Time: %d:%d:%d\n", currentDateTime->tm_hour, currentDateTime->tm_min, currentDateTime->tm_sec);

    int arraySize;
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    int numbers[arraySize];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Original array: ");
    printArray(numbers, arraySize);

    bubbleSort(numbers, arraySize);

    printf("Sorted array: ");
    printArray(numbers, arraySize);
    
     
    return 0;
   
}
