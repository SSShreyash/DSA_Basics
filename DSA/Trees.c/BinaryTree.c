#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* LC;
    struct node* RC;
};

struct node* createNode(int data){
    struct node* node = (struct node* )malloc(sizeof(struct node));
    node->data = data;
    node->LC = NULL;
    node->RC = NULL;
    return node;
}

void preOrder(struct node* root){
    if(root!=NULL){                 //Condition to stop recursion for each call.(For nodes if we recurse the function root will become NULL so next call would give nothing for that recursion.) 
        printf("%d ", root->data);
        preOrder(root->LC);
        preOrder(root->RC);
    }
}

void postOrder(struct node* root){
    if(root!=NULL){                     //Function calls stack one upon another in recursion and the previous is executed once last is termianated.
        postOrder(root->LC);
        postOrder(root->RC);
        printf("%d ",root->data);
    }
}

void Inorder(struct node* root){
    if(root!=NULL){
        Inorder(root->LC);
        printf("%d ",root->data);
        Inorder(root->RC);
    }
}

int main(){
    struct node* root = createNode(2);
    struct node* c1 = createNode(4);
    struct node* c2 = createNode(6);
    struct node* c3 = createNode(3);
    struct node* c4 = createNode(1);
    struct node* c5 = createNode(7);
    struct node* c6 = createNode(5);

    root->LC = c1;
    root->RC = c2;

    c1->LC = c3;
    c1->RC = c4;
    
    c2->LC = c5;
    c2->RC = c6;

    preOrder(root);
    printf("\n");

    postOrder(root);
    printf("\n");

    Inorder(root);

    return 0;
}