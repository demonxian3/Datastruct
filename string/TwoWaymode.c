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

int twoWayMode(String T,String S){
  if(S.len > T.len)return -1;
  int i=0, j=0, m=S.len-1, n=m/2;
  int count = 0;
  while(i<T.len && j<S.len){
    if(T.data[i]==S.data[j] && T.data[(i-j)+(m-j)]==S.data[m-j]){
      ++i;
      ++j;
      if(j>n){  //improve;
        printf("count is %d\n",++count);
        return i-j;
      }
    }else{ 
      i=i-j+1;  //rollback
      j=0;
    }
    count++;
  }
  printf("calc: %d\n",count);
  return -1;
}

int main(){
  
  char str1[] = "ABCABd ABdsadA ABCAdsaABddsadasdaABCDsadCaDdsaABCDEFGH";
  char str2[] = "ABCDEFGH";
  String S1,S2;
  initString(&S1);
  initString(&S2);
  strAssign(&S1,str1);
  strAssign(&S2,str2);
  
  int res = twoWayMode(S1,S2);
  if(res>=0)printf("find it: %d\n",res);
  else
    printf("doesn't match\n");
  return OK;
}
