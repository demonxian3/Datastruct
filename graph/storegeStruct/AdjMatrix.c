/*  Adjacency matrix  */
//there is a problem in line 101, 102, 106
//but rewrite the code and it revocery
#include <stdio.h>
#include <stdlib.h>
#define INFINITY 1000
#define MAXNUM 20

typedef char VertexType;    
typedef int VRType;
typedef struct{
  VertexType vexs[MAXNUM];
  VRType acrs[MAXNUM][MAXNUM];
  int acrnum,vexnum;
}MGraph;

/****************************
             UDN        
     ====================
      Undirected Network
 ****************************/

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

void printUDN(MGraph G){
  int i,j;
  printf("====== VARTEX ======\n");
  for(i=0;i<G.vexnum;i++)
    printf("(%c) ",G.vexs[i]);
  printf("\n");

  printf("====== MATRIX ======\n");
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

/****************************
 	      DG         
     ====================
        Directed Graph
 ****************************/
MGraph createDG(){
  MGraph G;
  printf("G.vexnum:");
  scanf("%d",&G.vexnum);
  printf("G.acrnum:");
  scanf("%d",&G.acrnum);
  getchar();
  
  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.vexs[%d]:",i);
    scanf("%c",&G.vexs[i]);
    getchar();
  }

  printf("vex: %d\n",G.vexnum);
  printf("acr: %d\n",G.acrnum);

  int j;
  for(i=0;i<G.vexnum;i++)
    for(j=0;j<G.vexnum;j++)
      G.acrs[i][j]=0;

  int a,b;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]--> i,j: ",i);
    scanf("%d,%d",&a,&b);
    getchar();
    G.acrs[a][b]=1;
  }

  printf("\n\n");
  return G;
}

void printDG(MGraph G){
  int i,j;
  printf("======  VERTEX  =====\n");
  for(i=0;i<G.vexnum;i++)
    printf("(%c) ",G.vexs[i]);
  printf("\n");

  printf("======  MATRIX  =====\n");
  for(i=0;i<G.vexnum;i++){
    for(j=0;j<G.vexnum;j++)
       printf("[%d] ",G.acrs[i][j]);
    printf("\n");
  }
}

int main(){
  MGraph G = createUDN();
  printUDN(G);
  
  //MGraph G = createDG();
  //printDG(G);
  return 0;
}
