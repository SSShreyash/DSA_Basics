#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    int size;
    char* arr;                          //Char array(string) in stack, to check for each element in string expression in main().
};

void push(struct stack* s, char val){
    if(s->top == s->size-1){
        printf("Stack overload! Cannot push %c.\n",val);
    }
    else{
        s->top++;
        s->arr[s->top] = val;
    }
}

char pop(struct stack* s){
    if(s->top == -1){
        return -1;
    }
    else{
        int val = s->arr[s->top];
        s->top--;
        return val;
    }

}

int match(char a, char b){
    if( a == '(' && b == ')' ){
        return 1;
    }
    if( a == '{' && b == '}' ){
        return 1;
    }
    if( a == '[' && b == ']' ){
        return 1;
    }

    return 0;                   //If any if condition doesn't satisfy.
}

int ParanthesisCheck(struct stack* s, char* exp){
    
    for(int i = 0; exp[i]!='\0'; i++){
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '('){                //Push in stack if any of the open brackets.
            push(s,exp[i]);
        }
        else if(exp[i] == '}' || exp[i] == ']' || exp[i] == ')'){           //Pop open bracket from stack for a closed bracket .

            char popped_ch = pop(s);
            if(popped_ch == -1){                    //Imbalanced if no opening brackets in stack.
                return 0;
            }
            if(match(popped_ch,exp[i]) == 0){       //Imbalanced if opening bracket popped doesn't match with closing bracket.
                return 0;                           //If any bracket is opened only the matching closed bracket should pop it.
            }
        }
    }

    if(s->top == -1){                       //Balanced if stack is finally empty after all push and pop operations.
        return 1;
    }
    else{
        return 0;
    }

}

int main(){

    char* exp = "{8+2*(3-1)-([4*)6]}";

    struct stack* s;
    s = (struct stack*) malloc(sizeof(struct stack));
    s->top = -1;
    s->size = strlen(exp);
    s->arr = (char*) malloc(sizeof(char)* s->size);

    if(ParanthesisCheck(s,exp)){
        printf("Paranthesis balanced.\n");
    }
    else{
        printf("Paranthesis not balanced.\n");
    }


    return 0;
}