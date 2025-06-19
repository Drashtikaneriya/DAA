#include <stdio.h>

void fibonacci_iterative(int n) {
    int a = 0, b = 1, next;
    
    printf("Fibonacci Series (Iterative): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
}

int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    fibonacci_iterative(n);
    return 0;
}
