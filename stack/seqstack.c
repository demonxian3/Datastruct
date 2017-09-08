#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OK 1
#define ERROR 0
#define MAX 100
#define DELAY 1


typedef int ElemType;
typedef int Status;
typedef struct{
  ElemType * base;
  ElemType * top;
} Sqstack;

Status initStack(Sqstack * stack){
  stack->base = (ElemType *)malloc(MAX * sizeof(ElemType));
  stack->top = stack->base;
  return OK;
}

Status stackEmpty(Sqstack stack){
  if(stack.top == stack.base)return OK;
  else return ERROR;
}

int stackLength(Sqstack stack){
  int count = stack.top - stack.base;
  return count;
}

Status getTopValue(Sqstack stack,ElemType * e){
  *e = *(stack.top-1);
  return OK;
}

Status Push(Sqstack *stack,ElemType e){

  if((stack->top - stack->base) >= MAX)return ERROR;
  *(stack->top) = e;
  stack->top++;
  return OK;
}

Status Pop(Sqstack *stack,ElemType * e){

  if(stack->top == stack->base)return ERROR;
  *e = *(stack->top-1);
  stack->top--;
  return OK;
}

Status printStack(Sqstack stack){
  
  if( stackEmpty(stack) ){
    printf("empty\n");
    return OK;
  }

  printf("stack len is %d \n",stackLength(stack));

  while(stack.base < stack.top){
     printf("[%d] ",*(stack.base));
     stack.base++;
  }

  printf("\n");
  return OK;
}

int main(){
  Sqstack stack;
  ElemType value;
  initStack(&stack);

  while(1){
    system("clear");
    printf("p = push\nP = pop\n");
    printf("g = get\ne = exit\n");

    printStack(stack);
    printf("enter a your choose:");
    char sel = getchar();

    if( sel == 'p'){
       printf("enter push value:");
       scanf("%d",&value);
       Push(&stack,value);
    }
    
    else if(sel == 'P'){
       Pop(&stack,&value);
       printf("value:%d is poped\n",value);
       sleep(DELAY);
    }
  
    else if(sel == 'g'){
       getTopValue(stack,&value);
       printf("value is %d\n",value);
       sleep(DELAY);
    }

    else if(sel == 'e'){
       exit(0);
    }

  }
}

