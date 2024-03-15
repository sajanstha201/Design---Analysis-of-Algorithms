#include<stdio.h>
#include<stdlib.h>
void combination(int *arr,int size,int r){
    int i,k=0;
    if(r==size){
        for(i=0;i<size;i++){
            printf("%d \t",arr[i]);
        }
        printf("\n");
        return;
    }
    int *left=(int*)malloc(sizeof(int)*size);
    int *right=(int*)malloc(sizeof(int)*(size-1));
    for(i=0;i<size;i++){
        left[i]=arr[i];
        if(i!=r){
            right[k]=arr[i];
            k++;
        }     
    }
    combination(left,size,r+1);
    combination(right,size-1,r);
    return;
}
void main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    combination(arr,n,0);
}