#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool cycle(int n, int* arr, int element){
    int i;
    for(i=0;i<n;i++){
        if(element==arr[i])
            return true;
    }
    return false;
}
void prims(int v,int adj[v][v],int mst[v][v],int selected[v]){
    int i,j,a,k=0,l;
    int x,y;
    int starting_point=0;
    selected[k]=starting_point;
    k++;
    int max=0;
    int min;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(adj[i][j]>max)
                max=adj[i][j];
        }
    }
    for(i=0;i<v-1;i++){
        min=max+1;
        for(j=0;j<k;j++){
            for(a=0;a<v;a++){
                if(adj[selected[j]][a]&&(adj[selected[j]][a]<min)&&!cycle(k,selected,a)){
                    min=adj[selected[j]][a];
                    x=selected[j];
                    y=a;
                }
            }
        }
        mst[x][y]=min;
        mst[y][x]=min;
        selected[k++]=y;
    }
}
void main(){
    printf("Enter the vertices: ");
    int v;
    scanf("%d",&v);
    int i,j,k;
    int adj[v][v];
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    int mst[i][j];
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            mst[i][j]=0;
        }
    }
    int selected[v];
    prims(v,adj,mst,selected);
    printf("\nMST is:\n");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            printf("%d ",mst[i][j]);
        }
        printf("\n");
    }
}