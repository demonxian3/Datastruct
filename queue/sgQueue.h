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

typedef struct{
  Qlink front;
  Qlink rear;
} Team, *Queue;

Status initQueue(Queue *Q){
  *Q = (Queue)malloc(sizeof(Team));
  (*Q)->front = (*Q)->rear = (Qlink)malloc(sizeof(Qnode));
  (*Q)->front->next = NULL;
  return OK;
}

Status createQueue(Queue Q,int num){
  srand(time(0));
  while(num--){
    Qlink n = (Qlink)malloc(sizeof(Qnode));
    n->data = rand() % 100 + 1;
    n->next = NULL;
    Q->rear->next = n;
    Q->rear = n;
  }
  return OK;
}

Status isEmpty(Queue Q){
  if(Q->front == Q->rear)return TRUE;
  else return FALSE;
}

Status enQueue(Queue Q,ElemType e){
  Qlink new = (Qlink)malloc(sizeof(Qnode));
  new->data = e;
  new->next = NULL;
  Q->rear->next = new;
  Q->rear = new;
  return OK;
}


Status deQueue(Queue Q,ElemType *e){
  if(isEmpty(Q))return ERROR;
  Qlink tmp = Q->front->next;
  Q->front->next = tmp->next;
  *e = tmp->data;
  if(Q->rear == tmp)Q->rear = Q->front;
  free(tmp);
  return OK;
}

Status destoryQueue(Queue *Q){
  while( (*Q)->front != NULL ){
    (*Q)->rear = (*Q)->front->next;
    free( (*Q)->front );
    (*Q)->front  = (*Q)->rear;
  }
  return OK;
}

Status getHead(Queue Q,int *e){
  if(!Q) return ERROR;
  if(Q->front->next) *e = Q->front->next->data;
  return OK;
}

Status printQueue(Queue Q){
  if(isEmpty(Q)){
    printf("Queue is empty\n");
    return ERROR;
  }

  Qlink p = Q->front;

  while(p = p->next){
    printf("[%d] ",p->data);
  }
  
  printf("\n");
}
