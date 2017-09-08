#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OVERFLOW -2
#define QUEUE_MAX_LEN 1024

typedef int Status;
typedef int ElemType;
typedef struct{
  ElemType * base;
  int front;
  int rear;
} sqQueue;

Status initQueue(sqQueue *Q){
  Q->base = (ElemType*)malloc(QUEUE_MAX_LEN * sizeof(ElemType));
  Q->front = Q->rear = 0;
  return OK;
}

Status isEmpty(sqQueue Q){
  if(Q.front == Q.rear)return TRUE;
  else return FALSE;
}

Status isFull(sqQueue Q){
  if(Q.rear % QUEUE_MAX_LEN +1 == Q.front)return TRUE;
  else return FALSE;
}

Status getLength(sqQueue Q){
  return (Q.rear - Q.front + QUEUE_MAX_LEN) % QUEUE_MAX_LEN;
}

Status getHead(sqQueue Q,ElemType *e){
  if(isEmpty(Q))return ERROR;
  *e = *(Q.base + Q.front);
  return OK;
}

Status enQueue(sqQueue *Q,ElemType e){
  if(isFull(*Q))return OVERFLOW;
  *( Q->base + Q->rear ) = e;
  Q->rear = (Q->rear + 1)%QUEUE_MAX_LEN;
  return OK;
}

Status deQueue(sqQueue *Q,ElemType *e){
  if(isEmpty(*Q))return OVERFLOW;
  *e = *(Q->base + Q->front);
  Q->front = (Q->front +1 )%QUEUE_MAX_LEN;
  return OK;
}

Status printQueue(sqQueue Q){
  if(isEmpty(Q))
    printf("queue is empty\n");

  int len = getLength(Q);
 
  while(Q.rear - Q.front){
    printf("[%d] ",*(Q.base+Q.front));
    Q.front = (Q.front+1)%QUEUE_MAX_LEN;
  }

  printf("\n");
  return OK;
}

int main(){
  char sel;
  int val;

  sqQueue Q;
  initQueue(&Q);

  while(1){
    system("clear");
    printf("\n");
    printQueue(Q);
    printf("e = enQueue\nd = deQueue\n");
    printf("g = getHead\n");
    printf("plese enter your choose[e|d|g]:");
    sel = getchar();

    if(sel == 'e'){
      printf("[EnQueue]enter value:");
      scanf("%d",&val);
      enQueue(&Q,val);
    }

    else if(sel == 'd'){
      deQueue(&Q,&val);
      printf("[DeQueue]value is %d\n",val);
      sleep(1);
    }

    else if(sel == 'g'){
      getHead(Q,&val);
      printf("[HeadVal]value is %d\n",val);
      sleep(1);
    }
  }
  return 0;
}
