#include<stdio.h>
#include<time.h>
int opcount;
unsigned int  len(unsigned int  n){
    unsigned int  i=0;
    if(n==0)
        return 1;
    while(n){
        i++;
        n=n/10;
    }
    return i;
}
unsigned int  max(unsigned int  a,unsigned int  b){
    if(a>b)
        return a;
    else
        return b;
}
unsigned int pow(unsigned int  base,unsigned int  power){
    unsigned int  i,num=1;
    for(i=0;i<power;i++)
        num=num*base;
    return num;
}
unsigned int  mul(unsigned int  a,unsigned int  b){
    opcount++;
    if(len(a)==1||len(b)==1){
        return a*b;
    }
    unsigned int n=max(len(a),len(b));
    unsigned int a1=a/pow(10,n/2),a0=a%pow(10,n/2),b1=b/pow(10,n/2),b0=b%pow(10,n/2);
    unsigned int  x=mul(a1,b1);
    unsigned int  y=mul(a0,b0);
    unsigned int  z=mul(a0+a1,b0+b1);
    return x*pow(10,(n/2+n/2))+(z-x-y)*pow(10,n/2)+y;
}
void main(){
    unsigned int  a,b;
    time_t start,end;
    printf("Enter the elements:");
    scanf("%d %d",&a,&b);
    opcount=0;
    start=clock();
    int c=mul(a,b);
    end=clock();
    double totaltime=(end-start)/CLOCKS_PER_SEC;
    printf("\nResult: %d\n",c);
    printf("Total time: %e\n ",totaltime);
    printf("opcount: %d\n",opcount);
}