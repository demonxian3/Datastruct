#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define Bool int
#define MAXNUM 40
#define INFINITY 1000

typedef char VertexType;
typedef int VRType;
typedef struct {
   VertexType vexs[MAXNUM];
   VRType acrs[MAXNUM][MAXNUM];
   int acrnum,vexnum;
} MGraph;

int getIndex(MGraph G,VertexType c){
   int i;
   for(i=0;i<G.vexnum;i++)
      if(G.vexs[i] == c)return i;

   return -1;
}

void ShortestPath_DIJ(MGraph G,VertexType u){
   int i,j,k,v,w;
   Bool final[G.vexnum];	//Storage the state for selected;
   Bool P[G.vexnum][G.vexnum];  //Storage path for per edge;
   VRType Dist[G.vexnum];       //Storage v0 to every edge;
   k = getIndex(G,u);		//k is source edge;

   for(v=0;v<G.vexnum;v++){	//init all varibales
      final[v] = FALSE;
      Dist[v] = G.acrs[k][v];
      for(w=0;w<G.vexnum;w++)
         P[v][w] = FALSE;
      if(Dist[v] < INFINITY){
         P[v][k] = TRUE; 
         P[v][v] = TRUE;
      }
   }

   Dist[k] = 0;		//join the k to the S
   final[k] = TRUE;
    
   //select the shortest path and let the edge join S for per loop
   for(i=0;i<G.vexnum;i++){
      int min = INFINITY;
      for(w=0;w<G.vexnum;w++)
         if(!final[w] && Dist[w]<min){
            min = Dist[w];
            v = w;
         }

      final[v] = TRUE;	//let shortest edge join the S;
      for(w=0;w<G.vexnum;w++){
         if(!final[w] && min+G.acrs[v][w] < Dist[w]){
            Dist[w] = min+G.acrs[v][w];   //update the shortest length
            for(j=0;j<G.vexnum;j++)       //add edge for this path 
               P[w][j] = P[v][j];   
            P[w][w] = TRUE;
         }

      }
   }

   //output the result
   for(i=0;i<G.vexnum;i++){
      printf("to [%c]: ",G.vexs[i]);
      for(j=0;j<G.vexnum;j++)
         if(P[i][j])
            printf("--> %c",G.vexs[j]);
      printf("\n");
   }  
}


MGraph createUDN(){
   int i,j,a,b,w;
   MGraph G;
   
   printf("Enter G.vexnum: "); 
   scanf("%d",&G.vexnum);
   printf("Enter G.acrnum: ");
   scanf("%d",&G.acrnum);
   getchar();

   for(i=0;i<G.vexnum;i++){
      printf("Enter G,vexs[%d]: ",i);
      scanf("%c",&G.vexs[i]);
      getchar();
   }

   for(i=0;i<G.vexnum;i++)
      for(j=0;j<G.vexnum;j++)
         G.acrs[i][j] = INFINITY;
   
   for(i=0;i<G.acrnum;i++){
      printf("[%d]i j v: ",i);
      scanf("%d %d %d",&a,&b,&w);
      getchar();
      a -= 1;
      b -= 1;
      G.acrs[a][b] = w;
      G.acrs[b][a] = w;
  }
 
  return G;
}

void printUDN(MGraph G){
   int i,j;
   
   for(i=0;i<G.vexnum;i++){
      for(j=0;j<G.vexnum;j++)
         if(G.acrs[i][j] == INFINITY)
            printf("[ N] ");
         else
            printf("[%2d] ",G.acrs[i][j]);
      printf("\n");
   }
} 

int main(){
   MGraph G = createUDN();
   printUDN(G);
   printf("Enter source-edge: ");
   char c = getchar();
   ShortestPath_DIJ(G,c);
   return 0;
}
