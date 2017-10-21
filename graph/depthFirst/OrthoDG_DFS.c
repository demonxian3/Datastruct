//This programe cannot run in kali linux with gcc-6.1.x

#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
#define True 1
#define False 0

typedef char VertexType;
typedef struct AcrBox{
  int headvex,tailvex;
  struct AcrBox *headlink,*taillink;
}AcrBox;

typedef struct{
  VertexType data;
  struct AcrBox *firstin,*firstout;
}VexNode;

typedef struct{
  VexNode xlist[MAXNUM];
  int acrnum,vexnum;
}OLGraph;

OLGraph createDG(){
  OLGraph G;
  printf("G.vexnum: ");
  scanf("%d",&G.vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();

  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.xlist[%d].data:",i);
    scanf("%c",&G.xlist[i].data);
    getchar();
  }

  int a,b;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]acr->i,j: ",i);
    scanf("%d,%d",&a,&b);
    getchar();
    AcrBox *new   = (AcrBox*)malloc(sizeof(AcrBox));
    new->headvex  = b;
    new->tailvex  = a;
    new->headlink = G.xlist[b].firstin;
    new->taillink = G.xlist[a].firstout;
    G.xlist[b].firstin  = new;
    G.xlist[a].firstout = new;
  }
  return G;
}

//Depth First Traverse 
int visited[MAXNUM];

void DFS(OLGraph G,int v);

void DFSTraverse(OLGraph G){
  int i;
  for(i=0;i<G.vexnum;i++)
    visited[i] = False;
  
  for(i=0;i<G.vexnum;i++)
    if(!visited[i])
      DFS(G,i);
}

void DFS(OLGraph G,int v){ 
  printf("[%c] ",G.xlist[v].data);
  visited[v] = True;
  AcrBox *w = G.xlist[v].firstout;
  while(w!=NULL){
    if(!visited[w->headvex])
      DFS(G,w->headvex);
    w=w->headlink;
  }
}

int main(){
  OLGraph G = createDG();
  DFSTraverse(G);
  int i,j=0;
  for(i=0;i<G.vexnum;i++)
    if(visited[i])
      j++;

  printf("the number of true is %d\n",j);
  return 0;
}
