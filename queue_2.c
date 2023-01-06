#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* link;
}node;

node* front;
node* rear;

void enqueue(int num){
  node* temp;
  temp=(node*)malloc(sizeof(node));
  temp->data=num;
  if(front){
    rear->link=temp;
  }
  else{
    front=temp;
  }
  rear=temp;
}

int dequeue(){
  node* temp;
  temp=front;
  int item=-1;
  if(front){
    item=front->data;
    front=front->link;
  }
  free(temp);
  return item;
}

void show(){
  node* temp=front;
  for(;temp;temp=temp->link){
    printf("%d\t",temp->data);
  }
  printf("\n");
}

int main(){
  int ch=0;
  int i;
  while(ch!=4){
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    scanf("%d",&ch);
    int add;
    if(ch==1){
      printf("enter the element:-\n");
      scanf("%d",&add);
      enqueue(add);
    }
    else if(ch==2){
      printf("%d removed\n",dequeue());
    }
    else if(ch==3){
      show();
    }
  }
  return 0;
}
