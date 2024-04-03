#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int opcount=0;
void subset_backtracking(int n, int arr[n], int target, int selected[n],int k){
    if(target==0){
        int i;
        for(i=0;i<n;i++){
            if(selected[i])
                printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    if(k==n)
        return;
    opcount++;
    subset_backtracking(n,arr,target,selected,k+1);
    selected[k]=1;
    subset_backtracking(n,arr,target-arr[k],selected,k+1);
    selected[k]=0;
}
void main(){
    int n,d,i,j;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the value of sum: ");
    scanf("%d",&d);
    printf("Enter the element: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int selected[5];
    for(i=0;i<n;i++)
        selected[i]=0;
    opcount=0;
    time_t start,end;
    start=clock();
    subset_backtracking(n,arr,d,selected,0);
    end=clock();
    double totaltime=(end-start)/CLOCKS_PER_SEC;
    printf("\nThe opcount is %d \n",opcount);
    printf("The total time taken is %e\n",totaltime);
}