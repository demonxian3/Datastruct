#include <stdlib.h>
#include <stdio.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX 100
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct {
  ElemType *base;
  ElemType *top;
} Sqstack;

Status initStack(Sqstack *S){
  S->base = (ElemType*)malloc(MAX*sizeof(ElemType));
  S->top = S->base;
  return OK;
}

Status isEmpty(Sqstack S){
  if(S.top == S.base)return TRUE;
  else return FALSE;
}

int getLength(Sqstack S){
  return S.top - S.base;
}

Status pushStack(Sqstack *S,ElemType e){
  if(getLength(*S)>=MAX)return OVERFLOW;
  *(S->top++) = e; 
  return OK;
}

Status popStack(Sqstack *S,ElemType *e){
  if(isEmpty(*S))return OVERFLOW;
  *e = *(--S->top);
  return OK;
}


