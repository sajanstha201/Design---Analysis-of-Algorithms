/*
Mergesort is a perfect example of a successful application of the divide and conquer
technique. It sorts a given array A[0,1,....n-1] by dividing it into two halves 
A[0,1,..n/2-1] and A[n/2,...n-1], sorting each of them recursively, and then merging
then two smaller sorted arrays into a single sorted one.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int opcount=0;
int* mergeSort(int * arr,int size){
    int i,j,k;
    if(size==1)
        return arr;
    int lsize=(int)(size/2);
    int rsize=size-(int)(size/2);
    int *left=(int*)malloc(sizeof(int)*lsize);
    int *right=(int*)malloc(sizeof(int)*rsize);
    for(i=0;i<lsize;i++)
        left[i]=arr[i];
    for(i=0;i<rsize;i++)
        right[i]=arr[i+lsize];
    left=mergeSort(left,lsize);
    right=mergeSort(right,rsize);
    i=0;
    j=0;
    k=0;
    while(1){
        opcount++;
        if(i==lsize){
            while(j!=rsize){
                arr[k]=right[j];
                j++;
                k++;
            }
            break;
        }
        else if(j==rsize){
            while(i!=lsize){
                arr[k]=left[i];
                i++;
                k++;
            }
            break;
        }
        if(left[i]<right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }

        k++;
    }
    return arr;
}
void main(){
    int n,i;
    printf("Total number of element: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("array[%d]: ",i+1);
        scanf("%d",&arr[i]);
    }
    time_t start,end;
    double totaltime;
    start=clock();
    int *sorted=(int*)malloc(sizeof(int)*n);
    end=clock();
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    sorted=mergeSort(arr,n);
    printf("The sorted array is :\n");
    for(i=0;i<n;i++)
        printf("%d\t",sorted[i]);
    printf("\nThe opcount is %d\n",opcount);
    printf("The time of execution is %e\n",totaltime);

}