#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int opcount;
void swap(int *a ,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void topdown(int * arr, int size){
    int i,j,k;
    for(i=1;i<=size;i++){
        k=i;
        while(1){
            opcount++;
            if(k==1)
                break;
            if(arr[(int)k/2-1]>arr[k-1])
                break;
            swap(arr+(int)k/2-1,arr+k-1);
            k=(int)k/2;
        }
    }
}
int* heapsorting(int *arr, int size){
    topdown(arr,size);
    int i,j,k;
    int *sorted=(int*)malloc(sizeof(int)*size);
    for(i=0;i<size;i++){
        sorted[i]=arr[0];
        arr[0]=arr[size-i-1];
        topdown(arr,size-i-1);
    }
    return sorted;
}

void main(){
    int i,n;
    opcount=0;
    time_t start,end;
    double totaltime;
    printf("Enter number of element: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(sizeof(int)*n);
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    start=clock();
    int *sorted=heapsorting(arr,n);
    end=clock();
    printf("Sorted array: ");
    for(i=n-1;i>=0;i--)
        printf("%d  ",sorted[i]);
    printf("\n");
    printf("opcount: %d\n",opcount);
    printf("Totaltime: %e\n",totaltime);

}