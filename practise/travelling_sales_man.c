#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int min=INFINITY;
int *choose_path;
int *travel;
void permutation(int n, int arr[n][n],int r){
    int i,j;
    if(r==n-1){
        int cost=0;
        for(i=0;i<n-1;i++){
            cost+=arr[travel[i]][travel[i+1]];
        }
        cost+=arr[travel[n-1]][0];
        printf("%d\n",cost);
        if(min>cost){
            min=cost;
            for(i=0;i<n;i++)
                choose_path[i]=travel[i];
        }
        return;
    }
    for(i=0;i<n-r;i++){
        swap(travel+r,travel+r+i);
        permutation(n,arr,r+1);
        swap(travel+r,travel+r+i);
    }
    return;
}
void main(){
    int n=4;
    int adj[][4]={{0,2,5,7},{2,0,8,3},{5,8,0,1},{7,3,1,0}};
    int i,j;
    travel=(int*)malloc(sizeof(int)*n);
    choose_path=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        travel[i]=i;
    }
    permutation(n,adj,1);
    for(i=0;i<n;i++){
        printf("%d->",choose_path[i]+1);
    }
    printf("\ntotal cost: %d\n",min);
}