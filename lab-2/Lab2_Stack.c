//write a program to implement a stack using an array in C and make functions to push, pop, display, peep and change the stack elements.
#include <stdio.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) 
    {
        printf("Stack overflow\n");
    } 
    else 
    {
        stack[++top] = value;
        printf("Pushed %d onto stack\n", value);
    }
}

int pop() {
    if (top < 0) 
    {
        printf("Stack underflow\n");
        return -1;
    } 
    else 
    {
        int value = stack[top--];
        printf("Popped %d from stack\n", value);
        return value;
    }
}

void display() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void peep(int index) {
    if (index < 0 || index > top) {
        printf("Invalid index\n");
    } else {
        printf("Element at index %d: %d\n", index, stack[index]);
    }
}

void change(int index, int value) {
    if (index < 0 || index > top) {
        printf("Invalid index\n");
    } else {
        stack[index] = value;
        printf("Changed element at index %d to %d\n", index, value);
    }
}

void main() {
    int choice, value, index;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peep\n");
        printf("5. Change\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter index to peep: ");
                scanf("%d", &index);
                peep(index);
                break;
            case 5:
                printf("Enter index to change: ");
                scanf("%d", &index);
                printf("Enter new value: ");
                scanf("%d", &value);
                change(index, value);
                break;
            case 6:
                return;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}






