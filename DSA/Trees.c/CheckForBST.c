#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* LC;
    struct node* RC;
};

struct node* createNode(int data){
    struct node* n = malloc(sizeof(struct node));
    n->data = data;
    n->LC = NULL;
    n->RC = NULL;
    
    return n;
}

int checkBST(struct node* root, int minimum, int maximum){
    if(root == NULL){
       return 1; 
    }
    else{
        if(root->data < maximum && root->data > minimum             //Check if Root in range min to max.
        && checkBST(root->LC, minimum, root->data)                  //Check for left subtree using recursion until root becomes NULL.
        && checkBST(root->RC, root->data, maximum)){                //Check for right subtree by updating min as present call's root->data.
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main(){
    struct node* root = createNode(6);
    struct node* c1 = createNode(3);
    struct node* c2 = createNode(9);
    struct node* c1c1 = createNode(1);
    struct node* c1c2 = createNode(4);
    struct node* c2c1 = createNode(7);
    struct node* c2c2 = createNode(13);

    root->LC = c1;
    root->RC = c2;

    c1->LC = c1c1;
    c1->RC = c1c2;

    c2->LC = c2c1;
    c2->RC = c2c2;

    int check = checkBST(root,INT_MIN,INT_MAX);

    if(check){
        printf("BST.");
    }
    else{
        printf("Not a BST.");
    }
    return 0;
}