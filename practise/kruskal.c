#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool dfs(int point,int v,int adj[v][v],int visited[v],int parent){
    int i;
    visited[point]=1;
    for(i=0;i<v;i++){
        if(adj[point][i]){
            if(visited[i]){
                if(parent==i){
                    return false;
                }
                continue;
            }
            if(dfs(i,v,adj,visited,point))
                return true;

        }
    }
    return false;
}
bool cycle(int v,int adj[v][v],int added_vertices){
    int i;
    int visited[v];
    for(i=0;i<v;i++){
            visited[i]=0;
        }
    dfs(added_vertices,v,adj,visited,i);
}
void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
void sort(int e,int arr[e][3]){
    int i,j,k;
    for(i=0;i<e;i++){
        for(j=0;j<e-1;j++){
            if(arr[j][2]>arr[j+1][2]){
                for(k=0;k<3;k++) 
                    swap(*(arr+j)+k,*(arr+j+1)+k);
            }
        }
    }
}
void kruskal(int v,int adj[v][v],int mst[v][v]){
    int i,j,k=0;
    int edges=0;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(i<j){
                if(adj[i][j]!=0)
                    edges++;
            }
        }
    }
    int arr[edges][3];
    k=0;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(i<j&&adj[i][j]!=0){
                arr[k][0]=i;
                arr[k][1]=j;
                arr[k][2]=adj[i][j];
                k++;
            }
        }
    }
    sort(edges,arr);
    for(i=0;i<edges;i++){
        for(k=0;k<3;k++){
            printf("%d ",arr[i][k]);
        }
        printf("\n");
    }
    k=0;
    i=0;
    while(1){
        mst[arr[k][0]][arr[k][1]]=arr[i][2];
        mst[arr[k][1]][arr[k][0]]=arr[i][2];
        i++;
        if(!cycle(v,mst,arr[k][0])){
            k++;
        }
        if(k==v)
            break;
    }
}
void main(){
    printf("Enter the vertices: ");
    int i,j,k,v;
    scanf("%d",&v);
    int adj[v][v];
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            scanf("%d",&adj[i][j]);
    int edges=0;
    int mst[v][v];
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(!adj[i][j])
                adj[i][j]=0;
            mst[i][j]=0;
        }
    }
    kruskal(v,adj,mst);
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            printf("%d ",mst[i][j]);
        }
        printf("\n");
    }
}