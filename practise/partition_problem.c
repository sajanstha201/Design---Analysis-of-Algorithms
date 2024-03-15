#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>
int partition(int n,int *arr){
    int i,j,k,b;
    int sum=0,sum2;
    for(i=0;i<n;i++)
        sum+=arr[i];
    if(sum%2!=0)
        return 0;

    for(i=1;i<pow(2,n);i++){
        b=i;
        k=0;
        sum2=0;
        while(b){
            if(b%2!=0)
                sum2+=arr[k];
            k++;
            b=b>>1;
        }
        if(sum/2==sum2)
            return i;
    }
    return 0;
}
void main(){
    int n=4,k=0;
    int arr[]={1,2,3,4};
    int s=partition(n,arr);
    if(s){
        printf("possible\n");
        while(s){
            if(s%2!=0)
                printf("%d ",arr[k]);
            s=s>>1;
            k++;
        }
    }
    else
        printf("not possible");
}