//infix to postfix
#include <stdio.h>

int icp[]={20,19,12,12,13,13,13,0};
int isp[]={0,19,12,12,13,13,13,0};

typedef enum{
  lparen,rparen,plus,minus,mul,divide,mod,eos,operand
}precedence;

char stack[100];
int top=0;
char s[100];

void push(char item){
  stack[++top]=item;
}

char pop() {
  return stack[top--];
}

precedence gettoken(char *symbol, int* n){
  *symbol=s[(*n)++];
  switch(*symbol){
    case '+': return plus;
    case '-':return minus;
    case '*':return mul;
    case '/':return divide;
    case '%':return mod;
    case '\0':return eos;
    case ')':return rparen;
    case'(': return lparen;
    default : return operand;
  }
}

precedence equiv(char s){
  switch(s){
    case '+': return plus;
    case '-':return minus;
    case '*':return mul;
    case '/':return divide;
    case '%':return mod;
    case '\0':return eos;
    case ')':return rparen;
    case'(': return lparen;
    default : return operand;
  }
}

void convert(){
  int n=0;
  char symbol;
  precedence token=gettoken(&symbol,&n);
  while(token!=eos){
    if(token==operand) printf("%c ",symbol);
    else if(token==rparen){
      char sym;
      while((stack[top])!='('){
        printf("%c",pop());
      }
      pop();
    }
    else{
      while(isp[equiv(stack[top])]>=icp[token]) printf("%c",pop());
      push(symbol);
    }
    token=gettoken(&symbol,&n);
  }
  while((symbol=pop())!='\0'){
    printf("%c",symbol);
  }
}

int main(){
  stack[0]='\0';
  printf("Enter the expression:-\n");
  scanf("%s",s);
  convert();
  return 0;
}
