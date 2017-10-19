#include <stdio.h>
#include <stdlib.h>
#define False 0
#define True  1
#define INFINITY 1000
#define MAXNUM 20

//AdjMatrix
typedef char VertexType;
typedef int VRType;
typedef struct{
  VertexType vexs[MAXNUM];
  VRType acrs[MAXNUM][MAXNUM];
  int acrnum,vexnum;
}MGraph;

//global array:
int visited[MAXNUM];
void DFS(MGraph G,int v);

void DFSTraverse(MGraph G){
  //init array:
  int i;
  for(i=0;i<G.vexnum;i++)
    visited[i] = False;

  //reverse array:
  for(i=0;i<G.vexnum;i++)
    if(!visited[i])
      DFS(G,i);
}

void DFS(MGraph G,int v){
  printf("[%c] ",G.vexs[v]);
  visited[v] = True;
  int w;
  for(w=0;w<G.vexnum;w++)
    if( G.acrs[v][w]!=INFINITY && !visited[w] )
      DFS(G,w);
}

MGraph createUDN(){
  MGraph G;
  printf("G.vexnum:");
  scanf("%d",&G.vexnum);
  printf("G.acrnum:");
  scanf("%d",&G.acrnum);
  getchar();

  //input the vertexs
  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.vexs[%d]:",i);
    scanf("%c",&G.vexs[i]);
    getchar();
  }

  //initialized the matrix
  int j;
  for(i=0;i<G.vexnum;i++)
    for(j=0;j<G.vexnum;j++)
      G.acrs[i][j]=INFINITY;

  //input the matrix
  int k,a,b,c;
  for(k=0;k<G.acrnum;k++){
    printf("[%d]i,j,v: ",k);
    scanf("%d,%d,%d",&a,&b,&c);
    G.acrs[a][b]=c;
    G.acrs[b][a]=c;
  }

  printf("\n\n");
  return G;
}

int main(){
  MGraph G = createUDN();
  DFSTraverse(G);
  int i,sum=0;
  for(i=0;i<G.vexnum;i++)
    if(visited[i])
      sum++;

  printf("the number of the true:%d\n",sum);
  return 0;
}
