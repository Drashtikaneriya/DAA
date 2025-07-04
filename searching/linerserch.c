//write a program to implement linear search algorithm.
//use best.txt to search and note the time taken

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int arr[100000], n, x, result;
    FILE *file;
    clock_t start, end;
    double cpu_time_used;

    n = 100000; 

    file = fopen("best.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    printf("Enter the element to search: ");
    scanf("%d", &x);

    start = clock();
    
    result = linearSearch(arr, n, x);
    
    end = clock();
    
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    
    printf("Time taken for linear search: %f seconds\n", cpu_time_used);

    return 0;

}
