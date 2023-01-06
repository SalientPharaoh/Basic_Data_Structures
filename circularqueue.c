#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int key;
}element;

element *queue;
int capacity=1;
int front=0,rear=0;

void copy(element* start,element* end,element *newqueue){
  element* i;
  element *j;
  i=newqueue;
  j=start;
  for(;j<end;i++,j++){
    *i=*j;
  }
}

void queuefull(){
  element *newqueue;
  newqueue=(element *)malloc(2*capacity*sizeof(element));
  int start=(front+1)%capacity;
  if(start<2){
    copy(queue+start,queue+start+capacity-1,newqueue);
  }
  else{
    copy(queue+start,queue+capacity,newqueue);
    copy(queue,queue+rear+1,newqueue+capacity-start);
  }
  front=2*capacity-1;
  rear=capacity-1;
  capacity*=2;
  free(queue);
  queue=newqueue;
}

void enqueue(element item){
  rear=(rear+1)%capacity;
  if(front==rear) queuefull();
  (queue[rear])=item;
}

int dequeue(){
  if(front==rear){
    printf("Queue is empty!\n");
    exit(0);
  }
  front=(front+1)%capacity;
  return queue[front].key;
}

void display(){
  int i;
  for(i=(front+1)%capacity;i!=rear;i=(i+1)%capacity){
    printf("%d\n",queue[i].key);
  }
  printf("%d\n",queue[i].key);
}

int main(){
  queue=(element *)malloc(capacity*sizeof(element));
  while(1){
    printf("1.Enqueue\n2.dequeue\n3.display\n4.exit\n");
    int ch;
    scanf("%d",&ch);
    if(ch==1){
      element item;
      printf("Enter element to add:-\n");
      scanf("%d",&item.key);
      enqueue(item);
    }
    else if(ch==2){
      printf("%d dequeued\n",dequeue());
    }
    else if(ch==3) display();
    else break;
  }
  
  return 0;
}
