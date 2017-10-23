#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define UNDEFINE -2
#define ERROR 0
#define INFINITY 1000
#define MAXNUM 100

typedef char VertexType;
typedef int VRType;
typedef struct{
  VertexType vexs[MAXNUM];
  VRType acrs[MAXNUM][MAXNUM];
  int acrnum,vexnum;
}MGraph;

struct{
  int adjvex;
  VRType lowcost;
} closedge[MAXNUM];

int getIndex(MGraph G,VertexType u){
  int i;
  for(i=0;i<G.vexnum;i++)
    if(G.vexs[i] == u)
      return i;
  return UNDEFINE;
}

void MiniSpanTree_PRIM(MGraph G,VertexType u){
  int k = getIndex(G,u);
  if(k<0){
    printf("unfind %c index!\n",u);
    return;
  }

  //init closedge;
  int i;
  for(i=0;i<G.vexnum;i++){
    closedge[i].adjvex = k;
    closedge[i].lowcost = G.acrs[k][i];
  }
  closedge[k].lowcost = 0;  //let u join the U
 
  //debug
  for(i=0;i<G.vexnum;i++)
    printf("adj:%d cot:%d\n",closedge[i].adjvex,closedge[i].lowcost);
  
  //beigin n-1 loop:
  for(i=1;i<G.vexnum;i++){
    //select lowcost in closedge which in V-U 
    int j,min=INFINITY,sel=G.vexnum;
    for(j=0;j<G.vexnum;j++)
      if(closedge[j].lowcost!=0 && closedge[j].lowcost<min){
        sel = j;
        min = closedge[j].lowcost;
      }
    //let selection join the U
    printf("select: %d -- %d \n",closedge[sel].adjvex,sel);
    closedge[sel].lowcost = 0;

   //update closedge 
   for(j=0;j<G.vexnum;j++)
     if(G.acrs[sel][j] < closedge[j].lowcost){
       closedge[j].adjvex = sel;
       closedge[j].lowcost = G.acrs[sel][j];
     }
  }
}

MGraph createUDN(){
  MGraph G;
  printf("G.vexnum: "); 
  scanf("%d",&G.vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();

  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.vexs[%d]:",i);
    scanf("%c",&G.vexs[i]);
    getchar();
  }

  int j;
  for(i=0;i<G.vexnum;i++)
    for(j=0;j<G.vexnum;j++)
      G.acrs[i][j]=INFINITY;

  int a,b,w;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]i,j,w: ",i);
    scanf("%d,%d,%d",&a,&b,&w);
    getchar();
    G.acrs[a][b]=w;
    G.acrs[b][a]=w;
  }
  return G;
}

void printUDN(MGraph G){
  int i,j;
  for(i=0;i<G.vexnum;i++){
    for(j=0;j<G.vexnum;j++){
     if(G.acrs[i][j]==INFINITY)
       printf("[N] ");
     else
       printf("[%d] ",G.acrs[i][j]);
    }
    printf("\n");
  }
} 

int main(){
  VertexType c;
  MGraph G = createUDN();
  printf("\n\n");
  printUDN(G);
  printf("\n\ninput a (char)begin-Edge: ");
  scanf("%c",&c);
  getchar();
  MiniSpanTree_PRIM(G,c);
  return 0;
}
