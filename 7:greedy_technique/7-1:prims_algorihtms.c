#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
bool cycle(int v,int *mst, int selected){
    int i;
    for(i=0;i<v;i++)
        if(selected==mst[i])
            return true;
    return false;
}
void prims(int v,int adj[v][v],int selected,int *s_arr,int mst[v][v]){
    int i=0,j,k,l,next_vertice;
    int smallest_path,selected_vertices;
    s_arr[i]=selected;
    int max=-INFINITY;
    int row,column;
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            if(max<adj[i][j])
                max=adj[i][j];
    for(i=1;i<v;i++){
        smallest_path=max;
        selected_vertices=selected;
        for(j=0;j<i;j++){
            for(k=0;k<v;k++){
                if((adj[s_arr[j]][k]<smallest_path)&&(adj[s_arr[j]][k]!=0)&&(!cycle(i,s_arr,k))){
                    smallest_path=adj[s_arr[j]][k];
                    selected=k;
                    row=s_arr[j];
                    column=k;
                }
            }
        }   
        mst[row][column]=smallest_path; 
        s_arr[i]=selected;
    }
}
void main(){
    int i,j,k,v;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    int adj[v][v];
    int *s_arr=(int*)malloc(sizeof(int)*v);
    int mst[v][v];
    printf("Enter the adj matrix: \n");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            scanf("%d",&adj[i][j]);
            mst[i][j]=0;
        }
    }
    int selected=0;
    prims(v,adj,selected,s_arr,mst);
    printf("The MST is: \n");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            printf("%d ",mst[i][j]);
        }
        printf("\n");
    }
}