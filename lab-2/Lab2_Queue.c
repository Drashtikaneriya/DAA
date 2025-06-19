#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
    } else {
        if (front == -1) front = 0; // Initialize front
        queue[++rear] = value;
        printf("Enqueued %d into queue\n", value);
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return -1;
    } else {
        int value = queue[front++];
        printf("Dequeued %d from queue\n", value);
        return value;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek(int index) {
    int pos = front + index;
    if (front == -1 || pos > rear || pos < front) {
        printf("Invalid index\n");
    } else {
        printf("Element at index %d: %d\n", index, queue[pos]);
    }
}

void change(int index, int value) {
    int pos = front + index;
    if (front == -1 || pos > rear || pos < front) {
        printf("Invalid index\n");
    } else {
        queue[pos] = value;
        printf("Changed element at index %d to %d\n", index, value);
    }
}

void main() {
    int choice, value, index;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Change\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter index to peek (starting from 0): ");
                scanf("%d", &index);
                peek(index);
                break;
            case 5:
                printf("Enter index to change (starting from 0): ");
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
