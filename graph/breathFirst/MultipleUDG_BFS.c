#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
#define True 1
#define False 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2



typedef int VertexType;
typedef struct EBox{
  int mark;
  int ivex,jvex;
  struct EBox *ilink,*jlink;
}EBox;

typedef struct VexBox{
  VertexType data;
  EBox *firstEdge;
}VexBox;

typedef struct{
  VexBox adjmulist[MAXNUM];
  int vexnum,acrnum;
}AMLGraph;

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
  if(Q->rear == tmp)Q->rear = Q->front;
  free(tmp);
  return OK;
}
/*========================================*/
/*		    BFST                  */
/*========================================*/
int visited[MAXNUM];

void BFSTraverse(AMLGraph G){
  //init visited
  int i;
  for(i=0;i<G.vexnum;i++)
    visited[i]=False;
  
  //init Queue
  Queue Q;
  initQueue(&Q);

  //breath first traverse
  for(i=0;i<G.vexnum;i++){
    visited[i]=True;
    printf("[%c] ",G.adjmulist[i].data);
    enQueue(&Q,i);
    while(!isEmpty(Q)){
      int w;
      deQueue(&Q,&w);
      EBox *neighbor = G.adjmulist[i].firstEdge;
      while(neighbor != NULL){
        if(neighbor->ivex == w){
          if(!visited[neighbor->jvex]){
            visited[neighbor->jvex]=True;
            printf("[%c] ",G.adjmulist[neighbor->jvex].data);
            enQueue(&Q,neighbor->jvex);
          }
          neighbor = neighbor->ilink;
        }else{
          if(!visited[neighbor->ivex]){
            visited[neighbor->ivex]=True;
            printf("[%c] ",G.adjmulist[neighbor->ivex].data);
            enQueue(&Q,neighbor->ivex);
          }
          neighbor = neighbor->jlink;
        }
      }
    }//while
  }//for
}

/*========================================*/
/*		    Create                */
/*========================================*/
AMLGraph createUDG(){
  AMLGraph G;
  printf("G.vexnum: ");
  scanf("%d",&G.vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();
  
  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.adjmulist[%d].data: ",i);
    scanf("%c",&G.adjmulist[i].data); 
    getchar(); 
    G.adjmulist[i].firstEdge = NULL;   
  }
  
  int a,b;
  for(i=0;i<G.acrnum;i++){
    printf("%d->(i,j): ",i);
    scanf("%d,%d",&a,&b);
    getchar();
    EBox *new=(EBox*)malloc(sizeof(EBox));
    new->ivex = a;
    new->jvex = b;
    new->ilink = G.adjmulist[a].firstEdge;
    new->jlink = G.adjmulist[b].firstEdge;
    G.adjmulist[a].firstEdge = new;
    G.adjmulist[b].firstEdge = new;
  }
  return G;
}

int main(){
  AMLGraph G = createUDG();
  BFSTraverse(G);
  int i,j=0;
  for(i=0;i<G.vexnum;i++)
    j++;
  printf("total:%d\n",j);
  return 0;
}

