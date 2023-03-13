#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *left;
  struct node *right;
}node;

node* createTree(){
  node* root;
  int d;
  printf("Enter the node data(-1 if empty):-\n");
  scanf("%d",&d);

  if(d==-1) return NULL;
  
  root=(node*)malloc(sizeof(node));
  root->data=d;

  printf("Enter the left child:-\n");
  root->left=createTree();

  printf("Enter the right child:-\n");
  root->right=createTree();

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
  node* root= createTree();
  printf("Inorder Traversal of created tree:-\n");
  inorder(root);
  printf("\n");
  printf("Preorder Traversal of created tree:-\n");
  preorder(root);
  printf("\n");
  printf("Postorder Traversal of created tree:-\n");
  postorder(root);
  printf("\n");
  return 0;
}
