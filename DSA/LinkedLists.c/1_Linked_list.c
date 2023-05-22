#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void displayLL(struct node*);

struct node* insertAtBegin(struct node* head, int data){
    struct node* ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;

    return ptr;
}

void insertAtEnd(struct node* head, int data){
    struct node* ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    struct node* traverse = head;

    while(traverse->next!=NULL){                        
        traverse = traverse->next;
    }
    //Loop ends with traverse->next now equal to NULL.(traverse pointing to last node)
    traverse->next = ptr; 

}

void insertAtPos(struct node* head, int data, int pos){
    struct node* new = malloc(sizeof(struct node));
    new->data = data;

    struct node* old = head;

    for(int i = 1; i < pos-1; i++){
        old = old->next;                //n executions will lead temp to position (n+1).
                                        //So we need (pos-2) executions to reach a node before given pos.
    }
    //We call function with pos as 3, so 1(pos-2) execution and temp points to 2nd(pos-1) node.
    new->next = old->next;          //For insertion first set the next for new node,using old node.
    old->next = new;                //Then make changes to old node after linking new node to the list.
    
}

void insert_After_Given_Node(struct node* givenNode, int data){
    struct node* ptr = malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = givenNode->next;
    givenNode->next = ptr;
}

struct node* deleteFirstNode(struct node* head){
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void deleteLastNode(struct node* head){
    struct node* p = head;
    struct node* q = head->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }                   //After loop finishes, q points to last and p points to 2nd last node in the list.

    p->next = NULL;
    free(q);
}

void deleteAtPos(struct node* head, int pos){
    struct node* p = head;
    struct node* q = head->next;
    for(int i = 1; i < pos-1; i++){
        p = p->next;
        q = q->next;
    }
    //p will be pos-1 node, q will be at the pos of node to delete.
    
    p->next = q->next;
    free(q);
}

struct node* deleteByData(struct node* head,int data){
    struct node* p = head->next;
    struct node* q = head;

    if(head->data == data){
        head = head->next;
        free(q);
    }
    
    else{
        while(p->next!=NULL && p->data!=data){
            p = p->next;
            q = q->next;
        }

        if(p->data == data){
            q->next = p->next;
            free(p);
        }
    }
    
    return head;

}

int main(){
    
    //Linked list with a single node(head).
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;     

    //Insert at beginning needs updating the head.
    head = insertAtBegin(head,5);       // 5 10             //O(1)
    insertAtEnd(head,12);               // 5 10 12          //O(n)
    insert_After_Given_Node(head,15);   // 5 15 10 12       //O(1)      will insert after the argument node passed(here head)
    insertAtPos(head,11,3);             // 5 15 11 10 12    //O(n)
    
    //displayLL(head);

    //Deletion of first node needs updation of the head.
    head = deleteFirstNode(head);       // 15 11 10 12      //O(1)
    deleteLastNode(head);               // 15 11 10         //O(n)
    deleteAtPos(head,2);                // 15 10            //O(n)
    insertAtEnd(head,12);               // 15 10 12
    head = deleteByData(head,10);       // 15 12            //O(n)    update head only if data is in head.
 
    displayLL(head);


    return 0;
}

void displayLL(struct node* head){
    struct node* ptr = head;

    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}