#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int opcount;
bool DFS(int *visited, int v, int adj[v][v],int n,int parent ){
    opcount++;
    int i;
    for(i=0;i<v;i++){
        if(adj[n][i]&&i!=parent){
            if(visited[i]==1){
                return true;
            }
            else{
                visited[i]=1;
                bool cycle=DFS(visited,v,adj,i,n);
                if(cycle)
                    return true;
            }
        }
    }
    return false;
}
bool checkcycle(int vertices,int edges, int min[edges][3]){
    int adj[vertices][vertices];
    int i,j,k;
    int visited[vertices];
    for(i=0;i<vertices;i++)
        for(j=0;j<vertices;j++)
            adj[i][j]=0;
    for(i=0;i<edges;i++){
        adj[min[i][1]][min[i][2]]=1;
        adj[min[i][2]][min[i][1]]=1;
    }
    adj[vertices-1][vertices-1]=0;
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            visited[j]=0;
        }
        visited[i]=1;
        if(DFS(visited,vertices,adj,i,i))
            return true;
    }
    return false;
}
void krushkal(int edge,int vertices, int min[edge][3]){
    int k=0,i,j;
    int minspan[vertices-1][3];
   for(i=0;i<edge;i++){
        opcount++;
        minspan[k][0]=min[i][0];
        minspan[k][1]=min[i][1];
        minspan[k][2]=min[i][2];
        if(!checkcycle(vertices,k+1,minspan)){
            k++;
        }
        if(k==vertices-1)
            break;
    }
    printf("\nThe MST information are: \n");
    for(i=0;i<vertices-1;i++){
        printf("%d %d %d\n",minspan[i][0],minspan[i][1],minspan[i][2]);
    }
}
void main(){
    int edge=14;
    int vertices=9;
    int i,j,k;
    time_t start,end;
    printf("Enter the total number of vertices: ");
    scanf("%d",&vertices);
    printf("Enter the total number of edges: ");
    scanf("%d",&edge);
    int adj[edge][3];
     int w,v1,v2;
    for(i=0;i<edge;i++){
        for(j=0;j<3;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(i=0;i<edge;i++){
        k=i;
        for(j=0;j<edge;j++){
            if(adj[k][0]<adj[j][0])
                k=i;
        }
        w=adj[i][0];
        v1=adj[i][1];
        v2=adj[i][2];
        adj[i][0]=adj[k][0];
        adj[i][1]=adj[k][1];
        adj[i][2]=adj[k][2];
        adj[k][0]=w;
        adj[k][1]=v1;
        adj[k][2]=v2;
    }
    opcount=0;
    start=clock();
    krushkal(edge,vertices,adj);
    end=clock();
    double totaltime=(end-start)/CLOCKS_PER_SEC;
    printf("\nThe opcount is %d\n",opcount);
    printf("The total time taken is %e\n",totaltime);
}