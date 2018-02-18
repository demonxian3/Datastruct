#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAX 100

typedef int ElemType;
typedef int Status;

typedef struct{
   ElemType * base;
   ElemType * top;
} Stack;


Status initStack(Stack *s){
  s->base = (ElemType*)malloc(MAX * sizeof(ElemType));
  s->top = s->base;
  return OK;
}

Status Push(Stack *s,ElemType e){
  if( s->top - s->base == MAX )return ERROR;
  *s->top++ = e;
  return OK;
}

Status Pop(Stack *s,ElemType *e){
  if( s->top - s->base == 0 )return ERROR;
  *e = *(--s->top);
  return OK;
}

Status convertion(int val){
  int popvalue;
  Stack s;
  initStack(&s);

  do{
    Push(&s,val%2);
  }while(val/=2);

  while(s.top!=s.base){
    Pop(&s,&popvalue);
    printf("%d",popvalue);
  }
 
  printf("\n");
  return OK;
}

int main(){
  int value;
  
  printf("This is binary convertioner\n");
  printf("enter Ctrl + C to stop programe\n");
  while(1){
    printf("enter a value:");
    scanf("%d",&value);
    convertion(value);
  }
}


/*
8 / 2 = 4 ------ 0  push first
4 / 2 = 2 ------ 0  push second
2 / 2 = 1 ------ 0  push third
1 / 2 = 0 ------ 1  push fourth
*/

/*
1  pop first
0  pop second
0  pop third
0  pop fourth
*/


