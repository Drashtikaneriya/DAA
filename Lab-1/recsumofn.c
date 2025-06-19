#include<stdio.h>
int sum(int n){
    if(n==0){
        return 0;
    }
    else{
        return n+sum(n-1);
    }
}
void main(){
    int n;
    int ans;
    printf("enter num to sum ");
    scanf("%d",&n);
    ans=sum(n);
    printf("%d",ans);
}