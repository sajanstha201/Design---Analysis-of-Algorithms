#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int opcount;
void  add(int n,int a[n][n], int b[n][n],int c[n][n]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            c[i][j]=a[i][j]+b[i][j];
        }            
    }
    return;
}
void  sub(int n,int a[n][n], int b[n][n],int c[n][n]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            c[i][j]=a[i][j]-b[i][j];
    }
    return;
}
int** strassen(int n,int a[n][n],int b[n][n],int c[n][n]){
    opcount++;
    int mid=n/2;
        int i,j;
    if(n==1){
        c[0][0]=a[0][0]*b[0][0];
        return c;
    }
    int a00[mid][mid],a01[mid][mid],a10[mid][mid],a11[mid][mid];
    int b00[mid][mid],b01[mid][mid],b10[mid][mid],b11[mid][mid];
    int m1[mid][mid],m2[mid][mid],m3[mid][mid],m4[mid][mid],m5[mid][mid],m6[mid][mid],m7[mid][mid];
    for(i=0;i<mid;i++){
        for(j=0;j<mid;j++){
            a00[i][j]=a[i][j];
            b00[i][j]=b[i][j];
            a01[i][j]=a[i][j+mid];
            b01[i][j]=b[i][j+mid];
            a10[i][j]=a[i+mid][j];
            b10[i][j]=b[i+mid][j];
            a11[i][j]=a[i+mid][j+mid];
            b11[i][j]=b[i+mid][j+mid];
         //   printf("%d %d %d %d %d %d %d %d\n",a00[i][j],b00[i][j],a01[i][j],b01[i][j],a10[i][j],b10[i][j],a11[i][j],b11[i][j]);
        }
        printf("\n");
    }
    int add1[mid][mid],add2[mid][mid],add3[mid][mid],add4[mid][mid],add5[mid][mid],add6[mid][mid],add7[mid][mid],add8[mid][mid],add9[mid][mid],add10[mid][mid];
    add(mid,a00,a11,add1);
    add(mid,b00,b11,add2);
    add(mid,a10,a11,add3);
    sub(mid,b01,b11,add4);
    sub(mid,b10,b00,add5);
    add(mid,a00,a01,add6);

    sub(mid,a10,a00,add7);
    add(mid,b01,b00,add8);
    sub(mid,a01,a11,add9);
    add(mid,b10,b11,add10);
    
    strassen(mid,add1,add2,m1);
    strassen(mid,add3,b00,m2);
    strassen(mid,a00,add4,m3);
    strassen(mid,a11,add5,m4);
    strassen(mid,add6,b11,m5);
    strassen(mid,add7,add8,m6);
    strassen(mid,add9,add10,m7);
   // printf("%d %d\n",add9[0][0],add10[0][0]);
    //printf("m1 %d\n m2 %d\n m3 %d\n m4 %d\n m5 %d\nm6 %d\n m7 %d\n",m1[0][0],m2[0][0],m3[0][0],m4[0][0],m5[0][0],m6[0][0],m7[0][0]);
    /*
       int **c00=(int**)malloc(sizeof(int*)*mid);
    int **c01=(int**)malloc(sizeof(int*)*mid);
    int **c10=(int**)malloc(sizeof(int*)*mid);
    int **c11=(int**)malloc(sizeof(int*)*mid);
    */
    int c00[mid][mid],c01[mid][mid],c10[mid][mid],c11[mid][mid];
    add(mid,m3,m5,c01);
    add(mid,m2,m4,c10);
    int x1[mid][mid],x2[mid][mid],x3[mid][mid],x4[mid][mid];

    add(mid,m1,m3,x1);
    sub(mid,x1,m2,x2);
    add(mid,x2,m6,c11);

    add(mid,m1,m4,x3);
    sub(mid,x3,m5,x4);
    add(mid,x4,m7,c00);
    for(i=0;i<mid;i++){
        printf("sajan shrestha\n");
        for(j=0;j<mid;j++){
            c[i][j]=c00[i][j];
            c[i][j+mid]=c01[i][j];
            c[i+mid][j]=c10[i][j];
            c[i+mid][j+mid]=c11[i][j];
        }
    }
    return c;     
}

void main(){
    int n;
    printf("Enter the order of matrix: ");
    scanf("%d",&n);
    printf("\nEnter for 1st array:\n");
    int i,j;
    int a[n][n],b[n][n];
    for(i=0;i<n;i++){
        printf("%d row: ",i+1);
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nEnter for 2nd array:\n");
    for(i=0;i<n;i++){
        printf("%d row: ",i+1);
        for(j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    int c[n][n];
    opcount=0;
    time_t start,end;
    start=clock();
    strassen(n,a,b,c);
    end=clock();
    double totaltime=(end-start)/CLOCKS_PER_SEC;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    printf("\n Total time: %e\n",totaltime);
    printf("\nOpcount: %d\n",opcount);

}