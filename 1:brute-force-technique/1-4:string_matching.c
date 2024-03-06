#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
bool stringMatching(char * sentence,char * string){
    int i,j,k;
    for(i=0;i<strlen(sentence)-strlen(string)+1;i++){
        k=i;
        for(j=0;j<strlen(string);j++){
            if(sentence[k]!=string[j]){
                break;
            }
            k++;
        }
        if(j==strlen(string)){
            return true;
        }
    }
    return false;
}
void main(){
    printf("Enter the sentence: ");
    char sentence[100],string[100];
    scanf(" %[^\n]",sentence);
    printf("Enter the string: ");
    scanf(" %[^\n]",string);
    if(stringMatching(sentence,string))
        printf("Substring Found\n");
    else
        printf("Substring not found\n");

}