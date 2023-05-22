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

//val to be added to BST.
void insert(struct node* root, int val){            
    struct node* prev;
    while(root!=NULL){
        prev = root;
        if(val > root->data){
            root = root->RC;
        }
        else if(val < root->data){
            root = root->LC;
        }
        else{                                   //root->data == val
            printf("%d already in BST. Duplicates not allowed for BST.\n",val);
            return;
        }
    }

    struct node* new = createNode(val);
    if(prev->data < val){
        prev->RC = new;
    }
    else if(prev->data > val){
        prev->LC = new;
    }

}

//Inorder Pre For Deletion.
struct node* InorderPre(struct node* node){     //Inorder pre of a node is,
    node = node->LC;                        //node's Left Subtree's  
    while(node->RC!=NULL){                  //Right-Most child.
        node = node->RC;
    }
    return node;
}
//Similarly, Inorder post for a node is node's right subtree's left-most child.

//Delete the node with key as data.
struct node* delete(struct node* root, int key){            
    struct node* InPre;

    if(root == NULL)
        return NULL;

    if(root->LC == NULL && root->RC == NULL && root->data == key){      //Leaf node is the target node to delete.
        free(root);
        return NULL;                        //We need to return to main else it will throw garbage value for deleted element.
    }

    else{                       //Search for node to be deleted.
        if(root->data < key){
            root->RC = delete(root->RC, key);
        }
        else if(root->data > key){
            root->LC = delete(root->LC, key);
        }
        else{                          //(root->data == key) but node is not leaf node.(Case 2 and 3)
            InPre = InorderPre(root);  //Case2 if node's child are leaf nodes we replace deleted node by it's InorderPre or InorderPost.
            root->data = InPre->data;  //Deletion by overwriting the target node data with inorder predecessor's data.
            root->LC = delete(root->LC,InPre->data);  //Case3 if node to delete is root node or a node with height>2, 
                                                      //we recurse case2 until there's no duplicate node left.
        }
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

    //insert(root,8);                 //Insertion in an already given BST always takes place at leaf node.
    //printf("%d", root->RC->LC->RC->data);   //So, 8 will be inserted at (root->RC->LC)(that is 7 for given BST)->RC.
    /*
    printf("%d\n",root->RC->RC->data);
    delete(root,9);
    printf("%d\n",root->RC->data);            
    printf("%d\n",root->RC->RC->data);        
    */

    Inorder(root);
    delete(root,1);             //We store the return value in function itself while recursion until it becomes NULL.
    printf("\n");
    Inorder(root);

    return 0;
}