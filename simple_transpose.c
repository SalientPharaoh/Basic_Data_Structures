#include <stdio.h>

typedef struct{
  int row;
  int col;
  int val;
}sparse;

sparse matrix[100];
int avail=1;
sparse transmat[100];
int col;
//function to create a sparse matrix from a column 2D array
void create(int arr[][col],int r, int c){
  int count=0;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(arr[i][j]!=0){
        matrix[avail].row=i;
        matrix[avail].col=j;
        matrix[avail++].val=arr[i][j];
        count++;
      }
    }
  }
  matrix[0].row=r;
  matrix[0].col=c;
  matrix[0].val=count;
}

//function to transpose the matrix
void transpose(sparse a[], sparse b[]){
  b[0].row=a[0].col;
  b[0].col=a[0].row;
  b[0].val=a[0].val;
  if(a[0].val>0){
    int currentb=1;
    for(int i=0;i<a[0].col;i++){
      for(int j=1;j<=a[0].val;j++){
        if(a[j].col==i){
          b[currentb].row=a[j].col;
          b[currentb].col=a[j].row;
          b[currentb++].val=a[j].val;
        }
      }
    }
  }
}

//function to display sparse matrix
void display_(sparse m[]){
  int n = m[0].val;
  for(int i=1;i<=n;i++){
    printf("row:-%d\n", m[i].row);
    printf("column-%d\n",m[i].col);
    printf("value:-%d\n",m[i].val);
  }
}

int main(){
  int row;
  printf("Enter the rows:-\n");
  scanf("%d",&row);
  printf("Enter the column:0\n");
  scanf("%d",&col);
  int arr[row][col];
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      printf("Enter %d row %d column element:-\n",i,j);
      scanf("%d",&arr[i][j]);
    }
  }
  create(arr,row,col);
  transpose(matrix,transmat);
  //display_(matrix);
  display_(transmat); //displaying the transpose sparse matrix
  
  return 0;
}
