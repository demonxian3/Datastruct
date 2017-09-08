#include <stdio.h>
#include <stdlib.h>

#define OK 1

typedef int Status;
typedef struct {
  char *data;
  int  len;
}String;

Status initString(String *T){
  T->data = NULL;
  T->len  = 0;
  return OK;
}

Status strAssign(String *T,char *str){
  if(T->data)free(T->data);
  
  int i=0,j;
  while(str[i]!='\0')i++;
  if(!i){T->data=NULL;T->len=0;}
  else{
    T->data=(char*)malloc(i*sizeof(char));
    for(j=0;j<i;j++){
      T->data[j]=str[j];
    }
    T->data[j]='\0';
    T->len=i;
  }
  return OK;
}

int Index_SimpleMode(String T,String S,int pos){
  if( S.len == 0 || T.len<S.len )return -1;
  
  int i=pos, j=0;
  while(i<T.len && j<S.len){
    if(T.data[i] == S.data[j]){i++,j++;}
    else{i=i-j+1;j=0;}
  }
  if(j==S.len)return i-S.len;
  else return -1;
}

int main(){
  int pos,idx;
  String S1,S2;
  initString(&S1);
  initString(&S2);

  char *main = (char*)malloc(100*sizeof(char));
  char *sub  = (char*)malloc(100*sizeof(char));


  printf("enter string:");
  scanf("%s",main);

  printf("enter string:");
  scanf("%s",sub);

  printf("enter index:");
  scanf("%d",&idx);

  strAssign(&S1,main);
  strAssign(&S2,sub);

  pos = Index_SimpleMode(S1,S2,idx);
  
  if(pos<0)printf("doesn't match\n");
  else printf("find it:%d\n",pos);

  return OK;
}
