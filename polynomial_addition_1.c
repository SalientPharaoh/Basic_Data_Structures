#include <stdio.h>

typedef struct{
  int expon;
  int coeff;
}polynomial;

polynomial p[100]; //Array of polynomial elements (max size 100)
int avail=0; //Tracking the index at which new term should be inserted

void addterm(int c, int e){
  p[avail].coeff=c;
  p[avail++].expon=e;
}

void padd(int sa,int ea,int sb,int eb,int *sd,int *ed){
  while(sa<=ea && sb<=eb){
    if(p[sa].expon==p[sb].expon){
      if(p[sa].coeff+p[sb].coeff){
        addterm(p[sa].coeff+p[sb].coeff,p[sa].expon);
      }
      sa++;
      sb++;
    }
    else if(p[sa].expon<p[sb].expon){
      addterm(p[sa].coeff,p[sa].expon);
      sa++;
    }
    else{
      addterm(p[sb].coeff,p[sb].expon);
      sb++;
    }
  }
  for(int i=sa;i<=ea;i++){
    addterm(p[i].coeff,p[i].expon);
  }
  for(int i=sb;i<=eb;i++){
    addterm(p[i].coeff,p[i].expon);
  }
  *ed=avail-1;
}
int main(){
  int a,b;
  printf("Enter size of polynomial A:-\n");
  scanf("%d",&a);
  printf("Enter the size of polynomial B:-\n");
  scanf("%d",&b);
  printf("Polynomial A:-\n");
  for(int i=0;i<a;i++){
    int c,e;
    printf("coefficient:-\n");
    scanf("%d",&c);
    printf("Exponent:-\n");
    scanf("%d",&e);
    addterm(c,e);
  }
  printf("Polynomial B:-\n");
  for(int i=0;i<b;i++){
    int c,e;
    printf("coefficient:-\n");
    scanf("%d",&c);
    printf("Exponent:-\n");
    scanf("%d",&e);
    addterm(c,e);
  }
  int sd,ed;
  padd(0,a-1,a,a+b-1,&sd,&ed);
  printf("Added polynomial is :-\n");
  for(int i=a+b;i<=ed-1;i++){
    printf(" %d x^%d +",p[i].coeff,p[i].expon);
  }
  printf(" %d x^%d ",p[ed].coeff,p[ed].expon);
  return 0;
  }
