#include <stdio.h>
int countDigits(int num) {
     if (num == 0)
        return 0;

    return 1 + countDigits(num / 10);
}
void main (){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Total digits: %d\n", countDigits(num));
}