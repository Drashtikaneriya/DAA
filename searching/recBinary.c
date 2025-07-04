//implement binary search algorithm using recursion

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            return binarySearch(arr, mid + 1, right, x);
        } else { 
            return binarySearch(arr, left, mid - 1, x);
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[100000], n, x, result;
    FILE *file;
    clock_t start, end;
    double cpu_time_used;

    n = 100000; 

    file = fopen("Best.txt", "r");
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
    
    result = binarySearch(arr, 0, n - 1, x);
    
    end = clock();
    
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    
    printf("Time taken for binary search: %lf seconds\n", cpu_time_used);

 return 0;
}
