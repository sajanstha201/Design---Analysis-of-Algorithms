#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
typedef struct node{
    int value;
    int f;
    struct node *left,*right;
    int code;
} NODE;
NODE *stack[100];
int top=-1;
void push(NODE * node){
    stack[++top]=node;
}
NODE* pop(){
    return stack[top--];
}

NODE* make_node(int value,int f){
    NODE * node=(NODE*)malloc(sizeof(NODE));
    node->value=value;
    node->f=f;
    node->right=NULL;
    node->left=NULL;
    return node;
}
void sort_stack(){
    int i,j;
    for(i=0;i<top+1;i++){
        for(j=0;j<top-i;j++){
            if(stack[j]->f<stack[j+1]->f){
                NODE * temp=stack[j];
                stack[j]=stack[j+1];
                stack[j+1]=temp;
            }
        }
    }
}
void print_all_code(NODE * root,int l,int *arr){
    arr[l]=root->code;
    if(root->left==NULL && root->right==NULL){
        int i;
        printf("code for frequency %d :",root->f);
        for(i=0;i<l+1;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    print_all_code(root->left,l+1,arr);
    print_all_code(root->right,l+1,arr);
}
void traverse(NODE *root){
    if(root==NULL)
        return;
    traverse(root->left);
    printf("%d-> %d  ",root->f,root->code);
    traverse(root->right);
    return;
}
void haffman_coding(int n){
    int i;
    while(1){
        sort_stack();
        NODE *a=pop();
        NODE *b=pop();
        NODE *c=make_node(-1,a->f+b->f);
        c->left=a;
        c->left->code=0;
        c->right=b;
        c->right->code=1;
        push(c);
        if(top==0)
            break;
    }
    NODE *root=pop();
    int arr[n];
    print_all_code(root,0,arr);
}
void main(){
    int n=5;
    int *arr=(int*)malloc(sizeof(int)*n);
    int i;
    for(i=0;i<n;i++)
        arr[i]=i+1;
    for(i=0;i<n;i++)
        push(make_node(i,arr[i]));
    haffman_coding(n);
}