#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

void displayDLL(struct node* );

void insertAtPos(struct node* head,int data,int pos){
    struct node* ptr = malloc(sizeof(struct node));
    ptr->data = data;

    struct node* p = head;

    for(int i = 1;i<pos;i++){           //We go directly to pos for doubly linked list.
        p = p->next;            
    }

    ptr->prev = p->prev;
    p->prev->next = ptr;
    p->prev = ptr;
    ptr->next = p;
}

struct node* insertAtFirst(struct node* head,int data){

    struct node* ptr = malloc(sizeof(struct node));
    ptr->data = data;

    head->prev = ptr;
    ptr->next = head;
    ptr->prev = NULL;
    
    head = ptr;
    
    return head;

}

void deleteAtPos(struct node* head,int pos){
    struct node* temp = head;

    for(int i = 1; i<pos; i++){                      // i always starts from 1 to run upto pos-1.
        temp = temp->next;                           // (pos-1) executions will result to temp pointing to node at pos.
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);

}

void deleteAtEnd(struct node* head){
    struct node* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}


int main(){
    
    struct node* head = malloc(sizeof(struct node));
    head->data=21;
    head->prev = NULL;
    
    struct node* base_second = malloc(sizeof(struct node));
    base_second->data=14;
    base_second->prev = head;
    head->next = base_second;

    struct node* base_last = malloc(sizeof(struct node));
    base_last->data=32;
    base_last->prev = base_second;   
    head->next->next = base_last;                            //Can also be written as second->next = third;
    base_last->next = NULL;

    printf("Base list:\n");
    displayDLL(head);                                     // 21 14 32

    insertAtPos(head,5,2);                                // 21 5 14 32
    displayDLL(head);

    head = insertAtFirst(head,51);                        // 51 21 5 14 32
    displayDLL(head);

    deleteAtPos(head,3);                                  // 51 21 14 32
    displayDLL(head);

    deleteAtEnd(head);                                    // 51 21 14
    displayDLL(head);

    return 0;
}

void displayDLL(struct node* head){
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
    printf("\n");

}