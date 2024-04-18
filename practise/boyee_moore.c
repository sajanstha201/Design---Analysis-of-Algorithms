#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void find_next(char * w,int *arr){
    int i,j,k;
    for(i=strlen(w)-1;i>=0;i--){
        k=(strlen(w)-i);
        char *sub=(char *)malloc(sizeof(char)*(k+1));
        sub[k]='\0';
        for(j=strlen(w)-1;j>=i;j--){
            sub[--k]=w[j];
        }
        printf("%s \n",sub);
    }
}
void main(){
    char sentence[100];
    char *string;
    printf("Entr sentence:");
    scanf(" %[^\n]",sentence);
    int arr_k[strlen(sentence)];
    find_next(sentence,arr_k);
}