#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FLASE 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef struct{
  ElemType * elem;
  int len; 
} Sqlist;

Status initList(Sqlist *L){
  L->elem = (ElemType*)malloc(SIZE * sizeof(ElemType*));
  if(!L->elem){
   printf("overflow!\n");
   return OVERFLOW;
  }
  L->len = 0;
  return OK;
}

Status insertList(Sqlist *L, int index,ElemType e){

  index--;	//because index begin in 1;

  //overflow
  if( index>L->len || index<0 ||L->len>=SIZE) {
   printf("overflow!\n");
   return OVERFLOW;
  }

  //insert last one
  if( index == L->len){
    *(L->elem+L->len)=e;
    L->len++;
    return OK;
  }

  //ElemType * q = L->elem + index;
  ElemType * q = &(L->elem[index]);
  ElemType * p = &(L->elem[L->len]);
  
  for(;p>q;p--)
     *p=*(p-1);

  *p  = e;
  L->len++;
 
  return OK;
}

Status deleteList(Sqlist *L,int index,ElemType *e){
  index--;

  if(index>L->len||index<0){
    printf("overflow!!\n");
    return OVERFLOW;
  }

  if(index == L->len){
    L->len--;
    return OK;
  }

  ElemType * q = L->elem+L->len;
  ElemType * p = &(L->elem[index]);

  while(p<q){
    *p = *(p+1);
    p++;
  }

  L->len--;

  return OK;
}

Status appendList(Sqlist * L,ElemType e){
  
  if(L->len >= SIZE){
    printf("overflow!\n");
    return OVERFLOW;
  }

  *(L->elem + L->len++) = e;

  return OK;
}

Status printList(Sqlist L){
  if(L.len == 0)printf("list is empty!\n");
  ElemType * p = L.elem;
  for(;p<(L.elem+L.len);p++)
     printf("[%d] ",*p);

  printf("\n");
  return OK;
}


int main(){
 int index,e;
 Sqlist L;
 initList(&L);
 printList(L);
 
 //append
 printf("[append] enter value:");
 scanf("%d",&e);
 appendList(&L,e);
 printList(L);
 
 //append
 printf("[append] enter value:");
 scanf("%d",&e);
 appendList(&L,e);
 printList(L);

 //insert
 printf("[insert] enter index:");
 scanf("%d",&index);
 printf("[insert] enter value:");
 scanf("%d",&e);
 insertList(&L,index,e);
 printList(L);

 //delete
 printf("[delete] enter index:");
 scanf("%d",&index);
 deleteList(&L,index,&e);
 printList(L);
 return 0;
}
