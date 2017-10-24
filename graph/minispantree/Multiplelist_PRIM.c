#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR -2
#define MAXNUM 100
#define INFINITY 1000

typedef int VRType;
typedef char VertexType;
typedef struct EBox{
  int weight,mark;
  int ivex,jvex;
  struct EBox *ilink,*jlink;
}EBox;

typedef struct VexBox{
  VertexType data;
  EBox *firstedge;
}VexBox;

typedef struct{
  VexBox mulist[MAXNUM];
  int vexnum,acrnum;
}MLGraph;

struct {
  int adjvex;
  VRType lowcost;
} closedge[MAXNUM];

int getIndex(MLGraph G,VertexType u){
  int i;
  for(i=0;i<G.vexnum;i++) 
    if(G.mulist[i].data == u)
      return i; 
  return ERROR;
}

void MiniSpanTree_PRIM(MLGraph G,VertexType u){
  int k = getIndex(G,u);
  int i,j;
  for(i=0;i<G.vexnum;i++){
    closedge[i].adjvex = k; 
    closedge[i].lowcost = INFINITY;
  }

  EBox *nei = G.mulist[k].firstedge;
  while(nei != NULL){
    if(nei->ivex == k){
      closedge[nei->jvex].lowcost = nei->weight;
      nei = nei->ilink;
    }else{
      closedge[nei->ivex].lowcost = nei->weight;
      nei = nei->jlink;
    }
  }
   
  closedge[k].lowcost = 0;
  
  for(i=1;i<G.vexnum;i++){
    int sel,min = INFINITY;
    for(j=0;j<G.vexnum;j++){
      if(closedge[j].lowcost!=0 && closedge[j].lowcost<min){
        min = closedge[j].lowcost;
        sel = j;
      }
    }
   
    printf("selection: %d -- %d \n",closedge[sel].adjvex,sel);
    closedge[sel].lowcost = 0;
    
    nei = G.mulist[sel].firstedge;
    while(nei!=NULL){ 
      if(nei->ivex == sel){
        if(nei->weight < closedge[nei->jvex].lowcost){
          closedge[nei->jvex].adjvex  = sel;
          closedge[nei->jvex].lowcost = nei->weight;
        }
        nei = nei->ilink;
      }else{
        if(nei->weight < closedge[nei->ivex].lowcost){
          closedge[nei->ivex].adjvex  = sel;
          closedge[nei->ivex].lowcost = nei->weight;
        }
        nei = nei->jlink;
      }
    }
  } 
}


MLGraph createUDN(){
  MLGraph G;
  printf("G.vexnum: ");
  scanf("%d",&G.vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();

  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.mulist[%d].data: ",i);
    scanf("%c",&G.mulist[i].data);
    getchar();
    G.mulist[i].firstedge = NULL;
  }
  
  int a,b,w;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]i,j,w: ",i);
    scanf("%d,%d,%d",&a,&b,&w);
    getchar();
    EBox *new = (EBox*)malloc(sizeof(EBox));
    new->weight = w;
    new->ivex=a;
    new->jvex=b;
    new->mark=0;
    new->ilink = G.mulist[a].firstedge;
    new->jlink = G.mulist[b].firstedge;
    G.mulist[a].firstedge = new;
    G.mulist[b].firstedge = new;
  }
  return G;
}



int main(){
  MLGraph G = createUDN();
  printf("input begin-edge:");
  char c = getchar(); 
  MiniSpanTree_PRIM(G,c);
}
