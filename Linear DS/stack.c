// All programs of stack in this file
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> // for using boolean in c, boolean is not defaultly available in c

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    if(top == -1) return true;
    else return false;
}
bool isFull() {
    if(top == MAX_SIZE - 1) return true;
    else return false; 
}
int getLength() {
    int count = 0;
    for(int i=top; i>=0; i--) count++;
    return count;
}

void push(int data) {
    if(isFull()) {
        printf("Stack overFlow.");
        system("pause");
        return;
    }
    stack[++top] = data;
}
void pop() {
    if(isEmpty()) {
        printf("Stack underflow.");
        return;
    }
    printf("\n%d Removed from the stack.", stack[top--]);
    system("pause");
}
int peep() {
    if(isEmpty()) {
        printf("Stack Underflow.");
        return -1;
    }
    else return stack[top];
}
void display() {
    if(isEmpty()) {
        printf("\nStack UnderFlow.");
        return;
    }
    printf("Stack : ");
    for(int i=top; i>=0; i--) {
        printf("%d, ", stack[i]);
    }
    printf("\b\b");
}
/*
    @brief The main tester or driver function
    @prams choice making choice what to do 
    @prams data for inputting data
*/
int main() {
    int choice, data;
    do {
        system("cls");
        display();
        printf("\n\n1.Push\n2.Pop\n3.Peek/Peep\n4.display\n5.length\n6.isEmpty\n7.isFull\nEnter Choice :");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter your Data :");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("First ELement in Stack : %d\n", peep());
                system("pause");
                break;
            case 4:
                display();
                system("pause");
                break;
            case 5:
                printf("Length Of the stack is : %d", getLength());
                system("pause");
                break;
            case 6:
                printf(isEmpty()? "Stack is Empty." : "Stack is Not Empty.");
                system("pause");
                break;
            case 7:
                printf(isFull()? "Stack is Full." : "Stack is Not Full.");
                system("pause");
                break;
            case 0:
                system("cls");
                printf("\nExiting the program...");
                break;
            default :
                printf("\nInvalid Input, please Try again.\n");
                system("pause");
                break;  
        }
    }while(choice != 0);
}
