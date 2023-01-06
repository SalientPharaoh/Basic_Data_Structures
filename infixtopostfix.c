#include <stdio.h>

int icp[]={20,19,12,12,13,13,13,0};
int isp[]={0,19,12,12,13,13,13,0};

typedef enum{
  lparen,rparen,plus,minus,mul,mod,divide,operand,eos
}token;

char stack[100];
int top=-1;

char string[100];

void push(char item){
  stack[++top]=item;
}

char pop(){
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

token equivalent(char s){
  switch(s){
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

void convert(){
  int p=0;
  char str;
  int n=0;
  while(string[p++]!='\0'){
    token symbol=gettoken(&str, &n);
    if(symbol==operand){
      printf("%c ",str);
    }
    else if(symbol==rparen){
      char a=pop();
      while(a!='('){
        printf("%c ",a);
      }
      pop();
    }
    else{
      while((isp[equivalent(stack[top])] >= icp[symbol])){
        printf("%c ",pop());
      }
      push(str);
    }
  }
  char res;
  while((res=pop())!='\0'){
    printf("%c ",res);
  }
}

int main(){
  stack[0]='\0';
  printf("Enter the expression:-\n");
  scanf("%s",string);
  convert();
  return 0;
}
