#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node *left,*right;
} NODE;

NODE* insert(NODE* root,int value){
    if(root==NULL){
        NODE *node=(NODE*)malloc(sizeof(NODE));
        node->value=value;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    if(value<root->value)
        root->left=insert(root->left,value);
    else if(value>root->value)
        root->right=insert(root->right,value);
    return root;
}
int height(NODE *root){
    if(root==NULL)
        return -1;
    else{
        int a=height(root->left);
        int b=height(root->right);
        if(a>b)
            return a+1;
        else
            return b+1;
    }
}
void display(NODE * root){
    if(root==NULL)
        return;
    display(root->left);
    printf("%d\t",root->value);
    display(root->right);
}
void main(){
    int choice,i,j,k,h,value;
    NODE *root=NULL;
    printf("1.insert\n2.display\n3.calculate height\n4.exit\n");
    while(1){
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter the number:");
            scanf("%d",&value);
            root=insert(root,value);
            break;
        case 2:
            display(root);
            printf("\n");
            break;
        case 3:
            h=height(root);
            printf("The height of tree is %d\n",h);
            break;
        case 4:
            return;
        default:
            printf("invalid choice");
        }
    }
}

