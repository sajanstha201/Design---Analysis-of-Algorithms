#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int opcount;
typedef struct node{
    int lvalue,mvalue,rvalue;
    struct node *left,*middle,*right;
}NODE;
NODE* insert(NODE*root, int value){
    
}
void main(){
    time_t start,end;
    double totaltime;
    printf("1.insert\n2.display\n3.exit\n");
    int choice,value;
    NODE *root=NULL;
    while(1){
        opcount=0;
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the number: ");
                scanf("%d",&value);
                root=insert(root,value);
                display(root);
                printf("\n");
                break;
            case 2:
                findFactor(root);
                display(root);
                printf("\n");
                break;
            case 3:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}