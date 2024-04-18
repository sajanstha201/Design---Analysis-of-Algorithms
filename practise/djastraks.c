#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void djs(int v,int adj[v][v],int starting_point, int path[v],int vertices[v]){
    int *fixed=(int*)malloc(sizeof(int)*v);
    int i,j,k,l;
    int previous=starting_point;
    int min;
    int max=-1;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(max<adj[i][j])
                max=adj[i][j];
        }
    }
    for(i=0;i<v;i++){
        vertices[i]=starting_point;
        path[i]=adj[starting_point][i];
        fixed[i]=0;
        if(i==starting_point)
            fixed[i]=1;
    }
    for(i=0;i<v-1;i++){
        min=max+2;
        for(j=0;j<v;j++){
            if(fixed[j]||path[j]==-1)
                continue;
            if(path[j]<min){
                min=path[j];
                printf("%d \n",min);
                k=j;
            }
        }
        fixed[k]=1;
        for(j=0;j<v;j++){
            if(fixed[j])
                continue;
            if(((path[k]+adj[k][j]<path[j])&&(adj[k][j]!=-1))||((path[j]==-1))&&(adj[k][j]!=-1)){
                path[j]=path[k]+adj[k][j];
                vertices[j]=k;
            }
        }

    }
}
void main(){
    int i,j,v;
    printf("Enter the vertices: ");
    scanf("%d",&v);
    int adj[v][v];
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(adj[i][j]==0&&i!=j)
                adj[i][j]=-1;
        }
    }
    int *path=(int*)malloc(sizeof(int)*v);
    int *vertices=(int*)malloc(sizeof(int)*v);
    int starting_point=0;
    djs(v,adj,starting_point,path,vertices);
    printf("The result is :\n");
    for(i=0;i<v;i++)
        printf("%d ",i+1);
    printf("\n");
    for(i=0;i<v;i++)
        printf("%d ",path[i]);
    printf("\n");
    for(i=0;i<v;i++)
        printf("%d ",vertices[i]+1);
        
}