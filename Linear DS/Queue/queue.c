/*
QUEUE INTRO THEORY :-

Queue Data Structure: Follows the FIFO (First In First Out) principle.

> Simple (One ended) queue
> Double Ended Queue (Deque)

Basic Operations performed on a queue:
    1. Enqueue (Insertion at the end)
    2. Dequeue (Deletion from the front)
    3. Front (Peek)
    4. Rear (Peek)
    5. isEmpty
    6. isFull

Applications of Queue:
    1. CPU Scheduling
    2. Disk Scheduling
    3. Simulations
    4. Call Center Phone Systems
    5. Handling of Interrupts in real time systems
    6. Traffic Management
    7. Asynchronous Data Transfer
    8. IO Buffers
    9. Accessing shared resources in a multi-threaded environment
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void enque(struct Queue *q, int value) {
    if (q->rear == MAX_SIZE - 1) printf("\nQueue is full");
    else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

void deque(struct Queue *q) {
    if (q->front == -1) printf("\nQueue is empty");
    else {
        printf("\nDequeued element: %d", q->items[q->front]);
        if (q->front == q->rear) q->front = q->rear = -1;
        else q->front++;
    }
}

int peekFront(struct Queue *q) {
    if (q->front == -1) printf("\nQueue is empty");
    else return q->items[q->front];
}

int peekRear(struct Queue *q) {
    if (q->front == -1) printf("\nQueue is empty");
    else return q->items[q->rear];
}

void display(struct Queue *q) {
    if (q->rear == -1) printf("\nQueue is empty");
    else {
        printf("\nQueue elements are: ");
        for (int i = q->front; i <= q->rear; i++) printf("%d ", q->items[i]);
        printf("\n");
    }
}

int main() {
    struct Queue q;
    q.front = q.rear = -1;

    int choice, value;

    do {
        system("cls");
        display(&q);
        printf("\n\nQueue Menu: \n");
        printf("\n1. Enque");
        printf("\n2. Deque");
        printf("\n3. Peekfront and Peekrear");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter value to enqueue: ");
            scanf("%d", &value);
            enque(&q, value);
            break;

        case 2:
            deque(&q);
            printf("\n");
            break;

        case 3:
            printf("\nPeekfront: %d", peekFront(&q));
            printf("\nPeekrear: %d", peekRear(&q));
            printf("\n");
            break;

        case 4:
            display(&q);
            break;

        case 5:
            printf("\nExiting...\n");
            break;
        
        default:
            break;
        }
        printf("\n");
        // system("pause");
    } while (choice != 5);
    
}