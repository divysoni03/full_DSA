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

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = creatNode(data);
    if(*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    struct Node* curr = *head;
    while(curr->next != *head) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->next = *head;
    // *head = newNode; // if we un- comment this liked list will be printed reverse
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = creatNode(data);
    if(*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    struct Node* curr = *head;
    while(curr->next != *head) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->next = *head;
    *head = newNode; // if we un- comment this liked list will be printed reverse
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = creatNode(data);
    if (*head == NULL && position != 1) {
        printf("\nList is empty, so position out of bounds.");
        return;
    }

    if(position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* curr = *head;
    for(int i = 1; i < position - 1; i++) {
        if(curr->next == *head) {
            printf("\nPosition out of bounds, please enter a valid position.");
            return;
        }
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }
    struct Node* curr = *head;
    while(curr->next != *head) {
        curr = curr->next;
    }
    curr->next = temp->next;
    *head = temp->next;
    free(temp);
}
void deleteAtEnd(struct Node** head) {
    if(*head == NULL) {
        printf("List is empty.");
        return;
    }
    struct Node* temp = *head;
    if((*head)->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    struct Node* curr = *head;
    while(curr->next->next != *head) {
        curr = curr->next;
    }
    temp = curr->next;
    curr->next = temp->next;
    free(temp);
}
void deleteAtPosition(struct Node** head, int position) {
    if(*head == NULL && position < 1) {
        printf("\nList is empty or invalid position. ");
        system("pause");
        return;
    }
    struct Node* curr = *head;
    for(int i=1; i < position - 1; i++) {
        if(curr->next == *head) {
            printf("\nposition out of bound, please enter valid position. ");
            system("pause");
            return;
        }
        curr = curr->next;
    }
    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
}

void display(struct Node* head) {
    if(head == NULL) {
        printf("List is empty.");
        return;
    }

    struct Node* temp = head;
    printf("Linked list : head -> ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf(" head");
}

int main() {
    struct Node* head = NULL;
    int choice = 0, data, position;

    do {
        system("cls");
        display(head);
        printf("\n1.Insert At Beginning\n2.Insert At End\n3.Insert At Position\n4.Delete At Beginning\n5.Delete At End\n6.Delete At position\n0.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("\nEnter Data :");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("\nEnter Data: ");
                scanf("%d", &data);
                printf("\nEnter Position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6: 
                printf("\nEnter Position :");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 0:
                printf("\nExiting the program.");
                break;
            default:
                printf("\nInvalid input, please try again.");
                system("pause");
                break;
        }
    } while(choice != 0);
    free(head);
    return 0;
}
