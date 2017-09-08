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

void getNext(String S,int *next){
  next[0] = -1;
  int k=-1, j=0;
  while(j<S.len-1){
    if(k==-1 || S.data[j]==S.data[k]){
      ++k;
      ++j;
      next[j]=k;
    }else{
      k=next[k];
    }
  }

  int i;
}

void newNext(String S,int *next){
  next[0] = -1;
  int k=-1, j=0;
  while(j<S.len-1){
    if(k==-1 || S.data[j]==S.data[k]){
      ++k;
      ++j;
      if(S.data[j]!=S.data[k])
        next[j] = k;
      else
        next[j] = next[k];
    }
    else{
      k=next[k];
    }
  }
}

int KMPSearch(String T,String S){
  int i=0, j=0, next[S.len], c=0;
  //getNext(S,next);
  newNext(S,next);

  while(i<T.len && j<S.len){
    if(j==-1 || T.data[i]==S.data[j]){i++;j++;}
    else{
      j=next[j];
    }
    c++;
  }
  printf("[TEST]:newNext: %d\n",c);
  if(j==S.len)return i-j;
  else return -1;
}

int main(){
  
  char str1[] = "ABCABd ABdsadA ABCAdsaABddsadasdaABCDsadCaDdsaABCDEFGH";
  char str2[] = "ABCDEFGH";
  String S1,S2;
  initString(&S1);
  initString(&S2);
  strAssign(&S1,str1);
  strAssign(&S2,str2);
  int res = KMPSearch(S1,S2);
  printf("%s\n%s\n",str1,str2);
  if(res>0)printf("find it :%d\n",res);
  else printf("doesn't match\n");
  return OK;
}
