#include<stdio.h>
#include<time.h>
#include<stdlib.h>


#define MAX 10000
void main(){
    int i ; 
    int j ;
    int temp;
    int swap=0;
   int a;
    FILE *file;
    clock_t start , end ;
    double cpu_time_used;
    int arr[MAX];
    
    printf("enter 1 to best case/n enter 2 avg case /n 3 worst case ");
    scanf("%d",&a);
    switch (a)
    {
    case 1 :
        file = fopen("best.txt","r");
         for(int i =0;i<MAX;i++){
        fscanf(file, "%d",&arr[i]);
     
    }
       break;
    case 2 :
        file = fopen("avg.txt","r");
        for(int i =0;i<MAX;i++){
        fscanf(file, "%d",&arr[i]);
        
    }
    break;
    case 3:
     file = fopen("worst.txt","r");
    for(int i =0;i<MAX;i++){
        fscanf(file, "%d",&arr[i]);
    }
        
        break;
    
    default:
    printf("enter valid number...!!!");
        break;
    }
    start = clock();
    for(i=0;i<MAX-1 ; i++){
        swap = 0;
        for (j=0;j<MAX-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=1;
            }
        }
        if(swap==0){
          break;
        }
    
    }
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("%f",cpu_time_used);
}


