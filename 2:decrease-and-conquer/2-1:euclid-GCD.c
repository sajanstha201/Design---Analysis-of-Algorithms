#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int opcount;
int gcd(int a,int b){
    opcount++;
    if(a<b)
        return gcd(b,a);
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void main(){
    printf("Enter two element: ");
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    time_t start,end;
    opcount=0;
    start=clock();
    int c=gcd(a,b);
    end=clock();
    double totaltime=(end-start)/CLOCKS_PER_SEC;
    printf("GCD of %d and %d is %d\n",a,b,c);
    printf("opcount: %d\n",opcount);
    printf("total time: %e\n",totaltime);
}