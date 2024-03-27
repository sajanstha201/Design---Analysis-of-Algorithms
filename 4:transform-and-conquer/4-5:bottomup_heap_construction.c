#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
int opcount;
int* buttomup(int *arr,int n){
    int i,j,k,temp,x;
    for(i=(int)(n/2);i>=1;i--){
        k=i;
        j=2*k;
        bool heap=false;
        while(!heap&&j<=n){
                opcount++;
            temp=j;
            if(j+1<=n)
                if(arr[j+1]>arr[j])
                    temp=j+1;
            if(arr[temp]>arr[k]){
                x=arr[temp];
                arr[temp]=arr[k];
                arr[k]=x;
                k=temp;
                j=2*k;
            }
            else
                heap=true;
        }
    }
    return arr;
}
void main(){
    int i;
    time_t start,end;
    double totaltime;
    while(1){
            printf("Enter the total number of element: ");
            int n;
            scanf("%d",&n);
            int *arr=(int*)malloc(sizeof(n));
            printf("Enter element: ");
            for(i=1;i<=n;i++)
                scanf("%d",&arr[i]);
            opcount=0;
            start=clock();
            int *heaped=buttomup(arr,n);
            end=clock();
            totaltime=(end-start)/CLOCKS_PER_SEC;
            printf("opcount %d\n",opcount);
            printf("total time %e\n",totaltime);
            printf("heaped data:  ");
            for(i=1;i<=n;i++){
                printf("%d  ",heaped[i]);
            }
            printf("\n");
    }


}