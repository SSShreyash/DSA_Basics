#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void enqueue(struct node** f_ref, struct node** r_ref, int val){
    struct node* ptr = malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Queue overload. Heap memory full.");
    }
    else{
        ptr->data = val;
        if((*f_ref) == NULL){               //Check for empty. If front NULL, rear will also be NULL and queue will be empty.
            *f_ref = *r_ref = ptr;          //Front = Rear = ptr(New enqueued node).
        }
        else{
            (*r_ref)->next = ptr;           //Add next to rear.
            (*r_ref) = (*r_ref)->next;       //Increment rear. Newly enqueued node(ptr) will be the rear.
        }
    }
}

int dequeue(struct node** f_ref){
    
    if((*f_ref) == NULL){
        printf("Queue empty.\n");
        return -1;
    }
    else{
        int val = (*f_ref)->data;
        
        struct node* temp = (*f_ref);
        (*f_ref) = (*f_ref)->next;
        free(temp);
        return val;
    }
}

int main(){
    struct node* front = NULL;                     
    struct node* rear = NULL;           //When empty, both pointers will be NULL.      

    //We have to change the pointers front and rear to enqueue or dequeue from the queue as they point to position of element(node).
    //So we call front and rear by reference using **front_ref and **rear_ref in function arguments and passing address in call. 

    enqueue(&front,&rear,6);
    printf("%d dequeued.\n",dequeue(&front));

    return 0;
}