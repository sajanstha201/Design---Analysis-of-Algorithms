#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
void dijkstras(int v,int adj[v][v],int starting_point,int min_path[v],int vertices[v]){
    int i,j,k,l;
    int d;
    k=0;
    int fixed[v];
    for(i=0;i<v;i++){
        fixed[i]=0;
        vertices[i]=starting_point;
        min_path[i]=adj[starting_point][i];
        if(i==starting_point){
            fixed[i]=1;
        }
    }
    int max=1000000;
    l=starting_point;
    for(i=0;i<v-1;i++){
        for(j=0;j<v;j++){
            if(fixed[j]||adj[l][j]==-1)
                continue;
            d=min_path[l]+adj[l][j];
            if(d<min_path[j]||min_path[j]==-1){
                min_path[j]=d;
                vertices[j]=l;
            }
        }
        k=max;
        for(j=0;j<v;j++){
            if(fixed[j]||min_path[j]==-1)
                continue;
            if(min_path[j]<k){
                k=min_path[j];
                l=j;
            }  
        }
        min_path[l]=k;
        fixed[l]=1;
    }
    printf("\nThe result is \n");
    for(i=0;i<v;i++)
        printf("%d ",i+1);
    printf("\n");
    for(i=0;i<v;i++)
        printf("%d ",min_path[i]);
    printf("\n");
    for(i=0;i<v;i++)
        printf("%d ",vertices[i]+1);
}
void main(){
    int i,j,v;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    int adj[v][v];
    printf("Enter the adj matrix: \n");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(i=0;i<v;i++)
        for(j=0;j<v;j++){
            if(adj[i][j]==0&&i!=j)
                adj[i][j]=-1;
        }
    int starting_point=0;
    int min_path[v];
    int vertices[v];
    dijkstras(v,adj,starting_point,min_path,vertices);
}