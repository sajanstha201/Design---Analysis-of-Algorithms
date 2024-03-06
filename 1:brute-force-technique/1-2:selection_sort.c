#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int opcount;
int * selectionSort(int *arr,int size){
    int i,j,k,temp;
    for(i=0;i<size-1;i++){
        for(j=i;j<size;j++){
            opcount++;
            if(arr[k]>arr[j])
                k=j;
        }
        temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
    }
    return arr;
}
void main(){
    int n;
    printf("Enter the number of element:");
    scanf("%d",&n);
    int i,j;
    int arr[n];
    printf("Enter the element: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    opcount=0;
    time_t start,end;
    start=clock();
    int * sorted=selectionSort(arr,n);
    end=clock();
    double totaltime=(end-start)/CLOCKS_PER_SEC;
    printf("Sorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nTotal time : %e\n",totaltime);
    printf("Opcount : %d\n",opcount);
}