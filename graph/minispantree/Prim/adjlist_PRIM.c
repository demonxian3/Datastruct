#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAXNUM 100
#define INFINITY 1000
#define OVERFLOW -2

typedef int VRType;
typedef char VertexType;
typedef struct EdgeNode{
  VRType weight;
  int adjvex;
  struct EdgeNode *nextacr;
}EdgeNode;

typedef struct VNode{
  VertexType data;
  EdgeNode *firstedge;
}VNode,AdjList[MAXNUM];

typedef struct {
  AdjList vexs;
  int vexnum,acrnum;  
}VNGraph;

struct {
  int adjvex;
  VRType lowcost;
} closedge[MAXNUM];

int getIndex(VNGraph G,VertexType u){
  int i;
  for(i=0;i<G.vexnum;i++)
    if(G.vexs[i].data = u)
      return i;
  return OVERFLOW;
}

void MiniSpanTree_PRIM(VNGraph G,VertexType u){
  int i,j;
  int k = getIndex(G,u);
  if(k<0){
    printf("%c is undefin\n",u);
    return;
  }
  
  //init closedge
  for(i=0;i<G.vexnum;i++){
    closedge[i].adjvex = k;
    closedge[i].lowcost = INFINITY;
  }

  //storage neighbor weight
  EdgeNode *neighbor = G.vexs[k].firstedge;
  while(neighbor!=NULL){
    closedge[neighbor->adjvex].lowcost = neighbor->weight;
    neighbor=neighbor->nextacr;
  }
  
  closedge[k].lowcost = 0; 
  
  //begin n-1 loop
  for(i=1;i<G.vexnum;i++){
    //select edge:
    int min = INFINITY,sel;
    for(j=0;j<G.vexnum;j++)
      if(closedge[j].lowcost!=0 && closedge[j].lowcost<min){
         min = closedge[j].lowcost;
         sel = j;
      }
    //append selection
    printf("selection: %d -- %d \n",closedge[sel].adjvex,sel);
    closedge[sel].lowcost = 0;
    
    //update closedge
    neighbor = G.vexs[sel].firstedge;
    while(neighbor!=NULL){
      if(neighbor->weight < closedge[neighbor->adjvex].lowcost){
        closedge[neighbor->adjvex].adjvex = sel;
        closedge[neighbor->adjvex].lowcost = neighbor->weight;
      }  
      neighbor = neighbor->nextacr;
    }
  }
}

void createUDN(VNGraph *G){
  printf("G.vexnum: ");
  scanf("%d",&G->vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G->acrnum);
  getchar();
  
  int i;
  for(i=0;i<G->vexnum;i++){
    printf("G.vexs[%d].data: ",i);
    scanf("%c",&G->vexs[i].data);
    getchar();
  }

  int a,b,w;
  for(i=0;i<G->acrnum;i++){
    printf("[%d]i,j,w: ",i);
    scanf("%d,%d,%d",&a,&b,&w);
    getchar();
    EdgeNode *pos = (EdgeNode*)malloc(sizeof(EdgeNode));
    EdgeNode *neg = (EdgeNode*)malloc(sizeof(EdgeNode));
    //positive
    pos->adjvex = b;
    pos->weight = w;
    pos->nextacr = G->vexs[a].firstedge;
    G->vexs[a].firstedge=pos;
    //negative
    neg->adjvex = a;
    neg->weight = w;
    neg->nextacr = G->vexs[b].firstedge;
    G->vexs[b].firstedge=neg;
  }
}


void printUDN(VNGraph G){
  int i;
  printf("========= UDN ========\n");
  for(i=0;i<G.vexnum;i++){
    printf("[%d]%c ",i,G.vexs[i].data);
    EdgeNode *tmp = (EdgeNode*)malloc(sizeof(EdgeNode));
    for(tmp=G.vexs[i].firstedge;tmp!=NULL;tmp=tmp->nextacr)
      printf(" --> [%d]%d  ",tmp->adjvex,tmp->weight);
    printf("\n");
  }
}

int main(){
  VNGraph G;
  createUDN(&G);
  printUDN(G);
  printf("input start edge(char): ");
  char c = getchar();
  MiniSpanTree_PRIM(G,c);
  return 0;
}
