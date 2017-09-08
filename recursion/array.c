#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
  return;
}

void echo(int a,int b,int c){
  printf("%d%d%d \n",a,b,c);
  return;
}

void change(int a,int b,int c){
  echo(a,b,c);
  swap(&b,&c);
  echo(a,b,c);
  swap(&a,&c);
  if(a==1 && b==2)return;
  change(a,b,c);
}

int main(){
  change(1,2,3);
  return 0;
}
