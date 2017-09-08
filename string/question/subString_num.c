#include <stdio.h>

int ADD(int num){
  if(num==1)return 1;
  else return num + ADD(num-1);
}

int main(){
  char str[256];
  printf("enter a string:");
  scanf("%s",str);

  int len=0;
  while(str[len]!='\0')len++;

  int res = ADD(len) + 1; 
  printf("common num is %d\n",res);
  return 0;
}
