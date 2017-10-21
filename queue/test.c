#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;
typedef struct Qnode{
  ElemType data;
  struct Qnode *new;
}Qnode,*Qlink;

typedef struct{
  Qlink front;
  Qlink rear;
}Queue;

Status initQueue(Queue *Q){
  Q->front = Q->rear = (Qlink)malloc(sizeof(Qnode));
  Q->front->next = NULL;
  return OK;
}

Status isEmpty(Queue Q){
  if(Q.front == Q.rear)return TRUE;
  else return FALSE;
}

Status enQueue(Queue *Q,ElemType e){
  Qlink new = (Qlink)malloc(sizeof(Qnode));
  new->data = e;
  new->next = NULL;
  Q->rear->next = new;
  Q->rear = new;
  return OK;
}

Status deQueue(Queue *Q,ElemType *e){
  if(isEmpty(*Q))return ERROR;
  Qlink tmp = Q->front->next;
  Q->front->next = tmp->next;
  *e = tmp->data;
  if(Q->rear == tmp)Q->rear = Q->front;
  free(tmp);
  return OK;
}

int main(){
  return OK;
}
