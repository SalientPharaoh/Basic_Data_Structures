#include <stdio.h>
#include <stdlib.h>

void insert(int val, int *n, int arr[]){
  (*n)+=1;
  arr[*n]=val;
  int i=*n;
  while(i>1){
    int parent=i/2;
    if(arr[parent]<arr[i]){
      int temp=arr[i];
      arr[i]=arr[parent];
      arr[parent]=temp;
      i=parent;
    }
    else{
      return;
    }
  }
}

void del(int arr[], int *n){
  if(*n==0){
    printf("Empty Maximum Heap!\n");
    return;
  }
  arr[1]=arr[*n];
  (*n)-=1;
  int i =1;
  while(i<*n){
    int left=arr[2*i];
    int right=arr[2*i+1];
    int larger = (left>right)? 2*i : 2*i+1;
    if(arr[i]<arr[larger]){
      int temp=arr[i];
      arr[i]=arr[larger];
      arr[larger]=temp;
      i=larger;
    }
    else return;
  }
}

int main(){
  int arr[100];
  int n=0;
  while(1){
    printf("1.Add node\n2.Delete node\n3.Display\n4.Exit\n");
    int ch;
    scanf("%d",&ch);
    if(ch==4) break;
    else if(ch==3){
      for(int i=1;i<=n;i++)printf("%d\t",arr[i]);
      printf("\n");
    }
    else if(ch==2){
      del(arr,&n);
    }
    else if(ch==1){
      int v;
      printf("Enter the value to add into the heap:\n");
      scanf("%d",&v);
      insert(v, &n, arr);
    }
  }
  

  return 0;
}
