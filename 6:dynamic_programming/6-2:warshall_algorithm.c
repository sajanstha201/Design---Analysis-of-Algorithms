#include<stdio.h>
#include<stdlib.h>
void warshall(int size, int R[size][size]){
    int i,j,k;
    int Rx[size][size];
    for(k=0;k<size;k++){
        for(i=0;i<size;i++)
            for(j=0;j<size;j++)
                Rx[i][j]=R[i][j]+R[i][k]*R[k][j];
        for(i=0;i<size;i++)
            for(j=0;j<size;j++)
                if(Rx[i][j]!=0)
                    R[i][j]=1;
    }

    printf("\nFinal transitive closure adjacent matrix:\n");
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("%d\t",R[i][j]);
        }
        printf("\n");
       }
}
void main(){
    int size;
    printf("Enter total number of vertices:");
    scanf("%d",&size);
    int adj[size][size];
    int i,j;
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            scanf("%d",&adj[i][j]);
    warshall(size,adj);
}