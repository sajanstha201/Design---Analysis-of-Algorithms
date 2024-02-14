#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int opcount=0;
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
int numberNode(NODE *root){
    if(root==NULL)
        return 0;
    else{
        opcount++;
        return numberNode(root->left)+numberNode(root->right)+1;
    }
}
void display(NODE * root){
    if(root==NULL)
        return;
    display(root->left);
    printf("%d\t",root->value);
    display(root->right);
}
int main(){
    int choice,i,j,k,node,value;
    time_t start,end;
    double totaltime;
    NODE *root=NULL;
    printf("1.insert\n2.display\n3.calculate node number\n4.exit\n");
    while(1){
        opcount=0;
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
            start=clock();
            node=numberNode(root);
            end=clock();
            totaltime=(double)(end-start)/CLOCKS_PER_SEC;
            printf("The node in tree is %d\n",node);
            printf("The opcount is %d\n",opcount);
            printf("The total time is %e\n",totaltime);
            break;
        case 4:
            return 0;
        default:
            printf("invalid choice");
        }
    }
    return 0;
}

