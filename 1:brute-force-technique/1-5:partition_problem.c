/*
Partition Problem using brute-force technique
->The partition problem is to determine whether a given set can be partiioned into two
subsets such that sum of elements in both subsets is the same.
Examples:
1.
Input:arr[]={1,5,11,5}
Output:True
The array can be partitoned as {1,5,5} and {11}

2.
Input: arr[]={1,5,3}
Output:False
The array cannot be partitioned into equal sum
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int partition_one_method(int l,int * arr,int sum){
    int i;
    int total=0;
    for(i=0;i<l;i++)
        total+=arr[i];
    if(sum==0||total==sum)
        return 1;
    if(l==0)
        return 0;
    return partition_one_method(l-1,arr+1,sum-*arr)+partition_one_method(l-1,arr+1,sum);
}

int partition_second_method(int *arr,int l){
    int subset=pow(2,l);
    int i,binary,k,total=0,sum;
    for(i=0;i<l;i++)
        total+=arr[i];
    for(i=0;i<subset;i++){
        binary=i;
        k=0;
        sum=0;
        while(binary){
            if(binary&0x1){
                sum+=arr[k];
            }
            k++;
            binary=binary>>1;
        }
        if(sum==total/2){
            return i;
        }
    }
}

int main(){
    int l=6;
    int arr[]={1,2,3,4,5,3};
    int i,sum=0;
    for(i=0;i<l;i++)
        sum+=arr[i];
    if(sum%2==0){
        sum=sum/2;
        if(partition_one_method(l,arr,sum))
            printf("Partition is possible\n");
    }
    else{
        printf("Partition is not possible\n");

    }


    int binary=partition_second_method(arr,l);
    int *a=(int*)malloc(sizeof(int));
    int *b=(int*)malloc(sizeof(int));
    int alen=0,blen=0,k=0;
    for(i=0;i<l;i++){
        if(binary&0x1){
            a=realloc(a,sizeof(int)*(alen+1));
            a[alen]=arr[k];
            alen++;
        }
        else{
            b=realloc(b,sizeof(int)*(blen+1));
            b[blen]=arr[k];
            blen++;
        }
        k++;
        binary=binary>>1;
    }
    for(i=0;i<alen;i++)
        printf("%d ",a[i]);
    printf("\n");
    for(i=0;i<blen;i++)
        printf("%d ",b[i]);
}