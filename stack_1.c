#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int key;
}element;

element *stack;
int top=-1;
int capacity=10;

void stackfull(element *stk){
  stk=realloc(stk,2*capacity*sizeof(element));
  capacity*=2;
}

void push(element item){
  if(top==capacity) stackfull(stack);
  stack[++top]=item;
}

int pop(){
  if(top==-1){
    printf("Stack empty!\n");
    exit(0);
  }
  return stack[top--].key;
}

void display(){
  int tos=top;
  while(tos!=-1){
    printf("%d\n",stack[tos--].key);
  }
}

int main(){
  stack=(element *)malloc(10*sizeof(element));
  int ch=0;
  while(ch!=4){
    printf("1.Push\n2.Pop\n3.Display\n4.exit\n");
    scanf("%d",&ch);
    element add;
    if(ch==1){
      printf("enter the element:-\n");
      scanf("%d",&add.key);
      push(add);
    }
    else if(ch==2){
      printf("%d removed\n",pop());
    }
    else if(ch==3){
      display();
    }
  }
  free(stack);
  return 0;
}
