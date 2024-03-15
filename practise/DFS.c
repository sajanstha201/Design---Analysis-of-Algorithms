#include<stdio.h>
#include<stdlib.h>
int stack[100];
int top=-1;
int *visited;
int *neighbour;
void push(int x){
    stack[++top]=x;
}
int pop(){
    return stack[top--];
}
void DFS(int i,int **adj){
    int k,x=i;
    push(i);
    visited[i]=1;
    while(1){
        x=pop();
        printf("%d \t",x);
        for(k=0;k<neighbour[adj[x][k]];k++){
            if(visited[adj[x][k]]==0){
                visited[adj[x][k]]=1;
                push(adj[x][k]);
            }
                
        }
        if(top==-1)
            return;
    }
}
void recursive_DFS(int i,int **adj){
    if(visited[i])
        return;
    visited[i]=1;
    printf("%d ",i);
    int k;
    for(k=0;k<neighbour[i];k++){
        recursive_DFS(adj[i][k],adj);
    }
}
void main(){
    int n=4;
    
    int **adj=(int**)malloc(sizeof(int*)*n);
    neighbour=(int*)malloc(sizeof(int)*n);
    visited=(int*)malloc(sizeof(int)*n);

    neighbour[0]=2;
    adj[0]=(int*)malloc(sizeof(int)*2);
    adj[0][0]=2;
    adj[0][1]=3;

    neighbour[1]=1;
    adj[1]=(int*)malloc(sizeof(int)*1);
    adj[1][0]=3;

    neighbour[2]=2;
    adj[2]=(int*)malloc(sizeof(int)*2);
    adj[2][0]=0;
    adj[2][1]=3;

    neighbour[3]=3;
    adj[3]=(int*)malloc(sizeof(int)*2);
    adj[3][0]=1;
    adj[3][1]=2;
    adj[3][2]=0;
    int i;
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    recursive_DFS(0,adj);

}