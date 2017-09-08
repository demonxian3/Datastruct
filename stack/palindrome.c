#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAX 100

typedef char ElemType;
typedef int Status;
typedef struct{
  ElemType * base;
  ElemType * top;
} Stack;

Status initStack(Stack * s){
  s->base = (ElemType*)malloc(MAX * sizeof(ElemType));
  s->top  = s->base;
  return OK;
}

Status Push(Stack *s,ElemType e){
  if(s->top - s->base == MAX)return ERROR;
  *(s->top++)=e;
  return OK;
}

Status Pop(Stack *s,ElemType *e){
  if(s->top - s->base == 0)return ERROR;
  *e = *(--s->top);
  return OK;
}

Status checkPalindrome(char * str){
  char c;
  Stack s;
  char * p = str;
  initStack(&s);

  while( *p != '\n')
    Push(&s,*p++);

  while(s.top != s.base){
    Pop(&s,&c);
    if(c != *str++)return ERROR;
  }

  return OK;
}

int main(){
  char text[100];

  printf("This is check text if it is palindarome\n");
  printf("enter the Ctrl + C to exit progrme\n");
  while(1){
    printf("enter a string:");
    fgets(text,100,stdin);
    if(checkPalindrome(text))
      printf("yes it is palindarome\n");
    else 
      printf("no it isn't palindarome\n");
  }
}
