#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quick(int size,int *arr){

    int n=size;
    int p=0;;
    int i=0,j=n-1;
    if(n==1||n==0)
        return;
    while(1){
        if(i>=j){
            swap(arr,arr+j);
            break;
        }
        while(arr[p]>arr[i]){      
            i++;
            if(i>j)
                break;
        }
        while(arr[p]<arr[j]){
            j--;
            if(i>j)
                break;
        }
        swap(arr+i,arr+j);
    }
    quick(j,arr);
    quick(n-j-1,arr+j+1);
    return;
}
void main(){
    int n=6;
    int arr[]={6,4,5,3,2,1};
    quick(n,arr);
    int i,j;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}