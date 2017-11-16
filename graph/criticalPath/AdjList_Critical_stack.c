#include "stack.h"

#define MAXNUM 100
#define INFINITY 1000

typedef char VertexType;
typedef int VRType;

typedef struct EdgeNode{
  int adjvex;
  VRType info;
  struct EdgeNode *nextacr;
}EdgeNode;

typedef struct {
  VertexType data;
  EdgeNode *firstedge;
} AdjList[MAXNUM];

typedef struct {
  AdjList vexs;
  int vexnum,acrnum;
} ALGraph;

/********************
 *        DN        *
 ********************/

ALGraph createDN(){
  ALGraph G;
  printf("G.vexnum: "); 
  scanf("%d",&G.vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();

  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.vexs[%d].data: ",i);
    scanf("%c",&G.vexs[i].data);
    G.vexs[i].firstedge = NULL;     //注意：之前少了这句，代码运行时一直报segment fault,此句很重要
    getchar();
  }    

  int a,b,w;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]i,j,w: ",i);
    scanf("%d,%d,%d",&a,&b,&w);
    EdgeNode *new =(EdgeNode*)malloc(sizeof(EdgeNode));
    new->adjvex = b;
    new->info = w;
    new->nextacr = G.vexs[a].firstedge;
    G.vexs[a].firstedge = new;
  }
  return G;
}

void printDN(ALGraph G){
  int i;
  EdgeNode *tmp = (EdgeNode*)malloc(sizeof(EdgeNode));
  for(i=0;i<G.vexnum;i++){
    printf("[%c]: ",G.vexs[i].data);
    tmp = G.vexs[i].firstedge;
    while(tmp){
      printf(" -> %c(%d) ",G.vexs[tmp->adjvex].data,tmp->info);
      tmp = tmp->nextacr;
    }
    printf("\n");
  }
}

/***********************
 *    Critical Paht    *
 ***********************/
int ve[MAXNUM];
void findIndegree(ALGraph G,int *indegree){
  int i;
  EdgeNode *p = (EdgeNode*)malloc(sizeof(EdgeNode));  
  for(i=0;i<G.vexnum;i++)
    indegree[i]=0;

  for(i=0;i<G.vexnum;i++){
    p = G.vexs[i].firstedge;
    indegree[p->adjvex]++;
    p = p->nextacr;
  }
 
}

Status TopoLogicalSort(ALGraph G,Sqstack *T){
  int i;
  int *indegree = (int*)malloc(G.vexnum*sizeof(int));
  EdgeNode *tmp = (EdgeNode*)malloc(sizeof(EdgeNode));
  Sqstack S;
  initStack(&S);
  findIndegree(G,indegree);
  initStack(T);

  for(i=0;i<G.vexnum;i++)
    printf("%d\n",G.vexs[i].data);
}

Status CriticalPath(ALGraph G){
  Sqstack T;
  if(!TopoLogicalSort(G,&T))
    return ERROR;
  
}


int main(){ 
  ALGraph G = createDN();
  //printDN(G);
  CriticalPath(G);
  return 0;
}
