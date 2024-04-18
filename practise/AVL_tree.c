#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int value;
    struct node *left,*right;
    int bf;
} NODE;
NODE* RR(NODE * root){
    NODE *next_root=root->left;
    NODE * temp=root->left->right;
    next_root->right=root;
    root->left=temp;
    return next_root;
}
NODE* LL(NODE * root){
    NODE *next_root=root->right;
    NODE *temp=root->right->left;
    next_root->left=root;
    root->right=temp;
    return next_root;
}
NODE* LR(NODE * root){
    root->left=LL(root->left);
   return  RR(root);
}
NODE* RL(NODE * root){
    root->right=RR(root->right);
    return LL(root);
}
int balance_factor(NODE * root){
    if(root==NULL)
        return 0;
    int a=balance_factor(root->left);
    int b=balance_factor(root->right);
    root->bf=a-b;
    if(a>b)
        return a+1;
    else
        return b+1;
}
NODE* insert(NODE *root, int value){
    if(root==NULL){
        NODE * node=(NODE*)malloc(sizeof(NODE));
        node->value=value;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    if(value<root->value)
        root->left=insert(root->left,value);
    else if(value>root->value)
        root->right=insert(root->right,value);
    balance_factor(root);
    if(root->bf>=2){
        if(value<root->left->value)
            root=RR(root);
        else
            root=LR(root);
    }
    else if(root->bf<=-2){
        if(root->right->value<value)
            root=LL(root);
        else
            root=RL(root);
    }
    return root;
}
void display(NODE * root){
    if(root==NULL)
        return;
    display(root->left);
    printf("%d->%d ",root->value,root->bf);
    display(root->right);
}
void main(){
    NODE *root=NULL;
    root=insert(root,50);
    root=insert(root,40);
    root=insert(root,30);
    root=insert(root,35);
    root=insert(root,25);
    root=insert(root,55);
    root=insert(root,53);
    balance_factor(root);
    display(root);
}