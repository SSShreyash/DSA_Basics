#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};

void display(struct stack*);

int isEmpty(struct stack* s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack* s){
    if(s->top == s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* s, int val){
    if(isFull(s)){
        printf("Stack overflow! %d couldn't be pushed\n",val);
    }
    else{
        s->top++;
        s->arr[s->top] = val;
    }
}

int pop(struct stack* s){
    if(isEmpty(s)){
        printf("Stack Empty.\n");
        return -1;
    }
    else{
        int x = s->arr[s->top];
        s->top--;
        return x;
    }

}

void insertAtBottom(struct stack* s, int item){
    //Base condition for recursion is when stack becomes empty.
    if(s->top == -1){           //Empty stack push 'item' which is the last element(at 0th index) taken from reverse func.
        push(s,item);           //This part actually adds to the bottom of stack. 
                                //else part empties the stack to make this condition true and then restores the stack for every call.
    }

    else{
        int temp = pop(s);              
        insertAtBottom(s,item);         //Function call stack, after storing stack elements in temp recurse to create call stack.
        //After base condition is true, execute the if() and
        push(s,temp);                   //this will run for all the function calls stacked from last to first.
        // Next Recursive Function call for reverse() will call insertAtBottom(s, item2) where item2 is changed item,i.e., 2nd last(2nd from bottom) element.
        // then this func will empty the stack again and add item2 at bottom in base condition.
        //So, new stack will have extra elements at bottom and top of original stack will be omitted at each call.
    }

}

void reverse(struct stack* s){
    if(s->top == -1){
        return;
    }
    else{
        int item = pop(s);              //Store stack elements in item. Recurse until stack is empty. 
        reverse(s);                     //Calls from Function call stack will execute for last element to first(top) of stack. 
        insertAtBottom(s,item);         //Insert last element(0th index) at bottom.
        //Base condition of insertAtBottom() is satisfied for each recursive call there.
        //Only the item changes as per the function call stack of reverse() from last element to 1st element. 
        //For every reverse() call, the stack will be restored, elements will be inserted at bottom and top will be omitted for each call.
        //For last call, the push will run for only as many times as it takes to make stack empty.So, after adding one at bottom
        //Top has to be omitted one by one leading to only inserted elements' stack.
    }
}

//One call of reverse() calls all the recursive function calls for insertAtBottom(). 
int main(){
    struct stack* s;
    s->size = 100;
    s->top = -1;
    s->arr = (int*) malloc(sizeof(int) * s->size);

    push(s,3);
    push(s,45);
    push(s,16);
    push(s,81);
    push(s,14);
    display(s);
    
    reverse(s);
    display(s);

    return 0;
}


void display(struct stack* s){
        for(int i = 0; i<=s->top; i++)
            printf("%d ", s->arr[i]);
        printf("\n");
    }