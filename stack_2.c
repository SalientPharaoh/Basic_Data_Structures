#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* link;
}node;

void push(node* head,int num){
  node* temp;
  temp=(node*)malloc(sizeof(node));
  temp->data=num;
  temp->link=NULL;
  while(head->link!=NULL){
    head=head->link;
  }
  head->link=temp;
}

int pop(node* head){
  if(head->link==NULL){
    printf("Linked List underflow!\n");
    exit(0);
  }
  while(head->link->link!=NULL){
    head=head->link;
  }
  int temp=head->link->data;
  free(head->link);
  head->link=NULL;
  return temp;
}

void show(node* temp){
  node* head=temp->link;
  while(head->link!=NULL){
    printf("%d->",head->data);
    head=head->link;
  }
  printf("%d",head->data);
  printf("\n");
}

int main(){
  node* head;
  head=(node*)malloc(sizeof(node));
  int ch=0;
  while(ch!=4){
    printf("1.Push\n2.Pop\n3.Display\n4.exit\n");
    scanf("%d",&ch);
    int add;
    if(ch==1){
      printf("enter the element:-\n");
      scanf("%d",&add);
      push(head,add);
    }
    else if(ch==2){
      printf("%d removed\n",pop(head));
    }
    else if(ch==3){
      show(head);
    }
  }
  free(head);
  return 0;
}
