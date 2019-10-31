#include<stdio.h>
#define MAX 100

typedef enum{
       lparen, rparen, times, div, mod, sum, minus, eos, operand 

}precedense;

int isp[] = { 0,19,13,13,13,12,12,0};
int icp[] = { 20,19,13,13,13,12,12,0};

int top =0;
int stack[MAX];
char str[MAX];

precedense gettoken(char *symbol, int *num){
        *symbol = str[(*num)++];
        switch(*symbol){
            case '(': return lparen; break;
            case ')': return rparen; break;
            case '*': return times; break;
            case '/': return div; break;
            case '%': return mod; break;
            case '+': return sum; break;
            case '-': return minus; break;
            case '\0' : return eos; break;
            default: return operand;
         }          



}


char printtoken(precedense token){
        switch(token){
            case lparen: printf("("); break;
	    	case rparen: printf(")"); break;
	    	case sum: printf("+"); break;
	    	case minus: printf("-"); break;
	    	case times: printf("*"); break;
	    	case div: printf("/"); break;
	    	case mod: printf("%%"); break;
	
            
         }          


}

void push(precedense token){
    stack[++top] = token;

}

char pop(){
    return stack[top--];
}


void token(){
    int n=0;
    char symbol;   
    stack[0]= eos; 
    precedense tok = gettoken(&symbol, &n);
    while(tok!=eos){
            if(tok == operand)
                    printf("%c", symbol);
            else if(tok == rparen){
                    while(stack[top] != lparen)
                           printtoken(pop());
                    pop();
                }

            else{
                    if(isp[stack[top]]>=icp[tok])
                            printtoken(pop());
                    push(tok);
                    // printf("%d",top);
            }
            tok = gettoken(&symbol, &n);
    }
    // for(int i=top; i>=0;i--)
    // 		printf("%d",stack[i]);
    // printf("%d",top);
    while((tok = pop())!=eos)
            printtoken(tok);    
}    


void main(){
    printf("enter the infix statement");
    scanf("%s",str);
    token();
    printf("\n");


}
