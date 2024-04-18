#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void swap(int *a, int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
void top_down(int v,int arr[v+1]){
    int i,j,k;
    for(i=1;i<=v;i++){
        k=i;
        while(1){
            if(k==1)
                break;
            if(arr[k]>arr[(int)(k/2)]){
                swap(arr+k,arr+(int)(k/2));
            }
            k=(int)(k/2);
        }
        for(j=0;j<i;j++){
            printf("%d ",arr[j]);
        }
        printf("\n");
    }
}
void bottom_up(int v,int arr[v+1]){
    int i,j,k;
    int temp;
    for(i=(int)(v/2);i>=1;i--){
        k=i;
        while(1){
            if(2*k+1>v)
                break;
            temp=2*k;
            if(2*k+1<=v){
                if(arr[2*k]<arr[2*k+1])
                    temp=2*k+1;
            }
            if(arr[k]<arr[temp]){
                swap(arr+k,arr+temp);
                k=temp;
                continue;
            }
            break;
        }
        for(j=1;j<=v;j++)
            printf("%d ",arr[j]);
        printf("\n");
    }
}
void heapsort_(int v,int arr[v+1],int *sorted){
    int i,j,k,temp;
    for(i=1;i<=v;i++){
        sorted[i]=arr[1];
        arr[1]=arr[v-i+1];
        k=1;
        while(1){
            if(2*k>v-i+1)
                break;
            temp=2*k;
            if(2*k+1<v-i+1){
                if(arr[2*k]<arr[2*k+1])
                    temp=2*k+1;
            }
            if(arr[k]<arr[temp]){
                swap(arr+k,arr+temp);
                k=temp;
                continue;
            }
            break;
        }
    }
}
void main(){
    int v=5;
    int arr[6]={0,10,20,6,4,50};
    int i,j,k;
    bottom_up(v,arr);
    int *sorted=(int*)malloc(sizeof(int)*(v+1));
    heapsort_(v,arr,sorted);
    printf("The sorted array is :\n");
    for(i=1;i<=v;i++)
        printf("%d ",sorted[i]);

}