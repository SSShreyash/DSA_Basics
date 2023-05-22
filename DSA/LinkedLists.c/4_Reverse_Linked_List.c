#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void displayLL(struct node* head);

struct node* reverse(struct node* head){                    // 3 pointers needed for reversing a singly Linked List.
    struct node* curr = head;
    struct node* prev = NULL;
    struct node* next = NULL;

    while(curr!=NULL){                      //At max 2 pointers pointing to same node at a time.(prev and curr) or (curr and next).
        next = curr->next;                  //All 3 cannot point to same node at any point in traversal.
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;                            // prev points to the last node of main() linked list.
    return head;

}


int main(){
    struct node* head = malloc(sizeof(struct node));
    head->data = 15;

    struct node* second = malloc(sizeof(struct node));
    second->data = 21;
    head->next = second;

    struct node* third = malloc(sizeof(struct node));
    third->data = 11;
    second->next = third;

    struct node* fourth = malloc(sizeof(struct node));
    fourth->data = 132;
    third->next = fourth;
    fourth->next = NULL;
    
    displayLL(head);

    head = reverse(head);
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