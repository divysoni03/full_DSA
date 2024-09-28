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
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("\nMemory Allocation failed, please try again.");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;

    return newNode; 
}

void enQueue(struct Node **head, int data) {
    struct Node* newNode = createNode(data);
    if((*head) == NULL) {
        *head = newNode;
        return;
    }
    struct Node* curr = *head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}
void deQueue(struct Node **head) {
    if(*head == NULL) {
        printf("\nQueue is empty.");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    printf("\n%d Removed from the Queue.", temp->data);
    free(temp);
}
void display(struct Node* head) {
    if(head == NULL) {
        printf("\nQueue : is Empty.");
        return;
    }
    struct Node* curr = head;
    printf("\nQueue : ");
    while(curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int main() {
    struct Node* head = NULL;
    int choice = 0, data;

    do {
        system("cls");
        display(head);
        printf("\n\n1.Enqueue\n2.Dequeue\n0.Exit\nEnter Your choice :");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Data :");
                scanf("%d", &data);
                enQueue(&head, data);
                break;
            case 2:
                deQueue(&head);
                break;
            case 0:
                printf("\nExiting the program...");
                break;
            default:
                printf("\nInvalid input, please try again.");
                system("pause");
                break;
        }
    }while(choice != 0);
    return 0;
}