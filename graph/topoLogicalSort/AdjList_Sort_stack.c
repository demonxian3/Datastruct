#include "stack.h"

#define MAXNUM 20

typedef int Bool;
typedef char VertexType;

typedef struct EdgeNode{
  int adjvex;
  struct EdgeNode *nextacr;
}EdgeNode;

typedef struct VNode{
  VertexType data;
  EdgeNode *firstedge;
}VNode, AdjList[MAXNUM];

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
    printf("[%d]data: ",i);
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

/*debug*/
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

void FindInDegree(ALGraph G,int *indegree){
  int i;
  for(i=0;i<G.vexnum;i++)
    indegree[i]=0;

  for(i=0;i<G.vexnum;i++){
    EdgeNode *p = G.vexs[i].firstedge;
    while(p){
      indegree[p->adjvex]++;
      p = p->nextacr;
    }
  }
}

Status TopologicalSort(ALGraph G){
  int count,i,k;
  Sqstack S;
  EdgeNode *p = (EdgeNode*)malloc(sizeof(EdgeNode));
  int indegree[MAXNUM];

  initStack(&S);
  FindInDegree(G,indegree);
  
  for(i=0;i<G.vexnum;i++)
    if(!indegree[i])pushStack(&S,i);
  

  printf("Topo Logical Sort:");
  count = 0;
  while(!isEmpty(S)){
    popStack(&S,&k); 
    printf("%c",G.vexs[k].data);
    p = G.vexs[k].firstedge; 
    while(p){
      if( --indegree[p->adjvex] == 0 )pushStack(&S,p->adjvex);
      p = p->nextacr;
    }
    count++;
  }

  printf("\n");
  if(count < G.vexnum){
    printf("Topo have loop!\n");
  }
}


int main(){
  ALGraph G = createDG();
  //printDG(G);
  TopologicalSort(G);
}
