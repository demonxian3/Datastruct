#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAXNUM 20

typedef int Bool;
typedef char VertexType;

typedef struct {
   Bool isShow;
   int  indeg;
} indegree;

typedef struct EdgeNode{
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
}ALGraph;

ALGraph createDG(){
  ALGraph G;
  printf("vexnum: ");
  scanf("%d",&G.vexnum);
  printf("acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();

  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.vexs[%d].data: ",i);
    scanf("%c",&G.vexs[i].data);
    getchar();
  }

  int a,b;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]i,j: ",i);
    scanf("%d,%d",&a,&b);
    EdgeNode *new = (EdgeNode*)malloc(sizeof(EdgeNode));
    new->adjvex = b;
    new->nextacr = G.vexs[a].firstedge;
    G.vexs[a].firstedge = new;
  }
  return G;
}

void printDG(ALGraph G){
  int i;
  for(i=0;i<G.vexnum;i++){
    printf("[%i] ",i);
    EdgeNode *tmp = G.vexs[i].firstedge;
    while(tmp){
      printf("-> %d",tmp->adjvex);
      tmp=tmp->nextacr;
    }
    printf("\n");
  }
}

void TopologicalSort(ALGraph G){
  int i,count=0;
  indegree ID[G.vexnum];
  EdgeNode *tmp =(EdgeNode*)malloc(sizeof(EdgeNode));

  for(i=0;i<G.vexnum;i++)
    ID[i].indeg = 0;

  for(i=0;i<G.vexnum;i++){
    tmp = G.vexs[i].firstedge;
    while(tmp){
      ID[tmp->adjvex].indeg++;
      tmp=tmp->nextacr;
    }
    ID[i].isShow = FALSE;
  }
 
  /*debug*/
  //for(i=0;i<G.vexnum;i++)
  //printf("[%d]:%d\n",i,ID[i].indeg);
   
  printf("Topo Logical Sort: ");
  while(count < G.vexnum){
    for(i=0;i<G.vexnum;i++){
      if(!ID[i].isShow && ID[i].indeg==0){
        //output the active
        printf("%c",G.vexs[i].data);
        ID[i].isShow = TRUE;
        //delete the relative
        tmp = G.vexs[i].firstedge;
        while(tmp){
          ID[tmp->adjvex].indeg--;
          tmp=tmp->nextacr;
        }
      }
    }
    count++;
  }
  printf("\n");
}

int main(){
  ALGraph G = createDG();
  TopologicalSort(G);
}
