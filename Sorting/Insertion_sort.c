#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int main() {
    int arr[SIZE];
    int choice;
    clock_t start, end;
    double cpu_time_used;

    printf("Insertion Sort CPU Time \n");
    printf("1. Best Case (Sorted)\n2. Average Case (Random)\n3. Worst Case (Reversed)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    start = clock();
    int i, key, j;
    for (i = 1; i < SIZE; i++) {
        key = arr[i];
        j = i - 1;

        // Shift elements
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
   
  
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %.3f seconds\n", cpu_time_used);

    return 0;
}
