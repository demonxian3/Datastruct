#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef struct{
  ElemType * elem;
  int last;
} Sqlist;

Sqlist initList(){
  Sqlist L;
  L.elem = (ElemType*)malloc(MAX * sizeof(ElemType));
  if(!L.elem){
    printf("overflow!!\n");
    exit(OVERFLOW);
  }
  L.last = 0;
  return L;
}

Sqlist insertList(Sqlist L,int index,ElemType e){
  index--;
  if( L.last >= MAX || index<0 || index>L.last){
    printf("overflow!\n");
    exit(OVERFLOW);
  }

  if( L.last == index ){
     *(L.elem + L.last++) = e;
     return L;
  }

  ElemType * p = L.elem + L.last;
  ElemType * q = &L.elem[index];
  while(p>q){
    *p = *(p-1);
    p--;
  }

  *p = e;

  L.last++;
  return L;
}

Sqlist deleteList(Sqlist L,int index,ElemType *e){
  index--;
  if( index < 0 || index >=L.last){
    printf("overflow!!\n");
    exit(OVERFLOW);
  }

  if(index == L.last-1){
    L.last--;
    return L;
  }

  ElemType * p = &(L.elem[index]);
  ElemType * q = L.elem + L.last - 1;
 
  while(p<q){
    *p = *(p+1);
    p++;
  }
  L.last--;
  return L;
}


Status printList(Sqlist L){
  if(L.last == 0){
    printf("empty\n");
    return OK;
  }
  ElemType * p = L.elem;
  ElemType * q = L.elem+L.last;
  while(p<q){
   printf("[%d] ",*p);
   p++;
  }

  printf("\n");
  return OK;
}

Sqlist appendList(Sqlist L,ElemType e){
  if(L.last >= MAX){
   printf("overflow!\n");
   exit(OVERFLOW);
  }

  *(L.elem + L.last++) = e;
  return L;
}

int main(){
  int index,e;
  Sqlist L = initList();
  printList(L);

  //append
  printf("[append] enter value:");
  scanf("%d",&e);
  L = appendList(L,e);
  printList(L);

  //append
  printf("[append] enter value:");
  scanf("%d",&e);
  L = appendList(L,e);
  printList(L);

  //insert
  printf("[insert] enter index:");
  scanf("%d",&index);
  printf("[insert] enter value:");
  scanf("%d",&e);
  L = insertList(L,index,e);
  printList(L);

  //delete
  printf("[delete] enter index:");
  scanf("%d",&index);
  L = deleteList(L,index,&e);
  printList(L);

  return 0;
}
