#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
}node;

void insertfirst(node** list){
  int num;
  printf("Enter the data to be inserted:-\n");
  scanf("%d",&num);
  node* temp;
  temp=(node*)malloc(sizeof(node));
  if(!*list){
    temp->next=NULL;
    *list=temp;
  }
  else{
    temp->data=num;
    temp->next=(*list)->next;
    (*list)->next=temp;
  }
}

void delfirst(node** list){
  if(*list){
    printf("Deleted Node:- %d\n",(*list)->data);
    *list=(*list)->next;
  }
  else{
    printf("List is already Empty!\n");
  }
}

void show(node* temp){
  node* list=temp->next;
  for(;list;list=list->next){
    printf("%d->",list->data);
  }
  printf("\n");
}


int main(){
  node *list;
  list=(node*)malloc(sizeof(node));
  int ch=0;
  while(ch!=4){
    printf("1.Insert node\n2.Delete node\n3.Show Linked List\n4.Terminate\n");
    scanf("%d",&ch);
    if(ch==1) insertfirst(&list);
    else if(ch==2) delfirst(&(list->next));
    else if(ch==3) show(list);
    else break;
  }
  return 0;
}
