#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enQueue(int data) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is overflow.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
}

void deQueue() {
    if (front == -1) {
        printf("Queue is Empty.\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

int peep() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];
}

void display() {
    if (front == -1) {
        printf("\nQueue is empty.");
        return;
    }
    
    printf("\nQueue: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d ", queue[rear]);
}

int main() {
    int choice = 0, data;
    do {
        system("cls");
        display();
        printf("\n1.Enqueue\n2.Dequeue\n3.Peep\n0.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Your Data: ");
                scanf("%d", &data);
                enQueue(data);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                printf("First Element: %d\n", peep());
                system("pause");
                break;
            case 0:
                printf("\nExiting the program.\n");
                break;
            default:
                printf("Invalid input, please try again.\n");
                system("pause");
                break;
        }
    } while (choice != 0);
    return 0;
}
