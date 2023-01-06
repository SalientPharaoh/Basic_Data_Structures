#include <stdio.h>

typedef enum{
  lparen,rparen,plus,minus,mul,mod,divide,operand,eos
}token;

int stack[100];
int top=-1;

char string[100];

void push(int item){
  stack[++top]=item;
}

int pop(){
  return stack[top--];
}

token gettoken(char *str, int *n){
  *str= string[(*n)++];
  switch(*str){
    case '+':{return plus;}
    case '-':return minus;
    case '*':return mul;
    case '/':return divide;
    case '%':return mod;
    case ')':return rparen;
    case '(':return lparen;
    case '\0':return eos;
    default : return operand;
  }
}

int eval(){
  int n=0;
  char str;
  token sym=gettoken(&str,&n);
  while(sym!=eos){
    if(sym==operand){
      push(str -'0');
    }
    else{
      int op2=pop();
      int op1=pop();
      switch(sym){
        case plus:{push(op1+op2); break;}
        case minus:{push(op1-op2); break;}
        case mul:{push(op1*op2); break;}
        case divide:{push(op1/op2); break;}
        case mod:{push(op1%op2); break;}
        default: break;
      }
    }
    sym=gettoken(&str,&n);
  }
  return pop();
}

int main(){
  printf("Enter the postfix expression:-\n");
  scanf("%s",string);
  int ans=eval();
  printf("Answer after evaluation is :- %d\n",ans);
  return 0;
}
