#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int* arr;
    int size;
};

int isEmpty(struct stack *s){
    if(s->top == -1){
        return 1;
    }
    else
        return 0;
}

int isFull(struct stack* s){
    if(s->top == s->size-1)
        return 1;
    else
        return 0;
}

void push(struct stack* s, int val){                //For push() we don't return, but we take a value to be pushed to stack as argument.
    if(isFull(s)){
        printf("\nStack overflow! Value %d can't be pushed.\n",val);
    }
    else{
        s->top++;                             //We use top to refer to index so increasing it everytime push is called.
        s->arr[s->top] = val;                   //set arr[top] = argument passed as val.
        printf("%d pushed to stack\n",val);
    }
    
}

int pop(struct stack* s){                     //For pop() we always pop the top element in stack and return value popped out from stack.(LIFO)
    int val = -1;
    if(isEmpty(s)){
        printf("\nNo element to pop. Stack Empty!\n");
    }
    else{
        val = s->arr[s->top];
        s->top--;
        printf("\nPopped value: %d\n",val);
    }
    return val;
}

//For stack using array, the elements are returned from top to bottom(LIFO) and index starts from 0 which points to bottom(last position.)
//For position(pos), the array index will be (top-pos) + 1 as top represents index of last element.
//Consider for 2nd element--: index should be top-1 as 1st element will always be at index top, i.e. top-2 + 1
void peek(struct stack* s, int pos){
    printf("%d\n",s->arr[(s->top)-pos + 1]);
}

void stackTop(struct stack *st){
    printf("Top: %d\n",st->arr[st->top]);
}

void stackBottom(struct stack* st){
    printf("Bottom: %d\n",st->arr[0]);
}

int main(){
    //Empty stack of size 10.
    struct stack* st;                                      //st is just a struct pointer. 
    st = (struct stack*) malloc(sizeof(struct stack));     //To create a stack we dynamically allocate for 1 stack.
                                                           //So, memory for 1 struct(stack) containing top,size and an integer arr allocated.
    st->size = 10;
    st->top = -1;
    st->arr = (int* )malloc(st->size*sizeof(int));
     
    /*Checking for empty and full*/
    printf("\n1 for true and 0 for false.\n");
    printf("Earlier----Empty: %d\n",isEmpty(st));
    printf("Earlier----Full: %d\n",isFull(st));
    

    push(st,1);
    push(st,2);
    push(st,3);
    push(st,4);
    push(st,5);
    push(st,6);
    push(st,7);
    push(st,8);
    push(st,9);
    push(st,10);
    
    push(st,11);                    //Stack overflow. 11 won't be in stack.
   
    /*Checking for empty and full*/
    printf("\n1 for true and zero for false.\n");
    printf("Later----Empty: %d\n",isEmpty(st));
    printf("Later----Full: %d\n",isFull(st));

    int x = pop(st);                       //10 was popped out.
    
    //peek(st,3);                    //3rd element from top will be 7 as 10 was popped already.
    printf("\nPrinting the stack using peek():\n");
    for(int pos=1; pos<=(st->top)+1; pos++){             //index for element at pos = (top-pos)+1. And index should be minimum 0.  
        peek(st,pos);                               //So, we run peek() upto (top+1)-pos = 0 which gives the last value in stack for index 0.
    }

    stackTop(st);
    stackBottom(st);
    
    return 0;
}