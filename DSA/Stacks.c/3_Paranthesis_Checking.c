#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    int size;
    char* arr;                          //Char array(string) in stack, to check for each element in string expression in main().
};

int isEmpty(struct stack* s){
    if(s->top == -1){
        return 1;
    }
    else{                       //else can be avoided when returning in if statement.
        return 0;
    }
}

int isFull(struct stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack *s, char val){
    if(isFull(s)){
        printf("Stack overload.\n");
    }
    else{
        s->top++;
        s->arr[s->top] = val;
    }
}

char pop(struct stack* s){
    if(isEmpty(s)){
        return -1;
    }
    else{
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int ParanthesisCheck(struct stack* s, char* exp){
    int val;
    for(int i = 0; i<strlen(exp); i++){
        if( exp[i] == '(' ){
            push(s,exp[i]);
        }
        else if( exp[i] == ')' ){
            val = pop(s);
            if(val == -1){
                return 0;
            }
        }
    }

    if(isEmpty(s)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    char* exp = "(4+2)*8)((-3+1)";
    
    struct stack* s;
    s = (struct stack*) malloc(sizeof(struct stack));
    s->size = strlen(exp);
    s->top = -1;
    s->arr = (char*) malloc(s->size*sizeof(char));
    
    if(ParanthesisCheck(s,exp)){
        printf("Paranthesis are balanced.\n");
    }
    else{
        printf("Paranthesis not balanced.\n");
    }

    return 0;
}