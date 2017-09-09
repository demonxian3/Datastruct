#include <stdio.h>
#include <stdlib.h>

typedef BitTree ElemType;

typedef struct Qnode{
  ElemType data;
  struct Qnode *next;
}Qnode,*Qlink;

typedef struct{
  Qlink front;
  Qlink rear;
} Queue;

typedef struct BitNode{
  int e;
  struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

void initQueue(Queue *Q){
  Q->front = Q->rear = (Qlink)malloc(sizeof(Qnode));
  Q->front->next = NULL;
  return;
}

void enQueue(Queue *Q,ElemType e){
  Qlink new = (Qlink)malloc(sizeof(Qnode));
  new->data = e;
  new->next = NULL;

  Q->rear->next = new;
  Q->rear = new;
  return;
}

void deQueue(Queue *Q,ElemType *e){
  if(Q->front == Q->rear){printf("overflow\n");return;}
   
  Qlink tmp = Q->front->next;
  Q->front->next = tmp->next;
  *e = tmp->data;
  if(tmp == Q->rear)Q->rear = Q->front;
  free(tmp);
  return;
}

void getHead(Queue Q,ElemType *e){
  if(Q.front->next == NULL) *e=-2;
  *e = Q.front->next->data;
  return;
}



int main(){
 Queue Q;
 initQueue(&Q);
 
 //create Tree
 
  
 return;
}
