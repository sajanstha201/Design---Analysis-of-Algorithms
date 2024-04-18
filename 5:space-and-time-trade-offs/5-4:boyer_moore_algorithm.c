#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int next_string(char *sentence, char *sub){
    int i,j,k;
    for(i=strlen(sentence)-strlen(sub)-1;i>=0;i--){
        for(j=strlen(sub)-1;j>=0;j--){
            if(sub[j]==sentence[i-strlen(sub)+j+1])
                continue;
            break;
        }
        if(j==-1)
            return strlen(sentence)-i-1;
    }
    return strlen(sentence);
}
int max(int a,int b){
    if(a>b)
        return a;
    else   
        return b;
}
bool boyer_moore(char *sentence, char *string, int * arr, int *arr_k){
    int i,j,k,l;
    int shift;
    for(i=0;i<strlen(sentence);i++){
        printf("\n\n%d\n",i);
        for(j=strlen(string)-1;j>=0;j--){
            if(i+j>=strlen(sentence))
                return false;
            if(string[j]==sentence[i+j])
                continue;
            printf("%c->%d %d->%d\n",sentence[i+j],arr[sentence[i+j]-'a']-strlen(string)+j+1,arr_k[strlen(string)-j-1],strlen(string)-j-2);
            shift=max(arr[sentence[i+j]-'a']-strlen(string)+j+1,arr_k[strlen(string)-j-2]);
            if(j==strlen(string)-1)
                shift=arr[sentence[i+j]-'a']-strlen(string)+j+1;
            break;
        }
        i=i+shift-1;
        if(j==-1)
            return true;
    }
    return false;
}
void main(){
    char sentence[]="shresthatha";
    char string[]="sh";
    int arr[27];
    int i,j,k;
    for(i=0;i<27;i++)
        arr[i]=strlen(string);
    for(i=0;i<strlen(string)-1;i++){
        arr[string[i]-'a']=strlen(string)-i-1;
        printf("%c -> %d\n",string[i],arr[string[i]-'a']);
    }
    int arr_k[strlen(string)];
    for(i=1;i<strlen(string)+1;i++){
        arr_k[i-1]=strlen(string);
        char *sub=(char*)malloc(sizeof(char)*(i+1));
        sub[i]='\0';
        for(j=i;j>=0;j--){
            sub[i-j]=string[strlen(string)-j];
        }
        
        arr_k[i-1]=next_string(string,sub);
        printf("%s ->%d\n",sub,arr_k[i-1]);
    }
    for(i=0;i<strlen(string);i++)
        printf("%d ",arr_k[i]);
    printf("\n");
    if(boyer_moore(sentence,string,arr,arr_k))
        printf("\navailable");
    else
        printf("\nnot available\n");
}