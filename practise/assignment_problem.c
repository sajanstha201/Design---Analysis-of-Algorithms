#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int *job;
int mincost=INFINITY;
int *choice;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void permutation(int n,int adj[n][n],int r){
    int cost,i,j;
    if(r==n-1){
        cost=0;
        for(i=0;i<n;i++){
            cost+=adj[i][choice[i]];
        }
        if(mincost>cost){
            mincost=cost;
            for(i=0;i<n;i++)
                job[i]=choice[i];
        }
        return;
    }
    for(i=0;i<n-r;i++){
        swap(choice+r,choice+r+i);
        permutation(n,adj,r+1);
        swap(choice+r,choice+r+i);
    }
    return;
}
void main(){
    int n=3,i,j;
    int adj[][3]={{9,2,7},{6,4,3},{5,8,1}};
    choice=(int*)malloc(sizeof(int)*n);
    job=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        choice[i]=i;
    }
    permutation(n,adj,0);
    for(i=0;i<n;i++){
        printf("%d  ",job[i]+1);
    }
    printf("\nMIN COST %d\n",mincost);
}