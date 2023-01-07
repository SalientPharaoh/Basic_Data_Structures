#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* link;
}node;

struct node* last=NULL;

void insertfront(int data){
  node* temp;
  temp=(node*)malloc(sizeof(node));
  if (last == NULL) {
    temp->data = data;
    temp->link = temp;
    last = temp;
  }
  else {
    temp->data = data;
    temp->link = last->link;
    last->link = temp;
    }
}


void insertafter(int data){
  int value;
  struct node *temp, *n;
  printf("Enter number after which you want to enter number:\n");
  scanf("%d", &value);
  temp = last->link;
  do {
        if (temp->data == value) {
            n = (struct node*)malloc(sizeof(struct node));
            n->data = data;
            n->link = temp->link;
            temp->link = n;
          
            if (temp == last)
                last = n;
            break;
        }
        else
            temp = temp->link;
    } while (temp != last->link);
}

void deleteAtIndex(){
    int pos, i = 1;
    struct node *temp, *position;
    temp = last->link;

    if (last == NULL)
        printf("List is empty.\n");

    else {
        printf("Enter index :-\n");
        scanf("%d", &pos);
        while (i <= pos - 1) {
            temp = temp->link;
            i++;
        }
        position = temp->link;
        temp->link = position->link;
        free(position);
    }
}
 
void viewList(){
    
    if (last == NULL)
        printf("List is empty\n");

    else {
        struct node* temp;
        temp = last->link;
        do {
            printf("Data = %d\n", temp->data);
            temp = temp->link;
        } while (temp != last->link);
    }
  }

int main(){
  while(1){
    printf("1.Insert at begining:-\n2.Insert after an element\n3.Delete at an index\n4.view list\n5.Exit\n");
    int ch;
    int val;
    scanf("%d",&ch);
    if(ch==1){
      printf("Enter value:-\n");
      scanf("%d",&val);
      insertfront(val);
    }
    else if(ch==2){
      printf("Enter value:-\n");
      scanf("%d",&val);
      insertafter(val);
    }
    else if(ch==3){
      deleteAtIndex();
    }
    else if(ch==4){
      viewList();
    }
    else break;
  }
  return 0;
}
