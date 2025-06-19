#include<stdio.h>
void main(){
    int n,i;
    int sum=0;
    printf("enter number :");
    scanf("%d",&n);
    if(n<0){
        printf("negitive number ");
    }
    else{
        for(i=1;i<=n;i++){
            sum+=i;
        }
        printf("%d",sum);

    }
}