#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int key;
}element;

element *queue;
int front=-1,rear=-1;
int capacity=10;

void queuefull(element *q){
  q=realloc(q,2*capacity*sizeof(element));
  capacity*=2;
}

void enqueue(element item){
  if(rear==capacity) queuefull(queue);
  queue[++rear]=item;
}

int dequeue(){
  if(front>rear){
    printf("Queue is Empty\n");
    exit(0);
  }
  return queue[++front].key;
}

void display(){
  int r=rear;
  int f=front;
  for(int i=front+1;i<=rear;i++){
    printf("%d\n",queue[i].key);
  }
}

int main(){
  queue=(element *)malloc(10*sizeof(element));
  int ch=0;
  while(ch!=4){
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.exit\n");
    scanf("%d",&ch);
    element add;
    if(ch==1){
      printf("enter the element:-\n");
      scanf("%d",&add.key);
      enqueue(add);
    }
    else if(ch==2){
      printf("%d removed\n",dequeue());
    }
    else if(ch==3){
      display();
    }
  }
  free(queue);
  return 0;
}
