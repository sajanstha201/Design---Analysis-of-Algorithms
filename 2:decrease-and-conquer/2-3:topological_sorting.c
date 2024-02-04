#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int **adj;
int *visited,*neighbour,*topo_sort;
int k=0,t=0,opcount=0;
int visit[5];
void DFS(int i){
    int j;
    if(visited[i]==0){
        visit[k]=i;
        k++;
        visited[i]+=1;
        for(j=0;j<neighbour[i];j++){
            opcount++;
            DFS(adj[i][j]);
            topo_sort[t]=adj[i][j];
            t++;
        }
    }
    return;
}
void main(){
    int n,i,j,npoint;
    int *row;
    printf("Enter the total number of points:");
    scanf("%d",&n);
    adj=(int**)malloc(sizeof(int));
    neighbour=(int*)malloc(sizeof(int)*n);
    visited=(int*)malloc(sizeof(int)*n);
    topo_sort=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    for(i=0;i<n;i++){
        printf("Total No of Point adjacent to %d: ",i+1);
        scanf("%d",&npoint);
        *(neighbour+i)=npoint;
        printf("Enter the adjacent points: ");
        row=(int*)malloc(sizeof(int)*npoint);
        for(j=0;j<npoint;j++){
            scanf("%d",&row[j]);
            row[j]--;
        }
        adj[i]=row;
    }
    printf("\nsajan shrestha\n\n");
    for(i=0;i<n;i++){
        printf("devraj\n");
        printf("%d\t",neighbour[i]);
    }


    /*
        for(i=0;i<n;i++){
            printf("%d: ",i+1);
        for(j=0;j<neighbour[i];j++){
            printf("%d\t",adj[i][j]+1);
        }
        printf("\n");
    }
    */

    time_t start,end;
    double totaltime;
    start=clock();
    DFS(0);
    end=clock();
    /*
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    for(i=0;i<n;i++){
        printf("->%d",visit[i]+1);
    }
    printf("The is topological sort:\n");
    for(i=0;i<n;i++)
        printf("->%d",topo_sort[i]+1);
    printf("The opcount is %d\n",opcount);
    printf("The total time is %e\n",totaltime);
    */
}
