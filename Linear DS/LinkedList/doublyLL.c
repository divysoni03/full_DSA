#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* creatNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory Allocation Failed, please try again.");
        return NULL;
    }
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = creatNode(data);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    (*head)->prev = newNode;
    newNode->next = *head;

    *head = newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = creatNode(data);
    struct Node* curr = *head;
    if(*head == NULL) {
        *head = newNode;
        return; 
    }
    while(curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->prev = curr;
}
void insertAtPosition(struct Node** head, int data, int position) {
    if(position < 1) {
        printf("Invalid Position, please Try again.");
        return;
    }
    struct Node* newNode = creatNode(data);
    if(position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* curr = *head;
    for(int i=1; i<position-1; i++) {
        if(curr == NULL) {
            printf("Position is out of bound, please enter valid position.");
            return;
        }
        curr = curr->next;
    }
    newNode->next = curr->next;
    (curr->next)->prev = newNode;
    newNode->prev = curr;
    curr->next = newNode;
}
void deleteAtBeginning(struct Node** head) {
    if(*head == NULL) return;
    if((*head)->next == NULL) {
        struct Node* temp = *head;
        *head = NULL;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}
void deleteAtEnd(struct Node** head) {
    if(*head == NULL) return;
    if((*head)->next == NULL) {
        struct Node* temp = *head;
        *head = NULL;
        free(temp);
    }
    struct Node* curr = *head;
    while(curr->next->next != NULL) {
        curr = curr->next;
    }
    struct Node* temp = curr->next;
    curr->next = NULL;
    free(temp);
}
void deleteAtPosition(struct Node** head, int position) {
    if(*head == NULL) return;
    if(position < 1) {
        printf("\nInvalid Position, please enter Valid position.");
        return;
    }
    struct Node* curr = *head;
    for(int i=1; i<position-1; i++) {
        if(curr == NULL) {
            printf("\nPosition out of Bounds, please Enter Valid position.");
            return;
        }
        curr = curr->next;
    }
    struct Node* temp = curr->next;
    curr->next = temp->next;
    (temp->next)->prev = curr;
    free(temp);
}
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;
    while(curr != NULL) {
        next = curr->next; // saving next node
        curr->next = prev; // modifying connection
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
void printFromEnd(struct Node* head) {
    if(head == NULL) return;
    printFromEnd(head->next);
    printf(" <- %d -> ", head->data);
}

int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

void print(struct Node* head) {
    printf("\nLinkedList : head ");
    while(head != NULL) {
        printf("<- %d -> ", head->data);
        head = head->next;
    }
    printf(" NULL");
}
int main() {
    struct Node* head = NULL;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    
    int choice = 0,data = 0, position = 0;
    do {
        system("cls");
        printf("\nName : pattani divy chetanbhai");
        printf("\nEnrollment number : 230130107107");
        printf("\nCurrent date : %02d-%02d-%04d\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        print(head);
        printf("\n1.Insert At Beginning");
        printf("\n2.Insert At End");
        printf("\n3.Insert At Postion");
        printf("\n4.Delete At Beginning");
        printf("\n5.Delete At End");
        printf("\n6.Delete At Position");
        printf("\n7.reverse Linked list");
        printf("\n8.get length");
        printf("\n9.printing in reverse order");
        printf("\nEnter Your Choice :");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Data :");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("\nEnter Data :");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("\nEnter Data :");
                scanf("%d", &data);
                printf("\nEnter Position :");
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
            case 7:
                reverseList(&head);
                break;
            case 8:
                printf("Linked list length : %d\n", getLength(head));
                system("pause");
                break;
            case 9:
                printf("List : NULL ");
                printFromEnd(head);
                printf(" head");
                system("pause");
                break;
            case 0:
                printf("Exiting the program.");
                free(head);
                break;
            default : 
                printf("Invalid Input, please Try again.");
                break;
        }
    }while(choice != 0);
    return 0;
}



// #include<stdio.h>
// #include<stdlib.h>

// typedef struct Node* node;
// struct Node {
//     int data;
//     node prev;
//     node next;
// };

// node createNode(int data) {
//     node newNode = (node)malloc(sizeof(struct Node));
//     if (newNode == NULL) {
//         printf("\nMemory Allocation Failed!");
//         exit(1);
//     }
//     newNode->prev = NULL;
//     newNode->data = data;
//     newNode->next = NULL;

//     return newNode;
// }

// // Insert At Front
// node insertAtFront(node head, int data) {
//     node newNode = createNode(data);
//     newNode->next = head;

//     if(head != NULL) {
//         head->prev = newNode;
//     }
//     return newNode;
// }

// node insertAtEnd(node head, int data) {
//     node newNode = createNode(data);

//     if(head == NULL) {
//         return newNode;
//     }

//     node curr = head;
//     while(curr->next != NULL) {
//         curr = curr->next;
//     }

//     curr->next = newNode;
//     newNode->prev = curr;

//     return head;
// }

// void printForward(node head) {
//     printf("\nJust List > \tNULL <-> ");
//     while(head != NULL) {
//         printf("%d <-> ", head->data);
//         head = head->next;
//     }
//     printf("NULL\n\n");
// }

// int main() {
//     node list = NULL;

//     // list = insertAtFront(list, 11);
//     // list = insertAtFront(list, 12);
//     // list = insertAtFront(list, 13);
//     // list = insertAtFront(list, 14);
//     // list = insertAtFront(list, 15);
//     // list = insertAtFront(list, 16);
//     // list = insertAtFront(list, 17);
//     // list = insertAtFront(list, 18);
//     // list = insertAtFront(list, 19);
//     // list = insertAtFront(list, 20);

//     list = insertAtEnd(list, 11);
//     list = insertAtEnd(list, 12);
//     list = insertAtEnd(list, 13);
//     list = insertAtEnd(list, 14);
//     list = insertAtEnd(list, 15);
//     list = insertAtEnd(list, 16);
//     list = insertAtEnd(list, 17);
//     list = insertAtEnd(list, 18);
//     list = insertAtEnd(list, 19);
//     list = insertAtEnd(list, 20);

//     printForward(list);
// }