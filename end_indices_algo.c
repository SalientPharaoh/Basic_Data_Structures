#include <stdio.h>
#include <string.h>

int endindices(char *string, char *pat){
  int lens=strlen(string);
  int lenp=strlen(pat);
  int start=0;
  int count=0;
  for(int i=lenp-1;i<lens;i++){
    if(pat[lenp-1]==string[i]){
      for(int i=start,j=0;i<start+lenp-1;i++,j++){
        if(string[i]!=pat[j]){
          count=0;
          break;
        }
        else count++;
      }
      if(count==lenp-1) return start;
    }
    start++;
  }
  return -1;
}

int main(){

  char str[100];
  char pat[100];
  printf("Enter the string:-\n");
  scanf("%s",str);
  printf("Enter the pattern:-\n");
  scanf("%s",pat);
  int index=endindices(str, pat);
  if(index==-1) printf("Pattern Not found in String!\n");
  else printf("Pattern starts at :- %d index\n",index);
  
  return 0;
}
