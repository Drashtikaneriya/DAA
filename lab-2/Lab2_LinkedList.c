//write a program to make linked list in C and make functions to insert at last, delete at last, display the linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* first = NULL;

void insertAtLast(int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (first == NULL) {
        first = newNode;
    } else {
        struct Node* temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
   
}

void deleteAtLast() {
    if (first == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (first->next == NULL) {
        free(first);
        first = NULL;
        return;
    }

    struct Node* temp = first;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    free(temp->next);
    temp->next = NULL;
}

void display() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = first;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Last\n");
        printf("2. Delete at Last\n");
        printf("3. Display Linked List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtLast(value);
                break;
            case 2:
                deleteAtLast();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}