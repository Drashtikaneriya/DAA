#include<stdio.h>
int fact(int n ){
    if(n==0||n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
void main(){
    int n ;
    printf("enter num to find fact: ");
    scanf("%d",&n);
    int fac=fact(n);
    printf("%d",fac);
}