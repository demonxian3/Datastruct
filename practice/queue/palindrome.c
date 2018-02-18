#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define STACK_MAX 100
#define QUEUE_MAX 100

typedef char ElemType;
typedef int  Status;

typedef struct{
  ElemType * base;
  ElemType * top;
} Stack;

typedef struct{
  ElemType *base;
  int front;
  int rear;
} Queue;

//****************************
//      stack library
//****************************
Status initStack(Stack *s){
  s->base = (ElemType*)malloc(STACK_MAX * sizeof(ElemType));
  s->top = s->base;
  return OK;
}

Status pushStack(Stack *s,ElemType e){
  if(s->top - s->base ==STACK_MAX)return ERROR;
  *s->top=e;
  s->top++;
  return OK;
}

Status popStack(Stack *s,ElemType *e){
  if(s->top - s->base == 0)return ERROR;
  *e = *(--s->top);
  return OK;
}


//****************************
//       queue library
//****************************
Status initQueue(Queue *q){
  q->base = (ElemType*)malloc(QUEUE_MAX * sizeof(ElemType));
  q->front = q->rear = 0;
  return OK;
}

Status enQueue(Queue *q,ElemType e){
  if(q->rear+1%QUEUE_MAX==q->front)return ERROR;
  *(q->base + q->rear) = e;
  q->rear = q->rear+1%QUEUE_MAX;
  return OK;
}

Status deQueue(Queue *q,ElemType *e){
  if((q->rear-q->front+QUEUE_MAX)%QUEUE_MAX==0)
    return ERROR;
  *e = *(q->base + q->front);
  q->front = (q->front+1)%QUEUE_MAX;
  return OK;
}

//思路：将字符串同时存进队列和堆栈中
//      若弹出的队列和堆栈字符相同
//      则该字符串是回文的
Status checkPalindrome(char *str){
  char c1,c2;
  char *p = str;

  Stack S;
  Queue Q;
  
  //init
  initStack(&S);
  initQueue(&Q);
  
  //input
  while(*p!='\n'){
    pushStack(&S,*p);
    enQueue(&Q,*p);
    p++;
  }

  //output
  while(S.top!=S.base){
    popStack(&S,&c1);
    deQueue(&Q,&c2);
    if(c1!=c2)return ERROR;
  }

  return OK;
}

int main(){
   char test[100];
   printf("This is check sentence if it is palindarome\n");
   printf("enter the Ctrl + C to exit programe\n");
   while(1){
     printf("enter a string:");
     fgets(test,100,stdin);
     if(checkPalindrome(test))
       printf("yes,it is\n");
     else 
       printf("no,it isn't\n");
   }
}
