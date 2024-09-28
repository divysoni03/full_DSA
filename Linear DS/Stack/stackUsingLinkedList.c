#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* creatNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("\nMemory Allocation Failed, please try again. ");
        system("pause");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
}
void push(struct Node** head, int data) {
    struct Node* newNode = creatNode(data);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}
void pop(struct Node** head) {
    if(*head == NULL) {
        printf("\nStack is empty.");
        return;
    }
    struct Node* temp = *head;
    
    if((*head)->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    
    *head = temp->next;
    free(temp);
}
int peep(struct Node* head) {
    if(head == NULL) {
        printf("\nStack is empty.");
        return -1;
    }
    return head->data;
}

void display(struct Node* head) {
    struct Node* temp = head;
    printf("List : ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice =0, data;

    do {
        system("cls");
        display(head);
        printf("\n1.Push\n2.Pop\n3.Peep\n0.Exit\nEnter Your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Your Data :");
                scanf("%d", &data);
                push(&head, data);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                printf("\nTop Element : %d\n", peep(head));
                system("pause");
                break;
            case 0:
                printf("\nExiting the program.");
                break;
            default :
                printf("\nInvalid input, please try again. ");
                system("pause");
                break;
        }
    }while(choice != 0);
    return 0;
}