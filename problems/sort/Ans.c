#include <stdio.h>
#include <string.h>

void swap(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void sort(char str[][100], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                swap(&str[i], &str[j]);
            }
        }
    }
}

int main() {
    char str[][100] = {"apple", "Banana", "grape", "cherry", "Apricot", "Apple"};
    int s = sizeof(str) / sizeof(str[0]);
    
    system("cls");
    printf("Before : ");
    for (int i = 0; i < s; i++) {
        printf("%s, ", str[i]);
    }

    sort(str, s);
    
    printf("\nAfter  : ");
    for (int i = 0; i < s; i++) {
        printf("%s, ", str[i]);
    }
    
    printf("\nNumber of strings: %d\n", s);
    return 0;
}
