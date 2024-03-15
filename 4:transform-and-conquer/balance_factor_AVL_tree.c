#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct node{
    int value;
    struct node *left,*right;
    int f;
}NODE;
int opcount;
NODE *insert(NODE *root,int value){
    if(root==NULL){
        NODE *node=(NODE*)malloc(sizeof(NODE));
        node->f=0;
        node->value=value;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    if(value<root->value)
        root->left=insert(root->left,value);
    else
        root->right=insert(root->right,value);
    return root;
}
int findFactor(NODE *root){
    if(root==NULL)
        return 0;
    opcount++;
    int a=findFactor(root->left);
    int b=findFactor(root->right);
    root->f=a-b;
    if(a>b)
        return a+1;
    else
        return b+1;
}
void display(NODE *root){
    if(root==NULL)
        return;
    display(root->left);
    printf("%d -> %d \t",root->value,root->f);
    display(root->right);
}
void main(){
    time_t start,end;
    double totaltime;
    printf("1.insert\n2.display\n3.find factor\n4.exit\n");
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
                break;
            case 2:
                display(root);
                printf("\n");
                break;
            case 3:
                start=clock();
                findFactor(root);
                end=clock();
                totaltime=(double)(end-start)/CLOCKS_PER_SEC;
                printf("The opocunt is %d\n",opcount);
                printf("The total time is %e\n",totaltime);
                display(root);
                printf("\n");
                break;
            case 4:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}