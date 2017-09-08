#include <stdio.h>
#include <stdlib.h>

#define OK 1

typedef int ElemType;
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

Status getHead(Queue Q,ElemType *e){
  if(Q.front->next == NULL) *e=-2;
  *e = Q.front->next->data;
  return OK;
}

void YangHui(int num){
  int i,j,p,s,e;
  
  Queue Q;
  initQueue(&Q);
  enQueue(&Q,1);
  
  for(i=1;i<=num;i++){
    s=0;
    enQueue(&Q,1);
    for(j=1;j<=i+1;j++){
      getHead(Q,&p);
      printf("%4d",p);
      deQueue(&Q,&e);
      enQueue(&Q,s+p);
      s=p;
    }
    printf("\n");
  }
}

int main(){
  int inp;
  printf("enter the low:");
  scanf("%d",&inp);
  YangHui(inp);
  return 0;
}
