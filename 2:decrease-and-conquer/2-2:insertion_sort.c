#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int* insertionSort(int *arr,int n){
    int i,j,temp;
    int opcount=0;
    for(i=1;i<n;i++){
        j=i;
        while(arr[j-1]>arr[j]){
            ++opcount;
            temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
    printf("The opcount is %d\n",opcount);
    return arr;
}
void main(){
    int n,i;
    int *sorted=(int*)malloc(sizeof(int)*n);
    time_t start,end;
    double totaltime;
    printf("Enter the number of element:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the %d element:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    start=clock();
    sorted=insertionSort(arr,n);
    end=clock();
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The time taken is %e\n",totaltime);
    printf("The sorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",sorted[i]);
}