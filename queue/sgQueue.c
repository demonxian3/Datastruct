#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;
typedef struct Qnode{
  int data;
  struct Qnode *next;
} Qnode,*Qlink;

typedef struct {
  Qlink front;
  Qlink rear;
} Queue;

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

Status destoryQueue(Queue *Q){
  while(Q->front != NULL){
    Q->rear = Q->front->next;
    free(Q->front);
    Q->front=Q->rear;
  }
  return OK;
}


int main(){
  int val;
  char sel;
 
  Queue Q;
  initQueue(&Q);
  
  while(1){
    printf("enter you choose[e|d|D]:");
    sel = getchar();

    if(sel == 'e'){
      printf("enter value:");
      scanf("%d",&val);
      enQueue(&Q,val);
    }

    else if(sel == 'd'){
      deQueue(&Q,&val);
      printf("value is %d\n",val);
      sleep(1);
    }
  
    else if(sel == 'D'){
      destoryQueue(&Q);
    }
  } 
}
