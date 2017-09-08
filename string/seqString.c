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

//***********************//
//    basic operation    //
//***********************//

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

Status strConcat(String *T,String S1,String S2){
  if(T->data)free(T->data);
  
  int j;
  int i = S1.len + S2.len;
  T->data = (char*)malloc(i*sizeof(char));
  
  for(j=0;j<S1.len;j++)
    T->data[j]=S1.data[j];
  
  for(j=S1.len;j<i;j++)
    T->data[j]=S2.data[j-S1.len];

  T->len = i;

  return OK;
}

Status subString(String *Sub, String S,int pos,int len){
  if(pos<0 || pos>=S.len || len<0 || pos+len>S.len){
    printf("In Function:subString error\n");
    exit(1);
  }

  int i;
  if(Sub->data)free(Sub->data);
  
  if(!len){Sub->data=NULL;Sub->len=0;}
  else{
    Sub->data = (char*)malloc(len * sizeof(char));
    Sub->len = len;

    for(i=0;len>0;len--,i++)
      Sub->data[i] = S.data[pos++];
    Sub->data[Sub->len]='\0';
  }
  return OK;
}

Status strCopy(String *T, String S,int i){
  if(i<0 || i>S.len){
    printf("In Function:strCopy error\n");
    exit(2);
  }
  
  int j;
  if(T->data)free(T->data);
  if(!i){T->data=NULL;T->len=0;}
  else{
    T->data = (char*)malloc(i*sizeof(char));
    for(j=0;j<i;j++)
      T->data[j]=S.data[j];
    T->len = i;
  }
}

int strCompare(String T,String S){
  //compare length
  if(T.len != S.len)return T.len-S.len;
  //compare ASCII code
  else{
    int i;
    for(i=0;i<T.len;i++)
      if(T.data[i]!=S.data[i])
        return T.data[i]-S.data[i];
  }
  return 0;
}

//***************************//
//    composite operation    //
//***************************//

Status strInsert(String *T,int pos,String S){
  int tail_len = T->len-pos;
  int head_len = pos;

  //head_string
  String sub1;
  strInit(&sub1);
  strCopy(&sub1,*T,pos);

  //tail_string
  String sub2;
  strInit(&sub2);
  subString(&sub2,*T,pos,tail_len);
  
  //concat_string
  String tmp;
  strInit(&tmp);
  strConcat(&tmp,sub1,S);
  strConcat(T,tmp,sub2);
  
  return OK;
}

Status strDelete(String *T,int pos,int len){
  if(pos<0 || pos>=T->len || len<0 || len+pos>T->len){
    printf("In Function:strDelete error");
    exit(1);
  }

  int i=pos;
  while(T->data[i]){
    T->data[i] = T->data[i+len];  //overlap
    i++;
  }
  T->len-=len;
  return 0;
}

int main(){
  String T,S1,S2,tmp,a,b;
  strInit(&T);
  strInit(&a);
  strInit(&b);
  strInit(&S1);
  strInit(&S2);
  strInit(&tmp);
  
  //concat
  strAssign(&S1,"hello ");
  strAssign(&S2,"world");
  strConcat(&T,S1,S2);
  printf("%s\n",T.data);     //T is "hello world"

  //subString
  int pos = 3;
  int len = 4;
  subString(&S1,T,pos,len);
  printf("%s\n",S1.data);    //S1 is "lo w"
  
  //copy
  strCopy(&S1,T,7);
  printf("%s\n",S1);         //S1 is "hello w"
  
  //compare
  int res;
  strAssign(&a,"hello worldaCc");
  strAssign(&b,"hello worldacc");
  if(!(res = strCompare(a,b)))
    printf("two sentence is eual\n");
  else{
    if(res>0)printf("res is %d\n",res);
    else printf("res is %d\n",res);
  }

  //insert
  strAssign(&tmp,"III");
  strInsert(&T,6,tmp);
  printf("len=%d:\"%s\"\n",T.len,T.data);  //T is "hello IIIworld"

  //delete
  strDelete(&T,6,3);
  printf("len=%d:\"%s\"\n",T.len,T.data);  ///T is "hello world"
  return 0;
}
