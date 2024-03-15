#include<stdio.h>
#include<stdlib.h>
int *sorted;
int *neg;
int *visited;
int x=0;
void  DFS(int i,int **adj){
    if(visited[i]!=0)
        return ;
    int k;
    visited[i]=1;
    for(k=0;k<neg[i];k++){
        if(visited[adj[i][k]]==0)
            DFS(adj[i][k],adj);
    }
    printf("%d\n",i);
    sorted[x++]=i;
    return;
}
void main(){
    int n=4;
    int **adj=(int**)malloc(sizeof(int*)*n);
    neg=(int*)malloc(sizeof(int)*n);
    visited=(int*)malloc(sizeof(int)*n);
    sorted=(int*)malloc(sizeof(int)*n);
    int i,j,k;
    for(i=0;i<n;i++)
        visited[i]=0;
    neg[0]=2;
    adj[0]=(int*)malloc(sizeof(int)*2);
    adj[0][0]=3;
    adj[0][1]=2;
    neg[1]=0;
    neg[2]=0;
    neg[3]=2;
    adj[3]=(int*)malloc(sizeof(int)*2);
    adj[3][0]=1;
    adj[3][1]=2;
    DFS(0,adj);
    for(i=n-1;i>=0;i--){
        printf("%d->",sorted[i]);
    }

}