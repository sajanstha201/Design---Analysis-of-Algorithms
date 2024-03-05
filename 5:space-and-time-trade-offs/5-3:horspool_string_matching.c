#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
int opcount;
bool horspool(char * sentence, char * string){
    int arr[27];
    int i,k,j,a;
    for(i=0;i<27;i++)
        arr[i]=strlen(string);
    for(i=0;i<strlen(string)-1;i++)
        arr[string[i]-'a']=strlen(string)-i-1;
    for(i=strlen(string)-1;i<strlen(sentence);){
        k=i;
        for(j=strlen(string)-1;j>=0;j--){
            opcount++;
            if(string[j]!=sentence[k]){
                if(97<=sentence[k] && sentence[k]<=123)
                    i=i+arr[sentence[i]-'a'];
                else
                    i=i+arr[26];
                break;
            }
            k--;
            
        }
        if(j==-1)
            return true;
    }
    return false;
}
void main(){
    char sentence[100],string[100];
    double totaltime;
    opcount=0;
    printf("Enter the sentence:");
    scanf(" %[^\n]",sentence);
    printf("\nEnter the string:");
    scanf(" %[^\n]",string);
    time_t start,end;
    start=clock();
    bool string_match=horspool(sentence,string);
    end=clock();
    totaltime=(start-end)/CLOCKS_PER_SEC;
    if(string_match)
        printf("substring is available\n");
    else
        printf("substring is not available\n");
    printf("Total time is %e\n",totaltime);
    printf("opcount is %d\n",opcount);
}