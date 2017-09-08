#include <stdio.h>
#include <stdlib.h>
#define OK 1

typedef int Status;
typedef struct {
  char *data;
  int  len;
}String;

Status strInit(String *T){
  T->data = NULL;
  T->len = 0;
  return OK;
}

Status strAssign(String *T,char *str){
  if(T->data)free(T->data);

  int i,j;
  i=j=0;
  while(str[i]!='\0')i++;
  
  if(!i){T->data=NULL;T->len=0;}   //empty
  else{ 			   //copy
    T->data = (char*)malloc(i*sizeof(char)); 
    for(j=0;j<i;j++)
      T->data[j]=str[j];
    T->len = i;
  }
  return OK;
}

int getNext(String S,int *next){
  next[0] = -1;
  int j,k;
  j=0;
  k=-1;
  while(j<S.len-1){
    if(k==-1 || S.data[k]==S.data[j]){
      j++;
      k++;
      if(S.data[j]!=S.data[k])
        next[j] = k;
      else
        next[j] = next[k];
    }else{
      k=next[k];
    }
  }
  return 0;
}

int getCount(String T,String S){
  int count = 0;
  int i=-1, j=-1, k;
  int next[S.len];
  getNext(S,next);
  while(i<T.len){
    if(j==-1 || T.data[i] == S.data[j]){
      ++i;
      ++j;
      if(j==S.len){count++;j=-1;--i;}
    }else{
      j=next[j];
    }
  }
  return count;
}

int main(){
  String S1,S2;
  strInit(&S1);
  strInit(&S2);
  char a[100];
  char b[100];
  
  scanf("%s",a);
  scanf("%s",b);

  strAssign(&S1,a);
  strAssign(&S2,b);

  int c = getCount(S1,S2);
  printf("total :%d string has been in \n",c);
  return 0;
}
