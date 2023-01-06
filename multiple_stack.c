#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int val;
}element;

typedef struct node{
  element data;
  struct node* link;
}node;

node* top[50];

void push(element item, int i){
  node* temp;
  temp=(node*)malloc(sizeof(node));
  temp->data=item;
  temp->link=top[i];
  top[i]=temp;
}

element pop(int i){
  node* temp=top[i];
  element item;
  if(temp==NULL){
    item.val=-1;
    return item;
  }
  else{
    top[i]=top[i]->link;
    item=temp->data;
    free(temp);
    return item;
  }
}

void show(int i){
  node* temp=top[i];
  for(;temp;temp=temp->link){
    printf("%d ",(temp->data).val);
  }
  printf("\n");
}

int main(){
  int z=50;
  for(int i=0;i<z;i++){
    top[z]=NULL;
  }
  int ch=0;
  int i;
  while(ch!=4){
    printf("1.Push\n2.Pop\n3.Display\n4.exit\n");
    scanf("%d",&ch);
    element add;
    if(ch==1){
      printf("Enter the stack number:-\n");
      scanf("%d",&i);
      printf("enter the element:-\n");
      scanf("%d",&add.val);
      push(add,i);
    }
    else if(ch==2){
      printf("Enter the stack number:-\n");
      scanf("%d",&i);
      printf("%d removed\n",pop(i).val);
    }
    else if(ch==3){
      printf("Enter the stack number:-\n");
      scanf("%d",&i);
      show(i);
    }
  }
  return 0;
}
