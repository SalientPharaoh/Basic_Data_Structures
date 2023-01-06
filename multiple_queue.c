#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int val;
}element;

typedef struct node{
  element data;
  struct node* link;
}node;

node* front[50];
node* rear[50];

void enqueue(element item, int i){
  node* temp;
  temp=(node*)malloc(sizeof(node));
  temp->data=item;
  if(front[i]){
    rear[i]->link=temp;
  }
  else{
    front[i]=temp;
  }
  rear[i]=temp;
}

element dequeue(int i){
  node* temp;
  temp=front[i];
  element item;
  if(front[i]){
    item=front[i]->data;
    front[i]=front[i]->link;
  }
  else{
    item.val=-1;
  }
  free(temp);
  return item;
}

void show(int i){
  node* temp;
  temp=front[i];
  for(;temp;temp=temp->link){
    printf("%d\t",temp->data.val);
  }
  printf("\n");
}

int main(){
  int ch=0;
  int i;
  while(ch!=4){
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    scanf("%d",&ch);
    element add;
    if(ch==1){
      printf("Enter the stack number:-\n");
      scanf("%d",&i);
      printf("enter the element:-\n");
      scanf("%d",&add.val);
      enqueue(add,i);
    }
    else if(ch==2){
      printf("Enter the stack number:-\n");
      scanf("%d",&i);
      printf("%d removed\n",dequeue(i).val);
    }
    else if(ch==3){
      printf("Enter the stack number:-\n");
      scanf("%d",&i);
      show(i);
    }
  }
  return 0;
}
