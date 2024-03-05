#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int * a,int * b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int opcount;
void quicksort(int *arr,int size){
    int pivot=0;
    if(size==1||size==0)
        return;
    int i=0,j=size-1;
    while(1){
        opcount++;
        if(i>=j){
            opcount++;
            swap(arr+pivot,arr+j);
            break;
        }
        while(arr[pivot]>arr[i]){
            i++;
            if(i>j)
                break;
        }
        while(arr[pivot]<arr[j]){
            j--;
            if(i>j)
                break;
        }  
        swap(arr+i,arr+j);
    }
    quicksort(arr,j);
    quicksort(arr+j+1,size-j-1);
    return;
}
void main(){
    int n,i;
    printf("Total number of element: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter element: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    time_t start,end;
    double totaltime;
    start=clock();
    end=clock();
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    quicksort(arr,n);
    printf("The sorted array is :\n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\nThe opcount is %d\n",opcount);
    printf("The time of execution is %e\n",totaltime);
}