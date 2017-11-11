#include "stack.h"

#define INFINITY 1000
#define MAXNUM 20

typedef VertexType;
typedef int VRType;
typedef struct {
  VertexType vexs[MAXNUM];
  VRType acrs[MAXNUM][MAXNUM];
   int acrnum,vexnum;
}MGraph;

MGraph createDN(){
  MGraph G;
  printf("G.vexnum: ");
  scanf("%d",&G.vexnum);
  printf("G.acrnum: ");
  scanf("%d",&G.acrnum);
  getchar();

  int i;
  for(i=0;i<G.vexnum;i++){
    printf("G.vexs[%d]: ",i);
    scanf("%c",&G.vexs[i]);
    getchar();
  }

  int j;
  for(i=0;i<G.vexnum;i++)
    for(j=0;j<G.vexnum;j++)
      G.acrs[i][j]=INFINITY;

  int a,b,w;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]i j k: ",i);
    scanf("%d %d %d",&a,&b,&w);
    getchar();
    G.acrs[a][b]=w;
  }
  
  return G;
}

void printDN(MGraph G){
  int i,j;
  for(i=0;i<G.vexnum;i++){
    for(j=0;j<G.vexnum;j++){
      if(G.acrs[i][j]!=INFINITY)
        printf("[%d] ",G.acrs[i][j]);
      else
        printf("[N] ");
    }
    printf("\n");
  }
}

void ShortestPath_FLOYD(MGraph G){
  int i,j,k;
  int P[G.vexnum][G.vexnum], D[G.vexnum][G.vexnum];
  for(i=0;i<G.vexnum;i++)
    for(j=0;j<G.vexnum;j++){
      D[i][j] = G.acrs[i][j];
      P[i][j] = -1; 
    }
 
  for(k=0;k<G.vexnum;k++)
    for(i=0;i<G.vexnum;i++)
      for(j=0;j<G.vexnum;j++)
        if(i!=j && D[i][k]+D[k][j] < D[i][j]){
          D[i][j] = D[i][k] + D[k][j]; 
          P[i][j] = k;
        }
 
  //debug
  printf("Final D[][]:\n-----------------\n");
  for(i=0;i<G.vexnum;i++){
    for(j=0;j<G.vexnum;j++){  
      if(D[i][j] != INFINITY)
        printf("[%2d]\t",D[i][j]);
      else
        printf("[ N]\tt");
    }
    printf("\n");
  }

  //debug
  printf("\n\n");
  printf("Final P[][]:\n-----------------\n");
  for(i=0;i<G.vexnum;i++){
    for(j=0;j<G.vexnum;j++)
      printf("[%2d]\t",P[i][j]);
    printf("\n");
  }
  
  //show path
  Node *S = initStack(); 
  for(i=0;i<G.vexnum;i++){
    for(j=0;j<G.vexnum;j++){
       printf("%d to %d: %d",i,j,i);
       if(i==j){
         printf("  w:0\n");
         continue;
       }

       int t=j;                 /* t is k */
       pushStack(S,j);          /* push node */
       while((k=P[i][t])!=-1){
         pushStack(S,k);
         t=k;
       }

       int e;
       while(!isEmpty(S)){      /* pop node */
         popStack(S,&e);
         printf("-> %d",e);
       }
       printf("  w:%d\n",D[i][j]);
    }
    printf("\n");
  }
}

int main(){
   MGraph G = createDN(G);
   //printDN(GP;
   ShortestPath_FLOYD(G);
}

