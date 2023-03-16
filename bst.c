#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  struct node* left;
  int data;
  struct node* right;
}node;

node* search(node* root, int key){
  if(!root) return NULL;
  if(key == root->data) return root;
  if(key < root->data) return search(root->left,key);
  return search(root->right,key);
}

node* insert(node* root, int key){
  if(root==NULL){
    root=(node*)malloc(sizeof(node));
    root->data=key;
    return root;
  }
  if(root->data > key){
    root->left=insert(root->left,key);
  }
  else if(root->data<key){
    root->right=insert(root->right,key);
  }
  return root;
}

void inorder(node* root){
  if(root==NULL) return;
  inorder(root->left);
  printf("%d\t",root->data);
  inorder(root->right);
}
void preorder(node* root){
  if(root==NULL) return;
  preorder(root->left);
  preorder(root->right);
  printf("%d\t",root->data);
  
}

void postorder(node* root){
  if(root==NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d\t",root->data);
  }

int main(){

  node* root = NULL;
  while(1){
    printf("1.Enter node\n2.display\n3.search key\n4.exit\n");
    int ch;
    scanf("%d",&ch);
    if(ch==4) break;
    else if(ch==3){
      int k;
      printf("Enter the key:-\n");
      scanf("%d",&k);
      node* r = search(root,k);
      if(r!=NULL)printf("Found the key\n");
      else printf("Not found\n");
    }
    else if(ch==2){
      printf("Inorder traversal:-\n");
      inorder(root);
      printf("\n");
      printf("Preorder traversal:-\n");
      preorder(root);
      printf("\n");
      printf("Postorder traversal:-\n");
      postorder(root);
      printf("\n");
    }

    else if(ch==1){
      printf("Enter the key to insert in BST:-\n");
      int k;
      scanf("%d",&k);
      root = insert(root, k);
    }
    
  }
  return 0;
}
