/*  Adjacency List  */
#include <stdio.h>
#include <stdlib.h>
#define INFINITY 1000
#define MAXNUM 100

typedef char VertexType;
typedef struct EdgeNode{
  int adjvex;
  struct EdgeNode *nextacr;
}EdgeNode;

typedef struct VNode{
  VertexType data;
  struct EdegeNode *nextacr;
}Vnode,AdjList[MAXNUM];

typedef struct{
  AdjList vexs;
  int vexnum,acrnum;
}VNGraph;

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
    scanf("%d",&G.vexs[i].data);
    getchar();
  }

  return G;
}

int main(){
  VNGraph G = createDG();
  return 0;
}
