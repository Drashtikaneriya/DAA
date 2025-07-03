#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Heapify function
void heapify(int arr[], int n, int i) {
    int largest = i;         // root
    int left = 2 * i + 1;    // left child
    int right = 2 * i + 2;   // right child

    if (left < n && arr[left] > arr[largest])
        largest = left;
        
    if (right < n && arr[right] > arr[largest])
        largest = right;
        
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        //  sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void main() {
    int arr[MAX];
    int choice;
    FILE *file;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter 1 for Best Case\nEnter 2 for Average Case\nEnter 3 for Worst Case\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            file = fopen("best.txt", "r");
            break;
        case 2:
            file = fopen("avg.txt", "r");
            break;
        case 3:
            file = fopen("worst.txt", "r");
            break;
        default:
            printf("Enter a valid number...!!!\n");
            return;
    }

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < MAX; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    start = clock();
    heapSort(arr, MAX);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Heap Sort: %f seconds\n", cpu_time_used);
}
