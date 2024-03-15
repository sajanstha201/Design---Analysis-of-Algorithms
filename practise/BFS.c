#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int *visited,*neighbour;
int *queue;
int rear=-1,front=0;
void enqueue(int x){
    queue[++rear]=x;
}
int dequeue(){
    return queue[front++];
}
void BFS(int i,int n,int **adj){
    int k;
    enqueue(i);
    printf("%d ",i);
    visited[i]=1;
    while(1){
        int x=dequeue();
       // printf("%d \t",x);
        for(k=0;k<neighbour[x];k++){
            if(visited[adj[x][k]]!=0)
                continue;
            printf("%d  ",adj[x][k]);
            enqueue(adj[x][k]);
            visited[adj[x][k]]=1;
        }
        if(front>rear)
            return;
    }
}
void main(){
    int n=4;
    
    int **adj=(int**)malloc(sizeof(int*)*n);
    queue=(int*)malloc(sizeof(int)*n);
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
    BFS(0,n,adj);

}