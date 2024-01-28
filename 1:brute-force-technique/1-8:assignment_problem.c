#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int* final_result;
int final_cost=INFINITY;

void permutation(int n,int (*arr)[n],int *choice,int r){
    int i,j,k,cost=0;
    if(n==r){
        for(i=0;i<n;i++){
            cost+=arr[i][*(choice+i)];
            printf("%d ",arr[i][*(choice+i)]);
        }
        printf("\n");
        if(final_cost>cost){
            final_cost=cost;
            final_result=(int*)malloc(sizeof(int)*n);
            for(i=0;i<n;i++)
                final_result[i]=choice[i];
        }
        return;
    }
    for(i=0;i<n-r;i++){
        swap(choice+r,choice+i+r);
        permutation(n,arr,choice,r+1);
        swap(choice+r,choice+i+r);
    }
}
int main(){
 
    int njob,npeople,i,j,capacity;
   /* printf("ASSIGNMENT PROBLEM USING BRUTE FORCE TECHNIQUE\n");
    printf("Enter the total number of job: ");
    scanf("%d",&njob);
    printf("Enter the total number of people: ");
    scanf("%d",&npeople);
    int arr[npeople][njob];
    printf("Enter the value: \n");
    for(i=0;i<npeople;i++){
        printf("Enter the cost for %d people:",i+1);
        for(j=0;j<njob;i++){
        scanf("%d",arr[i][j]);
    }
    }
    */
    int n=4;
    int arr[][4]={{9,3,5,2},{1,6,3,1},{1,5,1,2},{2,3,4,5}};
    int *choice=(int*)malloc(sizeof(int)*n);
    double totaltime;
    time_t start,end;
    for(i=0;i<n;i++){
        choice[i]=i;
    }
    start=clock();
    permutation(n,arr,choice,0);
    end=clock();
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    for(i=0;i<n;i++){
        printf("%d\t ",arr[i][*(final_result+i)]);
    }
    printf("\nThe minimal cost is %d\n",final_cost);
    printf("The total time is %e\n",totaltime);
    return 0;
}