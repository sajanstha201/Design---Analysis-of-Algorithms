#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
    int n,i,j,k;
    int opcount=0;
    printf("Enter the number of element:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the element: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    time_t start,end;
    start=clock();
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                opcount++;
                k=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=k;
            }
        }
    }
    end=clock();
    double totaltime=(end-start)/CLOCKS_PER_SEC;
    printf("Sorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nOpcount: %d",opcount);
    printf("\nTime taken: %e",totaltime);

}