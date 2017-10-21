#include <stdio.h>
#include <stdlib.h>
#define False 0
#define True  1
#define INFINITY 1000
#define MAXNUM 20
#define OK 1
#define ERROR 0
#define OVERFLOW -2

//AdjMatrix
typedef char VertexType;
typedef int VRType;
typedef struct{
  VertexType vexs[MAXNUM];
  VRType acrs[MAXNUM][MAXNUM];
  int acrnum,vexnum;
}MGraph;

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

//global array:
int visited[MAXNUM];

void BFSTraverse(MGraph G){
  //initalizated the visited array
  int i;
  for(i=0;i<G.vexnum;i++)
    visited[i]=False;
 
  //create a Queue
  Queue Q;
  initQueue(&Q);
 
  //Traverse each connected components 
  int w,j;
  for(i=0;i<G.vexnum;i++){
    if(!visited[i]){
      printf("[%c] ",G.vexs[i]);
      visited[i] = True;
      enQueue(&Q,i);
      while(!isEmpty(Q)){
        deQueue(&Q,&w);
        for(j=0;j<G.vexnum;j++){
           if(G.acrs[w][j]==1 && !visited[j]){
             printf("[%c] ",G.vexs[j]);
             visited[j]=True;
             enQueue(&Q,j);
           }
        }
      }
    }//if
  }//for
}


/*========================================*/
/*		   Create                 */
/*========================================*/
MGraph createUDN(){
  MGraph G;
  printf("G.vexnum:");
  scanf("%d",&G.vexnum);
  printf("G.acrnum:");
  scanf("%d",&G.acrnum);
  getchar();

  //input the vertexs
  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.vexs[%d]:",i);
    scanf("%c",&G.vexs[i]);
    getchar();
  }

  //initialized the matrix
  int j;
  for(i=0;i<G.vexnum;i++)
    for(j=0;j<G.vexnum;j++)
      G.acrs[i][j]=INFINITY;

  //input the matrix
  int k,a,b,c;
  for(k=0;k<G.acrnum;k++){
    printf("[%d]i,j,v: ",k);
    scanf("%d,%d,%d",&a,&b,&c);
    G.acrs[a][b]=c;
    G.acrs[b][a]=c;
  }
  printf("\n\n");
  return G;
}

int main(){
  MGraph G = createUDN();
  BFSTraverse(G);
  int i,sum=0;
  for(i=0;i<G.vexnum;i++)
    if(visited[i])
      sum++;

  printf("the number of the true:%d\n",sum);
  return 0;
}
