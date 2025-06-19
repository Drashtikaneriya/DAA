#include<stdio.h>
int Apowerb(int base,int power){
    if(power<0)
    {
        return -1 ;
    }
    else if(power==0){
        return 1;
    }
    else{
        return base*Apowerb(base,power-1);
    }
}
void main(){
    int base,power,i;
    printf("enter base");
    scanf("%d",&base);
      printf("enter power");
    scanf("%d",&power);
    int ans=Apowerb(base,power);
    printf("%d",ans);
}
