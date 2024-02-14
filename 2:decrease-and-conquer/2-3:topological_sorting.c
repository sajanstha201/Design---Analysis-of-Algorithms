#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
int **adj;
int *visited,*neighbour,*topo_sort;
int k=0,t=0,opcount=0;
int *visit;
bool cycle=false;
void DFS(int i){
    int j;
        visit[k]=i;
        k++;
        visited[i]+=1;
        for(j=0;j<neighbour[i];j++){
            opcount++;
            if(visited[adj[i][j]]!=0)
                cycle=true;
            else
                DFS(adj[i][j]);
        }
    topo_sort[t]=i;
    t++;
    return;
}
void main(){
    int n,i,j,npoint;
    int *row;
        for(i=0;i<20;i++)
        printf("--");
    printf("TOPOLOGICAL SORTING");
    for(i=0;i<20;i++)
        printf("--");
    printf("\nNote: write the outgoing edge points only\nFor example: 1->2\n");
    printf("Then\nTotal No fo outgoing adjacent point to 1: 1\n");
    printf("Enter the adjacent points:2\n");
    printf("Total No of outgoing adjacent point to 2: 0\n\n");
    for(i=0;i<20;i++)
        printf("--");
    printf("NOW START");
    for(i=0;i<20;i++)
        printf("--");
    printf("\n\nEnter the total number of points:");
    scanf("%d",&n);
    adj=(int**)malloc(sizeof(int*)*n);
    neighbour=(int*)malloc(sizeof(int)*n);
    visited=(int*)malloc(sizeof(int)*n);
    visit=(int*)malloc(sizeof(int)*n);
    topo_sort=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    for(i=0;i<n;i++){
        printf("Total No of outgoing adjacent point to %d: ",i+1);
        scanf("%d",&npoint);
        *(neighbour+i)=npoint;
        if(npoint==0)
            continue;
        printf("Enter the adjacent points: ");
        row=(int*)malloc(sizeof(int)*npoint);
        for(j=0;j<npoint;j++){
            scanf("%d",&row[j]);
            row[j]--;
        }
        adj[i]=row;
    }
        for(i=0;i<n;i++){
            printf("%d: ",i+1);
        for(j=0;j<neighbour[i];j++){
            printf("%d\t",adj[i][j]+1);
        }
        printf("\n");
    }

    time_t start,end;
    double totaltime;
    start=clock();
    DFS(0);
    end=clock();
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nDepth First Search:\n");
    for(i=0;i<n;i++){
        printf("->%d",visit[i]+1);
    }
    if(cycle)
        printf("\nTopological sorting is not possible\n");
    else{
        printf("\nThe is topological sort:\n");
        for(i=n-1;i>=0;i--)
            printf("->%d",topo_sort[i]+1);
    }
    printf("\nThe opcount is %d\n",opcount);
    printf("The total time is %e\n",totaltime);
}
