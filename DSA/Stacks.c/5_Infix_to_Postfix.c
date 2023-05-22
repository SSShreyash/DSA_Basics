#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    int size;
    char* arr;
};

void push(struct stack* s, int val){
    if(s->top == s->size-1){
        printf("Stack overload.\n");
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
        char val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int isOperator(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/'){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char a){
    
    if(a == '/' || a == '*'){
        return 3;
    }
    if(a == '+' || a == '-'){
        return 2;                   //Setting the Precedence of +,- lesser than *,/ 
    }

    return 0;
}

char* InfixtoPost(char* infix, struct stack* s){
    char* postfix;                                  //Just a pointer.
    postfix = (char*) malloc(sizeof(char)*strlen(infix));       //Now it is a string(char array).

    int i = 0;
    int j = 0;

    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){                                      //Not an operator,
            postfix[j] = infix[i];                                      //add to postfix.
            j++;
            i++;
        }
        else{                                                           //Operator, check precedence.
        //If operator(infix[i]) precedence greater than stack top precedence, or if stack has no operator left at top(empty stack),
            if( precedence(infix[i]) > precedence(s->arr[s->top]) || s->top == -1){     
                push(s,infix[i]);                                                   //push the operator(infix[i]) to stack.
                i++;
            }
            else{                                     //If precedence lower than or equal to current operator at top, 
                                                      //Unless stack is not empty,
                postfix[j] = pop(s);                  //pop the top until we get lesser precedence in stack top, 
                j++;                                  //by continuing the loop for same operator and incrementing postfix position.
            }
        }
    }           //Traversed through whole expression at end of loop.

    while(s->top!=-1){
        postfix[j] = pop(s);
        j++; 
    }

    postfix[j] = '\0';
    return postfix;
}

int main(){
    
    char* Infix;
    printf("Enter an infix expression: ");
    scanf("%s",Infix);
    printf("Infix expression: %s\n",Infix);

    struct stack* s;
    s = (struct stack*) malloc(sizeof(struct stack));
    s->size = strlen(Infix);
    s->top = -1;
    s->arr = (char*) malloc(sizeof(char) * s->size);

    printf("Equivalent Postfix Expression: %s",InfixtoPost(Infix,s));


    return 0;
}