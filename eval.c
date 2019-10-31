#include<stdio.h>
#define MAX 100

char str[MAX];
int stack[MAX];
int  top = -1;
typedef enum{
       lparen, rparen, times, div, mod, sum, minus, eos, operand 

}precedense;


precedense gettoken(char *symbol, int *num){
    *symbol = str[(*num)++];
    switch(*symbol){
        case '(': return lparen ; break;
        case ')': return rparen; break;
        case '+': return sum; break;
        case '-': return minus; break;
        case '*': return times; break;    
        case '/': return div; break;
        case '%': return mod; break;
        case '\0': return eos; break;
        default : return operand;     
    }
}

void push(int element){
    stack[++top] = element;

}

int pop(){
    return stack[top--];
}


void evaluation(){
        char symbol;
        int n=0;
        precedense tok = gettoken(&symbol, &n);
        while(tok!= eos){
            if(tok == operand)
                    push(symbol-'0');
            else{
                    int op1 = pop(), op2 = pop();
                    switch(tok){
                        case sum: push(op1+op2); break;
                        case minus: push(op1-op2); break;
                        case times: push(op1*op2); break;   
                        case div: push(op1/op2); break;
                        case mod: push(op1%op2); break;                        
                                            
                    }
            }   
            tok = gettoken(&symbol, &n);

        }

        printf("%d",pop());
}



void main(){
    printf("enter the postfix term");
    gets(str);
    evaluation(); 

}
