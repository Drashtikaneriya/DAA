#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 10000

void main(){
     int i ; 
    int j ;
    int temp;
    int swap=0;
    FILE *file;
    clock_t start , end ;
    double cpu_time_used;
    int arr[MAX];
    //int n=1000;
    int min_idx ;
    int a;
    // file = fopen("worst.txt","r");
    // for(int i =0;i<1000;i++){
    //     fscanf(file, "%d",&arr[i]);
    // }
   
    printf("enter 1 to best case/n enter 2 worst case /n 3 avg case ");
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
        file = fopen("worst.txt","r");
        for(int i =0;i<MAX;i++){
        fscanf(file, "%d",&arr[i]);
        
    }
    break;
    case 3:
     file = fopen("avg.txt","r");
    for(int i =0;i<MAX;i++){
        fscanf(file, "%d",&arr[i]);
    }
        
        break;
    
    default:
    printf("enter valid number...!!!");
        break;
    }
     start = clock();
    for(int i = 0;i<MAX-1;i++){
        min_idx=i;
        for(int j = i+1;j<MAX;j++){
            if(arr[j]>arr[min_idx]){
                min_idx=j;
            }
            temp =arr[min_idx];
            arr[min_idx]=arr[i];
            arr[i]=temp;

        }
    }  
    end=clock();
    
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
     printf("%f",cpu_time_used);
}