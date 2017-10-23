#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXNUM 100
#define INFINITY 1000

typedef char VertexType;
typedef struct EBox{
  int weight;
  int ivex,jvex;
  struct EBox *ilink,*jlink;
}EBox;

typedef struct VexBox{
  VertexType data;
  EBox *firstedge;
}VexBox;

typedef struct{
  VexBox adjmulist[MAXNUM];
  int vexnum,acrnum;
}AMLGraph;

int visited[MAXNUM];

AMLGraph createUDN(){
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
    G.adjmulist[i].firstedge = NULL;
  }

  int a,b,w;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]i,j,w: ");
    scanf("%d,%d,%d",&a,&b,&w);
    getchar();
    EBox *new = (EBox*)malloc(sizeof(EBox));
    new->weight = w;
    new->ivex = a;
    new->jvex = b;
    new->ilink = G.adjmulist[a].firstedge;
    new->jlink = G.adjmulist[b].firstedge;
    G.adjmulist[a].firstedge = new;
    G.adjmulist[b].firstedge = new;
  }
  return G;
}

void createMST(AMLGraph G,int b){
  //init visited
  int i,p;
  for(i=0;i<G.vexnum;i++)
    visited[i]=FALSE;
  
  //init U & T
  //Min-Spanning-Tree's acrnum = vexnum - 1;
  int   Uarray[G.vexnum];
  EBox *Tarray[G.vexnum-1];
  Uarray[0]=b;
  visited[b]=TRUE;  

  p=1;
  while(p<=G.vexnum){    //when U.lenght == T.lenght ,stoping;
    EBox *minedge = (EBox*)malloc(sizeof(EBox));
    minedge->weight = INFINITY;
    minedge->jvex = minedge->ivex = b;
    for(i=0;i<p;i++){    //traverse the Uarray
      EBox *neighbor;
      neighbor = G.adjmulist[i].firstedge;
      while(neighbor != NULL){  //traverse all (i)'s neighbors
        if(neighbor->ivex == i){
          //Amphibious edge
          if(!visited[neighbor->jvex] && neighbor->weight<=minedge->weight)
            minedge = neighbor;
          neighbor = neighbor->ilink;
        }else{
          //Amphibious edge
          if(!visited[neighbor->ivex] && neighbor->weight<=minedge->weight)
            minedge = neighbor;
          neighbor = neighbor->jlink;
        }
      }
      if(!visited[minedge->ivex]){
        Uarray[p]=minedge->ivex;
        visited[minedge->ivex]=TRUE;
      }
      if(!visited[minedge->jvex]){
        Uarray[p]=minedge->jvex;
        visited[minedge->jvex]=TRUE;
      }
      Tarray[p-1] = minedge;     
      p++;
    }
  }
  return;
}

int main(){
  int b;
  printf("input first edge index:");
  scanf("%d",&b);
  AMLGraph G = createUDN();
  createMST(G,b);
  return 0;
}
