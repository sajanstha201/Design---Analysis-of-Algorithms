#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int opcount;
int binarySearch(int * arr,int a,int b,int num){
    opcount++;
    if(a>b){
        return -1;
    }
    int mid=(a+b)/2;
    if(num==arr[mid])
        return mid;
    else if(num<arr[mid])
        return binarySearch(arr,a,mid-1,num);
    else
       return binarySearch(arr,mid+1,b,num); 
}
void main(){
    time_t start,end;
    printf("Enter number of element:");
    int n;
    scanf("%d",&n);
    printf("Enter the element:");
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to find: ");
    int number;
    scanf("%d",&number);
    opcount=0;
    start=clock();
    int z=binarySearch(arr,0,n-1,number);
    end=clock();
    double totaltime=(end-start)/CLOCKS_PER_SEC;
    if(z==-1)
        printf("Element not found\n");
    else
        printf("Element position: %d\n",z+1);
}