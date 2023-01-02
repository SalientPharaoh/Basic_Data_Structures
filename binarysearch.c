#include <stdio.h>

int search(int arr[],int key,int start, int end){
  if(start>end) return -1;
  else{
    int mid= start + (end-start)/2;
    if(arr[mid]==key) return mid;
    else if(arr[mid]>key) return search(arr,key,start,mid-1);
    else return search(arr,key,mid+1,end);
    }
}

int main(){
  int n,key;
  printf("Enter the size of array:-\n");
  scanf("%d",&n);
  int arr[n];
  printf("\nEnter the elements of array:-\n");
  for(int i=0;i<n;i++) scanf("%d",&arr[i]);
  for(int i=0;i<n;i++) printf("%d\t",arr[i]);
  printf("\nEnter the key to search\n");
  scanf("%d",&key);
  int index=search(arr,key,0,n-1);
  if(index==-1) printf("Key is not found in the array!\n");
  else printf("The key found at index :- %d\n",index);
  return 0;
  }
