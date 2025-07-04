//write a program to implement binary search algorithm.
//use best.txt to search and note the time taken

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int n, int x) {

    int left = 0, right = n - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid; 
        }

        if (arr[mid] < x) {
            left = mid + 1;
        }
        
        else { 
            right = mid - 1;
        }

    }

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
    
    result = binarySearch(arr, n, x);
    
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
