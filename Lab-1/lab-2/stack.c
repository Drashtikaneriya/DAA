
// Stack Implement With METHODS : push , pop , peep , change and display



#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 100

    int arr[MAX];
    int top=-1;

void push(int value){
    if(top == (MAX-1)){
        printf("Stack Overflow !!!\n");
    }else{
        arr[++top]=value;
    }
}

int pop(){
    if(top==-1){
        printf("Stack Underflow !!!\n");
        return 0;
    }else{
        return arr[top--];
    }
}

int peep(int idx){
    if(top==-1){
        printf("Stack is Empty !!!\n");
        return 0;
    }
    if((top-idx + 1)< 0){
        printf("invalid index\n");
        return 0;
    }else{
        return arr[top-idx+1];
    }
}

void change(int idx , int value){
    if((top-idx +1)<0){
        printf("invalid index\n");
    }else{
        arr[top-idx +1]=value;
    }
}

void display(){
    if(top==-1){
        printf("Stack is Empty !!!\n");
    }else{
        printf("stack is : ");
        for(int i=0 ; i<=top ; i++){
        printf("%d ",arr[i]);
        }
        printf("\n");
    }
    
}


void main(){
    bool flag=true;
    int n;
    while(flag){
        printf("Enter 1 for add Element \n 2 for delete element \n 3 for peap element \n 4 for change element \n 5 for Display Stack \n Enter Anything else for terminate\n");
        scanf("%d" , &n);
        
        switch(n){
            case 1:{
                int x;
                printf("Enter Value to add :");
                scanf("%d" , &x);
                push(x);
                break;
            }
            

            case 2:{
                pop();
                break;
            }

            case 3:{
                int a;
                printf("Enter Index from top :");
                scanf("%d" , &a);
                int ans = peep(a);
                if(ans!=0){
                    printf("The Element of index %d from top : %d \n" , a,ans);
                }
                
                break;
            }
                

            case 4:{
                int i;
                printf("Enter Index from top :");
                scanf("%d" , &i);
                int j;
                printf("Enter Value to add :");
                scanf("%d" , &j);
                change(i,j);
                break;
            }
                

            case 5:{
                display();
                break;
            }
                

            default:{
                flag=false;
                printf("Terminated");
                break;
            }
            
        
        }
    }
}
