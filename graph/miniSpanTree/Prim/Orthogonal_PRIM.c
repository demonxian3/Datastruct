#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAXNUM 100
#define INFINITY 1000
#define OVERFLOW -2 

typedef int  VRType;
typedef char VertexType;
typedef struct AcrBox{
  VRType weight;
  int tailvex,headvex;
  struct AcrBox *headlink,*taillink;
}AcrBox;

typedef struct VexNode{
  VertexType data;
  struct AcrBox *firstin,*firstout;
}VexNode;

typedef struct{
  VexNode xlist[MAXNUM];
  int acrnum,vexnum;
}OLGraph;

struct {
  VertexType adjvex;
  VRType lowcost;
}closedge[MAXNUM];

int  getIndex(OLGraph G,VertexType u){
  int i;
  for(i=0;i<G.vexnum;i++)
    if(G.xlist[i].data == u)
      return i;

  return OVERFLOW;
}

void MiniSpanTree_PRIM(OLGraph G,VertexType u){
  int i,j,k;
  k = getIndex(G,u);
  if(k<0){
    printf("%c is undefine\n",u);
    return;
  }
  
  for(i=0;i<G.vexnum;i++){
    closedge[i].adjvex = k;
    closedge[i].lowcost = INFINITY;
  }
  
  AcrBox *neighbor = G.xlist[k].firstout;
  while(neighbor != NULL){
    closedge[neighbor->headvex].lowcost = neighbor->weight;
    neighbor = neighbor->taillink;
  }
  closedge[k].lowcost = 0;
 
  for(i=1;i<G.vexnum;i++){ 
    int min=INFINITY,sel;
    for(j=0;j<G.vexnum;j++)
      if(closedge[j].lowcost != 0 && closedge[j].lowcost < min){
        min = closedge[j].lowcost;
        sel = j;
      }
    
    closedge[sel].lowcost=0;
    printf(" %d  -- %d \n",closedge[sel].adjvex,sel);
    neighbor = G.xlist[sel].firstout;
    while(neighbor != NULL){
      if(neighbor->weight < closedge[neighbor->headvex].lowcost ){
        closedge[neighbor->headvex].adjvex = sel;
        closedge[neighbor->headvex].lowcost = neighbor->weight;
      }
      neighbor = neighbor->taillink;
    }
  } 
}


void createDN(OLGraph *G){
  printf("G.vexnum: ");
  scanf("%d",&G->vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G->acrnum);
  getchar();

  int i;
  for(i=0;i<G->vexnum;i++){
    printf("G.xlist[%d].data: ",i);
    scanf("%c",&G->xlist[i].data);
    getchar();
  }

  int a,b,w;
  for(i=0;i<G->acrnum;i++){
    printf("[%d]acr-> i,j,w: ",i);
    scanf("%d,%d,%d",&a,&b,&w);
    getchar();
    AcrBox *new   = (AcrBox*)malloc(sizeof(AcrBox));
    new->weight = w;
    new->tailvex  = a;
    new->headvex  = b;
    new->taillink = G->xlist[a].firstout;
    new->headlink = G->xlist[b].firstin;
    G->xlist[a].firstout = new;
    G->xlist[b].firstin  = new;
  }
}

int main(){
  OLGraph G;
  createDN(&G);
  printf("input begin-edge:");
  char c = getchar();
  MiniSpanTree_PRIM(G,c);
  return;
}
