/*
There are 'n' peopele who need to be assigned to execute 'n' jobs, one person per job.
(That is, each persion is assigned to exactly one job and each job is assigned to 
exactly one person).

The cost that would resutl if the ith person is assigned to the jth job is a known 
wuantity C[i,j] for each pair i,j =1,2,...,n.

The problem is to find an assignment with the minimum total cost.

We can describe feasible solutions to the assignment problem as n-tuples j1,j2,...,jn
in which the ith components, i=1,2,3...,n indicats the columh of the element selected 
in the ith row(i.e, the job number assigned to the ith person).
*/

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
int opcount=0;
void permutation(int n,int (*arr)[n],int *choice,int r){
    int i,j,k,cost=0;
    if(n==r){
        for(i=0;i<n;i++){
            cost+=arr[i][*(choice+i)];
        }
        if(final_cost>cost){
            final_cost=cost;
            final_result=(int*)malloc(sizeof(int)*n);
            for(i=0;i<n;i++)
                final_result[i]=choice[i];
        }
        return;
    }
    for(i=0;i<n-r;i++){
            opcount++;
        swap(choice+r,choice+i+r);
        permutation(n,arr,choice,r+1);
        swap(choice+r,choice+i+r);
    }
}
int main(){
    int n,i,j;
   printf("ASSIGNMENT PROBLEM USING BRUTE FORCE TECHNIQUE\n");
    printf("Enter the total number of people: ");
    scanf("%d",&n);
    int arr[n][n];
    for(i=0;i<n;i++){
        printf("Enter %d cost for %d people:",n,i+1);
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    //int n=4;
    //int arr[][4]={{9,3,5,2},{1,6,3,1},{1,5,1,2},{2,3,4,5}};
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
    printf("\nThe opcount is %d\n",opcount);
    return 0;
}