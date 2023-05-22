#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
        return 0;
}

int isFull()
{                                                   // Stack is represented by linked list which will be increasing with nodes until heap memory is full.
    struct node *ptr = malloc(sizeof(struct node)); // Creating a new node with ptr pointing to it.
    if (ptr == NULL)
    { // Could not create new node as heap memory was full, and ptr points to null.
        return 1;
    }
    else
        return 0;
}

struct node *push(struct node *top, int data)
{
    if (isFull())
    {
        printf("Heap memory overload.");
        return top;
    }
    else                                                // For push() we insert a node at first position(top) and make it new top.
    {
        struct node *ptr = malloc(sizeof(struct node)); 
        ptr->data = data;
        ptr->next = top;
        return ptr;
    }
}

int pop(struct node **top_ref)                          // We pass top node by reference as we need to update the top from main().
{ 
    if (isEmpty(*top_ref))
    {
        printf("No element to pop. Stack Empty!\n");
    }

    else
    {
        int r = (*top_ref)->data;           // Storing the value at top to be deleted.
        struct node *temp = *top_ref;       // *top_ref gives top.
        *top_ref = (*top_ref)->next;        // For pop(), we move the top to next node.
        free(temp);                         // Deletes the previous top as temp pointed to previous top.
        return r;                           // Returning the deleted value.
    }
}

void peek(struct node *top, int pos)
{
    struct node *temp = top;
    int i;
    for (i = 1; (i < pos && temp != NULL); i++)             //(pos-1) executions to reach node at pos.
    { 
        temp = temp->next;
    }

    if (temp != NULL)
    {
        printf("%d at pos %d.\n", temp->data, i);
    }
    else
    {
        printf("Invalid input.\n");
    }
}

void stackTop(struct node* top){
    printf("Top: %d\n",top->data);
}

void stackBottom(struct node* top){
    struct node* temp = top;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    printf("Bottom: %d",temp->data);
}

void displayLL(struct node *);

int main()
{
    int returnVal;
    // Nodes are the elemets of stack with top node referring to 1st(head) node in list.
    // Linked list with single node 'top'.
    struct node *top = malloc(sizeof(struct node)); //top will be the 1st node in linked list.So, last position in stack will be at top.(LIFO)
    top->data = 24;                                 //and we will do insertion/deletion in stack w.r.t. top.
    top->next = NULL;

    printf("\n1 for true and 0 for false.\n");
    printf("Empty: %d\n", isEmpty(top));
    printf("Full: %d\n", isFull());

    returnVal = pop(&top);      //Update the top node to top->next and free previous top.Return deleted value from previous top.
    printf("%d popped.\n", returnVal);
    returnVal = pop(&top);      //Stack empty as top is popped above, so this will return nothing and Stack empty message will be prompted.

    printf("\n1 for true and 0 for false.\n");
    printf("Empty: %d\n", isEmpty(top));
    printf("Full: %d\n", isFull());

    top = push(top, 4);
    top = push(top, 9);
    top = push(top, 31);

    printf("\n1 for true and 0 for false.\n");
    printf("Empty: %d\n", isEmpty(top));
    printf("Full: %d\n", isFull());

    displayLL(top); // Traversing through linked list to get our stack.

    peek(top,3);
    peek(top,4);    //Invalid as only 3 elements present in stack(linked list).
    peek(top,1);


    stackTop(top);
    stackBottom(top);


    return 0;
}

void displayLL(struct node *head)
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}
