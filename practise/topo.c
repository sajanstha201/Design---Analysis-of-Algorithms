#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *sorted;
int *degree;
int k=0;
void finddegree(int n,int adj[n][n]){
    int i,j;
    for(i=0;i<n;i++){
        int d=0;
        for(j=0;j<n;j++){
            if(adj[j][i]==1)
                d++;
        }
        degree[i]=d;
    }
    for(i=0;i<k;i++){
        degree[sorted[i]]=-1;
    }
 
}
int findsmallestdegree(int n){
    int i;
    int min=0;
    for(i=1;i<n;i++){
        if(degree[i]!=-1)
            if(min>degree[i])
                min=degree[i];
    }  
    return min;
}
void topo(int n,int adj[n][n]){

    int i,j;
    int a,b;
    int s,x;
    for(i=0;i<n;i++){
        finddegree(n,adj);
        s=findsmallestdegree(n);
        if(degree[i]==s){
            sorted[k]=i;
            k++;
            for(j=0;j<n;j++){
                adj[i][j]=0;
                adj[j][i]=0;
            }
        }
    }

}
void main(){
    int n=4;
    //int *adj=(int)malloc(sizeof(int)*n);
    sorted=(int*)malloc(sizeof(int)*n);
    degree=(int*)malloc(sizeof(int)*n);
    int i;
    /*for(i=0;i<n;i++){
        adj[i]=(int*)malloc(sizeof(int)*n);
    }*/
    int adj[4][4]={{0,1,0,1},{0,0,1,1},{0,0,0,0},{0,0,0,0}};
    topo(n,adj);
    for(i=0;i<n;i++){
        printf("%d->",sorted[i]);
    }
 
}