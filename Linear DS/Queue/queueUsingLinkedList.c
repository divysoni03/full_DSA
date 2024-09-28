/*
    QUEUE - when we insert element then it inserts at end and when we remove one then it removes from the 
            front so as we know from ago (linked list) we will use insert at end and delete at beginning methods
            make this queue implementation using linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* creatNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("\nMemory Allocation failed, please try again.");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;

    return newNode; 
}

int main() {
    struct Node* head = NULL;
    return 0;
}