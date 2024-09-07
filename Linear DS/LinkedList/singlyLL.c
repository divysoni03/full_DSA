#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("\nMemory Allocation Failed, please Try again.");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {    
    struct Node* newNode = createNode(data);
    if(*head == NULL) {*head = newNode;return;}
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {*head = newNode;return;}
    struct Node* tempNode = *head;
    while (tempNode->next != NULL) {
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
}
void insertAtPosition(struct Node** head, int data, int position) {
    if(position < 1) {printf("Invalid Position.\n");return;}

    struct Node* newNode = createNode(data);
    if(position == 1) {newNode->next = *head;*head = newNode;return;}

    struct Node* temp = *head;
    for (int i = 1; i < position - 1; i++) {
        if(temp == NULL) {
            printf("Position is out of bounds.\n");
            return;
        }
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Position is out of bounds.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
int searchByValue(struct Node* head, int key) {
    int count = 0;
    while(head != NULL) {
        if (head->data == key) {
            return count;
        }
        count++;
        head = head->next;
    }
    return 0;
}
int getLength(struct Node* head) {
    int length = 0;
    while(head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
void deleteAtBeginning(struct Node **head) {
    if(*head == NULL) return;

    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}
void deleteAtEnd(struct Node **head) {
    if(*head == NULL) return;
    struct Node* temp = *head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void deleteAtPosition(struct Node** head, int position) {
    if(position < 1) {
        printf("\nInvalid Position, Please Try again with Valid Position.");
        return;
    }
    if(position == 1) {
        struct Node* temp = *head;
        *head = NULL;
        free(temp);
        return;
    }

    struct Node* curr = *head;
    for(int i=1; i<position-1; i++) {
        if(curr == NULL) {
            printf("\nPosition is Out of Bound.");
            return;
        }
        curr = curr->next;
    }
    if(curr == NULL) {
        printf("\nPostion is out of Bound.");
        return;
    }
    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
}
void printFromLast(struct Node* head) {
    if(head == NULL) return;
    printFromLast(head->next);
    printf(" <- %d", head->data);
}

void printList(struct Node* head) {
    printf("\nList: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
// input : 2 22 2 23 2 24 2 25 2 26 2 27 1 21
int main() {
    int choice, data, position, key;
    struct Node* head = NULL;

    while (1) {
        system("cls");
        printList(head);

        printf("\n\n\n1. Insert at beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Search By Value");
        printf("\n5. Length of the list");
        printf("\n6. Reverse the List");
        printf("\n7. Delete at beginning");
        printf("\n8. Delete at end");
        printf("\n9. Delete at Position");
        printf("\n10. Print list from beginning");
        printf("\n11. Print list from end");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;

        case 2:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;

        case 3:
            printf("\nEnter the position: ");
            scanf("%d", &position);
            printf("\nEnter the data: ");
            scanf("%d", &data);
            insertAtPosition(&head, data, position);
            break;

        case 4:
            printf("\nEnter the key to search from the list: ");
            scanf("%d", &key);
            int index = searchByValue(head, key);
            (index>0) ? printf("\n%d present in the list At %d index.\n", key, index) : printf("\n%d is not present in the list.\n", key);
            system("pause");
            break;

        case 5:
            printf("\nLength of the list: %d\n", getLength(head));
            system("pause");
            break;

        case 6:
            reverseList(&head);
            break;

        case 7:
            deleteAtBeginning(&head);
            break;

        case 8:
            deleteAtEnd(&head);
            break;

        case 9:
            printf("\nEnter the position to delete the node: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;

        case 10:
            printList(head);
            break;

        case 11:
            printf("\nList from End: ");
            printf("NULL");
            printFromLast(head);
            printf(" <- Head\n");
            system("pause");
            break;

        case 0:
            printf("\nExiting...\n");
            exit(0);

        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
        }
    }

    return 0;
}
