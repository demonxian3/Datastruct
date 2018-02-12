#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define LISTSIZE 100

#define	OK 0
#define ERROR 1
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct {
  ElemType * data;
  int len;
} List;

Status initList(List *L){
  L->data = (ElemType*)malloc(LISTSIZE * sizeof(ElemType));
  L->len = 0;
  return OK;
}

Status createNode(List *L, int num){
  if(!L) return ERROR;

  srand(time(0));

  while(num--)
    *(L->data + L->len++) = rand()%100+1;
  
  return OK;
}

Status insertNode(List *L, int i, ElemType e){
  if(!L || i<0 || i>L->len || L->len == LISTSIZE) 
    return ERROR;  
  
  ElemType * q = &(L->data[i]);
  ElemType * p = L->data + L->len;

  while( p > q ){
    *p = *(p-1);
    p--;
  }
 
  *p = e;
  L->len++;
  return OK;
}

Status deleteNode(List *L, int i, ElemType *e){
  if(!L || i<0 || L->len == 0)
    return ERROR;

  ElemType *p = &(L->data[i]);
  ElemType *q = L->data + L->len;

  *e = *p;

  while(p < q){
    *p = *(p+1);
    p++;
  }

  L->len--;
  return OK;
}

Status appendNode(List *L, ElemType e){
  if(!L) return ERROR;
  *(L->data + L->len++) = e;
  return OK;
}


Status clearList(List *L){
  while(L->len--)
    *(L->data + L->len) = 0;
  L->len = 0;
  return OK;
}

int getIndex(List *L, int begin, ElemType e){
  if(begin >= L->len) return ERROR;
  
  int i = begin;
  while( i < L->len){
    if(*(L->data + i) == e)return i;
    i++;
  }

  return OVERFLOW;
}

Status printInfo(){
  system("clear");
  printf("-------------------------------\n");
  printf("|  a = append    d = delete   |\n");
  printf("|  i = insert    r = replace  |\n");
  printf("|  g = getValue  G = getIndex |\n");
  printf("|  c = clear     c = create   |\n");
  printf("============ list =============\n");
}

Status printList(List L){
  if(L.len == 0)printf("List is empty\n");
  printf("List length: %d\n",L.len);

  ElemType *p = L.data;
  while( p < L.data + L.len ){
    printf("[%d] ",*p);
    p++;
  }

  printf("\n");
  return OK;
}

int main(){
  int i,e,v,n;
  char c;
  List L;
  initList(&L);

  while(1){
    printInfo();
    printList(L);
    
    printf("Enter command: ");
    c = getchar();
    
    if(c == 'i'){
      printf("[insert] Enter index: ");	
      scanf("%d",&i);
      printf("[insert] Enter value: ");	
      scanf("%d",&e);
      insertNode(&L, i, e);
      getchar();
    }

    else if(c == 'd'){
      printf("[delete] Enter index: ");
      scanf("%d",&i);
      deleteNode(&L, i ,&e);
      getchar();
    }

    else if(c == 'a'){
      printf("[append] Enter value: ");
      scanf("%d",&e);
      appendNode(&L, e);
      getchar();
    }
 
    else if(c == 'c'){
      printf("[create] Enter number: ");
      scanf("%d",&n);
      createNode(&L, n);
      getchar();
    }

    else if(c == 'g'){
      printf("[getValue] Enter index: ");
      scanf("%d", &i);
      printf("Value is %d\n", *(L.data + i));
      getchar();
      sleep(1);
    }

    else if(c == 'G'){
      printf("[getIndex] Enter begin index: ");
      scanf("%d",&i);
      printf("[getIndex] Enter value: ");
      scanf("%d",&e);
      printf("Index is %d\n",getIndex(&L,i,e));
      getchar();
      sleep(1);
    }

    
    else if(c == 'r'){
      printf("[replace] Enter index: ");
      scanf("%d", &i);
      printf("[getIndex] Enter value: ");
      scanf("%d",&e);
      L.data[i] = e;
      getchar();
    }

    else if(c == 'C'){
      clearList(&L);
    }
  }
}
