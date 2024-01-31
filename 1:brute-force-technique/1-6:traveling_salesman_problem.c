/*
A traveler needs to visit all the cities from a list, where distance between all the 
cities are known and each city should be visited just once. What is the shoretest
possible route that he visits each city exactly once and returns to the origin city?
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int *final_way;
int final_value=INFINITY;
void possibleWay(int n,int (*adj)[n+1],int *choice,int r){
    int i;
    if(r==n){
        int path=0;
        path=adj[0][choice[0]];
        for(i=0;i<n-1;++i){
            path+=adj[choice[i]][choice[i+1]];
        }
        path+=adj[choice[i]][0];
        if(final_value>path){
            final_value=path;
            for(i=0;i<n;i++)
                *(final_way+i)=*(choice+i);
        }
        return;
    }

    for(i=0;i<n-r;i++){
        swap(choice+r,choice+r+i);
        possibleWay(n,adj,choice,r+1);
        swap(choice+r,choice+r+i);
    }
}
void main(){
    int n,i,j,k;
    printf("Enter the total number of city: ");
    scanf("%d",&n);
    int adj[n][n];
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            printf("Distance between %d and %d city: ",i+1,j+1);
            scanf("%d",&adj[i][j]);
            adj[j][i]=adj[i][j];
        }
    }

    final_way=(int*)malloc(sizeof(int)*(n-1));
    int *choice=(int*)malloc(sizeof(int)*(n-1));
    for(i=0;i<n-1;i++)
        *(choice+i)=i+1;
    possibleWay(n-1,adj,choice,0);
    printf("0 -> ");
    for(i=0;i<n-1;i++){
        printf("%d -> ",final_way[i]);
    }
    printf("0\n");
    printf("Cost is %d\n",final_value);
}