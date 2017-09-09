#include <stdio.h>
#include <stdlib.h>

#define OK 1

typedef struct BitNode{
  int data;
  struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

typedef BitTree ElemType;
typedef int Status;
typedef struct Qnode{
  ElemType data;
  struct Qnode *next;
}Qnode,*Qlink;

typedef struct {
  Qlink front;
  Qlink rear;
} Queue;

Status initQueue(Queue *Q){
  Q->front = Q->rear = (Qlink)malloc(sizeof(Qnode));
  Q->front->next = NULL;
  return OK;
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
  if(Q->front == Q->rear){
    printf("overflow\n");
    exit(1);
  }

  Qlink tmp = Q->front->next;
  *e = tmp->data;
  Q->front->next = tmp->next;
  if(tmp == Q->rear)Q->rear = Q->front;
  free(tmp);
  return OK;
}

int emptyQueue(Queue Q){
  if(Q.rear == Q.front)return 1;
  else return 0;
}

//Status getHead(Queue Q,ElemType *e){
//  if(Q.front->next == NULL) *e=-2;
//  *e = Q.front->next->data;
//  return OK;
//}

