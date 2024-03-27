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
    topdown(arr,n);
    end=clock();
    totaltime=(end-start)/CLOCKS_PER_SEC;
    printf("heaped array: ");
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
    printf("opcount: %d\n",opcount);
    printf("Totaltime: %e\n",totaltime);

}