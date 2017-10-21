//This programe cannot run in kali linux with gcc-6.1.x

#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
#define True 1
#define False 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef char VertexType;
typedef struct AcrBox{
  int headvex,tailvex;
  struct AcrBox *headlink,*taillink;
}AcrBox;

typedef struct{
  VertexType data;
  struct AcrBox *firstin,*firstout;
}VexNode;

typedef struct{
  VexNode xlist[MAXNUM];
  int acrnum,vexnum;
}OLGraph;

/*========================================*/
/*		    Queue                 */
/*========================================*/
typedef int Status;
typedef int ElemType;
typedef struct Qnode{
  ElemType data;
  struct Qnode *next;
}Qnode,*Qlink;

typedef struct{
  Qlink front,rear;
}Queue;

Status initQueue(Queue *Q){
  Q->front = Q->rear = (Qlink)malloc(sizeof(Qnode));
  Q->front->next = NULL;
  return OK;
}

Status isEmpty(Queue Q){
  if(Q.rear == Q.front)return True;
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
  if(Q->rear = tmp)Q->rear = Q->front;
  free(tmp);
  return OK;
}

/*========================================*/
/*		    Create                */
/*========================================*/
OLGraph createDG(){
  OLGraph G;
  printf("G.vexnum: ");
  scanf("%d",&G.vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();

  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.xlist[%d].data:",i);
    scanf("%c",&G.xlist[i].data);
    getchar();
  }

  int a,b;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]acr->i,j: ",i);
    scanf("%d,%d",&a,&b);
    getchar();
    AcrBox *new   = (AcrBox*)malloc(sizeof(AcrBox));
    new->headvex  = b;
    new->tailvex  = a;
    new->headlink = G.xlist[b].firstin;
    new->taillink = G.xlist[a].firstout;
    G.xlist[b].firstin  = new;
    G.xlist[a].firstout = new;
  }
  return G;
}

/*========================================*/
/*		    BFST                  */
/*========================================*/
int visited[MAXNUM];

void BFSTraverse(OLGraph G){
  //init visited
  int i,w,v;
  for(i=0;i<G.vexnum;i++)
    visited[i] = False;
  
  //init Queue
  Queue Q; 
  initQueue(&Q);

  for(i=0;i<G.vexnum;i++){
    if(!visited[i]){
      visited[i]=True;
      printf("[%c] ",G.xlist[i].data);
      enQueue(&Q,i);
      while(!isEmpty(Q)){
        deQueue(&Q,&w);
        AcrBox *neighbor = G.xlist[w].firstout;
        while(neighbor != NULL){
          v = neighbor->headvex;
          if(!visited[v]){
            visited[v]=True;
            printf("[%c] ",G.xlist[v].data);
            enQueue(&Q,v);
          } 
          neighbor = neighbor->taillink;
        }
      }//while  
    }//if 
  }//for
}

int main(){
  OLGraph G = createDG();
  BFSTraverse(G);
  int i,j=0;
  for(i=0;i<G.vexnum;i++)
    if(visited[i])
      j++;

  printf("the number of true is %d\n",j);
  return 0;
}
