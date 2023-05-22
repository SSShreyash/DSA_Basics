#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

void displayLL(struct node* head);

void push(struct node* ptr){

}

void reverse(struct node** head_ref){
    struct node* curr = *head_ref;
    struct node* next = *head_ref;

    while(curr->next!=NULL){            //We run upto curr->next!=NULL to cover all nodes except last node,
        next = curr->next;              //next always points to original linked list's curr->next.
        curr->next = curr->prev;
        curr->prev = next;
        curr = next;                    //Running this for last node, 'curr' will point to NULL.
    }
    //So, we swap pointers for last node outside the loop without updating 'curr' which will now point to last node.
    
    next = curr->next;              //next pointing to NULL.         
    curr->next = curr->prev;        //Original last node's next updated with last 2nd node's address.
    curr->prev = next;              //Original last node's prev updated to NULL(original last node's next).

    *head_ref = curr;           //Updating the head with original linked list's last node.
    
}

int main(){

    struct node* head = malloc(sizeof(struct node));
    head->data = 15;
    head->prev = NULL;

    struct node* second = malloc(sizeof(struct node));
    second->data = 21;
    second->prev = head;
    head->next = second;

    struct node* third = malloc(sizeof(struct node));
    third->data = 11;
    third->prev = second;
    second->next = third;

    struct node* fourth = malloc(sizeof(struct node));
    fourth->data = 132;
    fourth->prev = third;
    third->next = fourth;
    fourth->next = NULL;
    
    displayLL(head);

    reverse(&head);
    displayLL(head);
    
    return 0;
}

void displayLL(struct node* head){
    struct node* temp = head;

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }

    printf("\n");
}