/*  Adjacency List  */
//In GCC-4.8.1 :This will be appear a segmentfault;
//Missing separate debuginfos, use: debuginfo-install glibc-2.12-1.209.el6_9.2.x86_64
//In GCC-4.8.5 :The program is OK

#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
#define INFINITY 1000

typedef char VertexType;

/*****--->    Directed Graph     <----******/

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
}VNGraph;

/*****--->  Undirected Network   <----******/
typedef struct EdgeNode_w{
  int adjvex;
  int weight;
  struct EdgeNode_w *nextacr;
}EdgeNode_w;

typedef struct VNode_w{
  VertexType data;
  EdgeNode_w *firstedge;
}VNode_w,AdjList_w[MAXNUM];

typedef struct{
  AdjList_w vexs;
  int vexnum,acrnum;
}VNNet;

/************************
 *          DG		*
 * *********************/

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

void printDG(VNGraph G){
  int i;
  printf("========= DG ========\n");
  for(i=0;i<G.vexnum;i++){
    printf("[%d]%c ",i,G.vexs[i].data);
    EdgeNode *tmp = (EdgeNode*)malloc(sizeof(EdgeNode));
    for(tmp=G.vexs[i].firstedge;tmp!=NULL;tmp=tmp->nextacr)
      printf(" --> [%d]  ",tmp->adjvex);
    printf("\n");
  }
}

/************************
 *          UDN		*
 * *********************/
VNNet createUDN(){
  VNNet G;
  printf("G.vexnum: ");
  scanf("%d",&G.vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();

  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.vexs[%d].data: ",i);
    scanf("%c",&G.vexs[i].data);
    getchar();
  }

  int a,b,c;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]<i,j,v>: ",i);
    scanf("%d,%d,%d",&a,&b,&c);
    getchar();
    EdgeNode_w *pos = (EdgeNode_w*)malloc(sizeof(EdgeNode_w));
    EdgeNode_w *neg = (EdgeNode_w*)malloc(sizeof(EdgeNode_w));
    //positive
    pos->adjvex = b;
    pos->weight = c;
    pos->nextacr = G.vexs[a].firstedge;
    G.vexs[a].firstedge = pos;
    //negative
    neg->adjvex = a;
    neg->weight = c;
    neg->nextacr = G.vexs[b].firstedge;
    G.vexs[b].firstedge = neg;
  }
   
  return G;
}

void printUDN(VNNet G){
  int i;
  printf("========= UDN ========\n");
  for(i=0;i<G.vexnum;i++){
    printf("[%d]%c ",i,G.vexs[i].data);
    EdgeNode_w *tmp = (EdgeNode_w*)malloc(sizeof(EdgeNode_w));
    for(tmp=G.vexs[i].firstedge;tmp!=NULL;tmp=tmp->nextacr)
      printf(" --> [%d]%d  ",tmp->adjvex,tmp->weight);
    printf("\n");
  }
}

int main(){

  VNGraph G = createDG();
  printf("\n\n");
  printDG(G);
  
  //VNNet G = createUDN();
  //printf("\n\n");
  //printUDN(G);
  return 0;
}
