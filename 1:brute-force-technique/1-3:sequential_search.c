#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int opcount;
int sequentialSort(int *arr,int size,int num){
    int i;
    for(i=0;i<size;i++){
        opcount++;
        if(arr[i]==num)
            return i;
    }
    return 0;
}
void main(){
    printf("Enter the number of element: ");
    int n;
    scanf("%d",&n);
    printf("Enter the element; ");
    int i,arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the number of find: ");
    int num;
    scanf("%d",&num);
    time_t start,end;
    opcount=0;
    start=clock();
    int z=sequentialSort(arr,n,num);
    end=clock();
    double totaltime=(end-start)/CLOCKS_PER_SEC;
    if(z)
        printf("position of %d is %d\n",num,z+1);
    else
        printf("Element not available\n");
    printf("\nTotal time: %e\n",totaltime);
    printf("Opcoutn : %d\n",opcount);

}