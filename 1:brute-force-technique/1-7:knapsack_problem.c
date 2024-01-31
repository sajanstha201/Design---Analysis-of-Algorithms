/*
Given 'n' items of known weights w1,w2,...,wn and values v1,v2,...,vn and 
a knapsack of capacity W, find the most valuable subset of the items that fit
into the knapsack.
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int power(int a,int b){
    int i;
    int value=1;
    for(i=0;i<b;i++)
        value=value*a;
    return value;
}
int knapsack(int *w,int*v,int c,int n){
    int i,k,binary,maxValue=0;
    int totalSubset=power(2,n);
    int weight=0,value=0,finalIndex=0,opcount=0;
    for(i=0;i<totalSubset;i++){
        ++opcount;
        weight=0;
        value=0;
        binary=i;
        k=0;
        while(binary){
            if(binary&0x1){
                value+=v[k];
                weight+=w[k];
            }
            binary=binary>>1;
            k++;
        }
        if(value>maxValue&&weight<=c){
            maxValue=value;
            finalIndex=i;
        }
    }
    printf("The opcount is %d\n",opcount);
    return finalIndex;
}
int main(){
    printf("%d\n",8&0x1);
    int element,i,capacity;
    printf("KNAPSACK PROBLEM USING BRUTE FORCE TECHNIQUE\n");
    printf("Enter the total number of element: ");
    scanf("%d",&element);
    int *w=(int*)malloc(sizeof(int)*element);
    int *v=(int*)malloc(sizeof(int)*element);
    printf("Enter the capacity of knapsack:");
    scanf("%d",&capacity);
    printf("Enter the weight: ");
    for(i=0;i<element;i++){
        scanf("%d",(w+i));
    }
    printf("Enter the value: ");
    for(i=0;i<element;i++){
        scanf("%d",(v+i));
    }
    double totaltime;
    time_t start,end;
    start=clock();
    int index=knapsack(w,v,capacity,element);
    end=clock();
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The total time is %e\n",totaltime);

    int finalweight=0,finalvalue=0,binary,k=0;
    printf("The knapsack are:\n");
    while(index){
        if(index&0x1){
            printf("weight: %d \t value: %d\n",w[k],v[k]);
            finalweight+=w[k];
            finalvalue+=v[k];
        }
        index=index>>1;
        k++;
    }
    printf("\nThe final value is %d\n ",finalvalue);
    printf("\nThe final weight is %d\n",finalweight);
}