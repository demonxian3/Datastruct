#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
#define True 1
#define False 0
#define OK 1
#define ERROR -2

typedef char VertexType;

typedef struct EdgeNode{
  int adjvex;
  struct EdgeNode *nextacr;
}EdgeNode;

typedef struct VNode{
  VertexType data;
  struct EdgeNode *firstedge;
}VNode,AdjList[MAXNUM];

typedef struct{
  AdjList vexs;
  int vexnum,acrnum;
}VNGraph;

/***********************************/
/*		Queue		   */
/***********************************/
typedef int Status;
typedef int ElemType;
typedef struct Qnode{
  ElemType data;
  struct Qnode *next;
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
  if(Q.front == Q.rear)return True;
  else return False;
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
  if(Q->rear == tmp)
    Q->rear = Q->front;
  free(tmp);
  return OK;
}

/***********************************/
/*		BFST		   */
/***********************************/
int visited[MAXNUM];

void BFSTraverse(VNGraph G){
  int i;
  //init visited
  for(i=0;i<G.vexnum;i++)
    visited[i]=False;

  //init Queue
  Queue Q;
  initQueue(&Q);

  //begin breath first traverse
  for(i=0;i<G.vexnum;i++){
    if(!visited[i]){
      printf("[%c] ",G.vexs[i].data); //visit
      visited[i]=True;
      enQueue(&Q,i);
      while(!isEmpty(Q)){
        int w;
        deQueue(&Q,&w);
        EdgeNode *neighbor = G.vexs[w].firstedge;
        while(neighbor!=NULL){
          if(!visited[neighbor->adjvex]){
            printf("[%c] ",G.vexs[neighbor->adjvex].data); //visit
            visited[neighbor->adjvex] = True;
            enQueue(&Q,neighbor->adjvex);
          }
          neighbor = neighbor->nextacr;
        }
      }//while
    }//if
  }//for
}


/***********************************/
/*		Create		   */
/***********************************/
VNGraph createDG(){
  VNGraph G;
  printf("G.vexnum: ");
  scanf("%d",&G.vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();
 
  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.vexs[%d].data: ",i);
    scanf("%c",&G.vexs[i].data);
    G.vexs[i].firstedge = NULL;
    getchar();
  }
 
  int a,b;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]<i,j>: ",i);
    scanf("%d,%d",&a,&b);
    EdgeNode *new = (EdgeNode*)malloc(sizeof(EdgeNode));
    new->adjvex = b;
    new->nextacr = G.vexs[a].firstedge;
    G.vexs[a].firstedge = new;
  }

  return G;
}

int main(){
  VNGraph G = createDG();
  BFSTraverse(G);
  int i,j=0;
  for(i=0;i<G.vexnum;i++)
    if(visited[i])
      j++;

  printf("total=%d\n",j);
  return 0;
}
