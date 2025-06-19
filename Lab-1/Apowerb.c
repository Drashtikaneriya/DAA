#include<stdio.h>
void main(){
    int base,power,i,ans=1;
    printf("enter base");
    scanf("%d",&base);
      printf("enter power");
    scanf("%d",&power);
    for(i=1;i<=power;i++){
        ans*=base;
    }
    printf("%d",ans);
}