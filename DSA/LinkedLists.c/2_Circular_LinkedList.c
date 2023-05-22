#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void displayLL(node*);

void insertAtPos(node* head,int data,int pos){
    node* ptr = malloc(sizeof(node));
    ptr->data = data;

    node* temp = head;
    for(int i = 1; i<pos-1; i++){
        temp = temp->next; 
    }           //(pos-2) executions to reach (pos-1)th node.

    ptr->next = temp->next;
    temp->next = ptr;
}
    
void insertAtEnd(node* head, int data){
    node* ptr = malloc(sizeof(node));
    ptr->data = data;

    node* temp = head;

    while(temp->next!=head){
        temp = temp->next;
    }

    ptr->next = head;
    temp->next = ptr;
}

void deleteAtPos(node* head,int pos){
    node* p = head;
    node* q = head->next;

    for(int i = 1; i<pos-1; i++){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

}   

void deleteAtFirst(node** head_ref){
    node* temp = (*head_ref);
    node* last = (*head_ref);

    while(last->next!=(*head_ref)){
        last = last->next;
    }

    (*head_ref) = (*head_ref)->next;       // Head in main() updated as called by reference. 
    last->next = (*head_ref);              // Making last node point to new head.
    free(temp);

}

int main(){
    node* head = malloc(sizeof(struct node));
    head->data = 10;

    node* second = malloc(sizeof(struct node));
    second->data = 24;
    head->next = second;                    //After declaring second(line by line execution).
    
    second->next = head;                    //Circular linked list :- last node's next points back to head.
    
    displayLL(head);                       // 10 24

    insertAtPos(head,5,2);                  // 10 5 24 
    displayLL(head);
    
    insertAtEnd(head,12);                   // 10 5 24 12
    displayLL(head);
   
    deleteAtPos(head,3);                    // 10 5 12
    displayLL(head);
   
    deleteAtFirst(&head);           //O(n) for circular linked list.    O(1) for normal forward linear linked list.
                                    //Call by reference :- any change made to the head in function reflects to the head in main. 
    displayLL(head);                        // 5 12
    return 0;
}

void displayLL(node* head){        //Not necessary to call by reference as no change for head.
    node* ptr = head;            //We put (*head_ref) in paranthesis when using both * and -> operator.(Operator Precedence)
    do{
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);           //Loop to print linked list data but traversal is head to head and not head to null, 
                                  // so we use do while to run once for ptr = head and rest of the loop until ptr comes back to head.
    printf("\n");
}