#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void warshall_flody(int v,int adj[v][v]){
    int i,j,k;
    for(k=0;k<v;k++){
        for(i=0;i<v;i++){
            for(j=0;j<v;j++){
                if(adj[i][k]==-1||adj[k][j]==-1)
                    continue;
                if(adj[i][j]==-1){
                    adj[i][j]=adj[i][k]+adj[k][j];
                    continue;
                }
                if(adj[i][j]>(adj[i][k]+adj[k][j]))
                    adj[i][j]=adj[i][k]+adj[k][j];
            }
        }
    }
}
void main(){
    int v;
    printf("Enter the vertices: ");
    scanf("%d",&v);
    int adj[v][v];
    int i,j;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(adj[i][j]==0&&i!=j){
                adj[i][j]=-1;
            }
        }
    }
    warshall_flody(v,adj);
    printf("\nResult: \n");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(adj[i][j]==-1){
                printf("0 ");
                continue;
            }
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}