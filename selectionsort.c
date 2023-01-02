#include <stdio.h>
#define swap(x,y,t)((t)= (x), (x)= (y), (y)= (t))

void selection(int list[],int n){
  int temp;
  for(int i=0;i<n-1;i++){
    int min=i;
    for(int j=i+1;j<n;j++){
      if(list[j]<list[min]) min=j;
    }
    swap(list[i],list[min],temp);
  }
}

int main(void) {
  int n;
  printf("Enter the size of array:-\n");
  scanf("%d",&n);
  int arr[n];
  printf("\nEnter the elements of array:-\n");
  for(int i=0;i<n;i++) scanf("%d",&arr[i]);
  for(int i=0;i<n;i++) printf("%d\t",arr[i]);
  selection(arr,n);
  printf("\nAfter the sorting array is:-\n");
  for(int i=0;i<n;i++) printf("%d\t",arr[i]);
  return 0;
}
