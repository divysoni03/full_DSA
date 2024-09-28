/*
    THIS IS PROGRAM FOR CIRCULAR AND DOUBLE ENDED QUEUE

    * KEY FEATURE -
        1.insert at front
        2.insert at end
        3.delete at front
        4.delete at end
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 10

/* Defining the struct and init function */
struct Queue {
    int queue[MAX_SIZE];
    int front;
    int rear;
};
struct Queue createQueue() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

/* other algo functions */
bool isFull(struct Queue q) {
    return q.front == q.rear;
}
bool isEmpty(struct Queue q) {
    return q.front == -1 && q.rear == -1;
}
void insertAtEnd(struct Queue *q, int data) {
    // checks if the next index of the rear is front is yes then it's overflow.
    if((q->rear + 1)%MAX_SIZE == q->front) {
        printf("\nQueue is overflow.");
        system("pause");
        return;
    }
    // if the front is -1 then the list is empty then initialize it.
    if(q->front == -1) {
        q->front = 0;
    }
    // OR increment the rear pointer and set the data
    // the %max is setting the rear to zero if the rear becomes reaches the max size
    // by doing modulo the remainder will be returned so in this case zero will be returned if rear becomes the max_size (same number's modulo is zero, 5/5 remainder will be zero)
    q->rear = (q->rear+1)%MAX_SIZE;
    q->queue[q->rear] = data;
}
void insertAtFront(struct Queue* q, int data) {
    /* if both will come at one position then queue is overflow */
    if(q->front - 1 == q->rear) {
        printf("\nQueue is overflow.");
        system("pause");
        return;
    }
    if(q->front == -1) {
        q->front = q->rear = 0;
    }
    else if(q->front == 0) {
        q->front = MAX_SIZE - 1; // moving the pointer to the end so we can add ahead
    }
    else {
        /* if the front is zero then it will move to the end and we can add there add if we want to add more then its not zero until we will add data */
        q->front--;
    }
    q->queue[q->front] = data; // add the data to the new position.
}
void deleteAtFront(struct Queue *q) {
    if(q->front == -1) {
        printf("\nQueue is underflow.");
        system("pause");
        return;
    }
    if(q->front == q->rear) {
        q->front = q->rear = -1;
        return;
    }
    // printf("Removed %d data from the queue.", q->queue[q->front]);
    q->front = ((q->front) + 1)%MAX_SIZE;
}
void deleteAtEnd(struct Queue *q) {
    if(q->front == -1) {
        printf("\nQueue is underflow.");
        system("pause");
        return;
    }
    if(q->front == q->rear) {
        q->front = q->rear = -1;
        return;
    }
    q->rear--;
}
int peepAtFront(struct Queue q) {
    if(q.front == -1) {
        printf("\nQueue is underflow.");
        return -1;
    }
    return q.queue[q.front];
}
int peepAtEnd(struct Queue q) {
    if(q.front == -1) {
        printf("\nQueue is underflow.");
        return -1;
    }
    return q.queue[q.rear];
}
void displayQueue(struct Queue q) {
    if(q.front == -1) {
        printf("Queue is Empty.");
        return;
    }

    printf("\nQueue: ");
    int i = q.front;
    while (i != q.rear) {
        printf("%d ", q.queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d ", q.queue[q.rear]);
}

int main() {
    struct Queue q = createQueue();

    int choice = 0, data;

    do {
        system("cls");
        displayQueue(q);
        printf("\n\n1.Add At front\n2.Add At end\n3.delete At front\n4.delete At end\n5.Peep At front\n6.Peep At end\n7.is Full\n8.is Empty\n0.exit\nEnter Your choice :");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Data :");
                scanf("%d", &data);
                insertAtFront(&q, data);
                break;
            case 2:
                printf("\nEnter Data :");
                scanf("%d", &data);
                insertAtEnd(&q, data);
                break;
            case 3:
                deleteAtFront(&q);
                break;
            case 4:
                deleteAtEnd(&q);
                break;
            case 5:
                printf("Element At Front : %d", peepAtFront(q));
                system("pause");
                break;
            case 6:
                printf("Element At End : %d", peepAtEnd(q));
                system("pause");
                break;
            case 7:
                printf(isFull(q)? "Queue is full." : "Queue is not Full");
                system("pause");
                break;
            case 8:
                printf(isEmpty(q)? "Queue is Empty." : "Queue is not Empty.");
                system("pause");
                break;
            case 0:
                printf("\nExiting the program...");
                break;
        }
    }while(choice != 0);
    return 0;
}