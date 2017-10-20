#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
#define True 1
#define False 0

typedef int VertexType;
typedef struct EBox{
  int mark;
  int ivex,jvex;
  struct EBox *ilink,*jlink;
}EBox;

typedef struct VexBox{
  VertexType data;
  EBox *firstEdge;
}VexBox;

typedef struct{
  VexBox adjmulist[MAXNUM];
  int vexnum,acrnum;
}AMLGraph;

AMLGraph createUDG(){
  AMLGraph G;
  printf("G.vexnum: ");
  scanf("%d",&G.vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();
  
  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.adjmulist[%d].data: ",i);
    scanf("%c",&G.adjmulist[i].data); 
    getchar(); 
    G.adjmulist[i].firstEdge = NULL;   
  }
  
  int a,b;
  for(i=0;i<G.acrnum;i++){
    printf("%d->(i,j): ",i);
    scanf("%d,%d",&a,&b);
    getchar();
    EBox *new=(EBox*)malloc(sizeof(EBox));
    new->ivex = a;
    new->jvex = b;
    new->ilink = G.adjmulist[a].firstEdge;
    new->jlink = G.adjmulist[b].firstEdge;
    G.adjmulist[a].firstEdge = new;
    G.adjmulist[b].firstEdge = new;
  }
  return G;
}
int visited[MAXNUM];

void DFS(AMLGraph G,int v){
  visited[v] = True;
  EBox *w = G.adjmulist[v].firstEdge;
  while(w!=NULL){
    if(w->ivex == v){
      if(!visited[w->jvex])
        DFS(G,w->jvex);
      w=w->ilink;
    }
    else{
      if(!visited[w->ivex])
        DFS(G,w->ivex);
      w=w->jlink;
    }
  }
}

void DFSTraverse(AMLGraph G){
  int i;
  for(i=0;i<G.vexnum;i++)
    visited[i]=False;
  
  for(i=0;i<G.vexnum;i++)
    if(!visited[i])
      DFS(G,i);
}

int main(){
  AMLGraph G = createUDG();
  DFSTraverse(G);
  int i,j=0;
  for(i=0;i<G.vexnum;i++)
    j++;
  printf("total:%d\n",j);
  return 0;
}

