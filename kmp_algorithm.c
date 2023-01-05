#include <stdio.h>
#include <string.h>

int failure[100];

void fail(char *pat){
  failure[0]=1;
  int n=strlen(pat);
  int i;
  for(int j=1;j<n;j++){
    i=failure[j-1];
    while(pat[j]!=pat[i+1] && i>=0){
      i=failure[i];
    }
    if(pat[j]==pat[i+1]) failure[j]=i+1;
    else failure[j]=-1;
  }
}

int pmatch(char *string, char *pat){
  int i=0,j=0;
  int lens=strlen(string);
  int lenp=strlen(pat);
  while(i<lens && j<lenp){
    if(string[i]==pat[j]){
      i++;
      j++;
    }
    else if(j==0){
      i++;
    }
    else j=failure[j-1]+1;
  }
  return (j==lenp? i-lenp:-1);
}

int main(){
  char str[100];
  char pat[100];
  printf("Enter the string:-\n");
  scanf("%s",str);
  printf("Enter the pattern:-\n");
  scanf("%s",pat);
  fail(pat);
  int index=pmatch(str, pat);
  if(index==-1) printf("Pattern Not found in String!\n");
  else printf("Pattern starts at :- %d index\n",index);
  
  return 0;
}
