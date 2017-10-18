#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
#define True 1
#define False 0

typedef char VertexType;

typedef struct EdgeNode{
  int adjvex;
  struct EdgeNode *nextacr;
}EdgeNode;

typedef struct VNode{
  VertexType data;
  struct EdgeNode *firstedge;
}VNode,AdjList[MAXNUM];

typedef struct {
  AdjList vexs;
  int vexnum,acrnum;
}VNGraph;

int visited[MAXNUM];

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

void DFS(VNGraph G,int v);

void DFSTraverse(VNGraph G){
  int i;
  for(i=0;i<G.vexnum;i++)
    visited[i]=False;

  for(i=0;i<G.vexnum;i++)
    if(!visited[i])
      DFS(G,i);
}

void DFS(VNGraph G,int v){
  EdgeNode * w; 
  for(w=G.vexs[v].firstedge;w!=NULL;w=w->nextacr)
    if(!visited[w->adjvex]);
      DFS(G,w->adjvex);
}

int main(){
  VNGraph G = createDG();
  DFSTraverse(G);
  int i,j=0;
  for(i=0;i<G.vexnum;i++)
    if(visited[i])j++;

  printf("total=%d\n",j);
  return 0;
}
