#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* LC;
    struct node* RC;
};

struct node* createNode(int data){
    struct node* new = malloc(sizeof(struct node));
    new->data = data;
    new->LC = NULL;
    new->RC = NULL;
    
    return new;
}

//Recursive Approach.
/*struct node* search(struct node* root, int key){                //Searching on the basis of key value.
    if(root == NULL){                               //Terminating recursion condition.(When recursion called for leaf node.)
        return NULL;
    }

    else{
        if(root->data == key){
            return root;
        }
        
        else if(root->data < key){
            return search(root->RC, key);           //Calls need to be returned or NULL outside conditions will be implemented.
        }
        
        else{
            return search(root->LC, key);
        }   
    }
    
    return NULL;                       //Incase node with key data not in BST.
}
*/
//Iterative Approach.

struct node* search(struct node* root, int key){
    
    while(root!=NULL){                  //Just like recursion terminating condition is to traverse until we reach leaf node.
        if(root->data < key){
            root = root->RC;
        }
        else if(root->data > key){
            root = root->LC;
        }
        else{
            return root;
        }
    }

    return NULL;            //Either root = NULL or no node with key as it's data.
    
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

    struct node* ptr = malloc(sizeof(struct node));
    ptr = search(root,13);

    if(ptr!=NULL){
        printf("Found. Data = %d\n",ptr->data);
    }
    else{
        printf("Node not found.\n");
    }

    return 0;
}