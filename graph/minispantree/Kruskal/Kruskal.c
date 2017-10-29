#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAXNUM 100
#define INFINITY 1000

typedef int VRType;
typedef char VertexType;

typedef struct {
  VertexType vexs[MAXNUM];
  VRType acrs[MAXNUM][MAXNUM];
  int vexnum,acrnum;
} MGraph;

typedef struct {
  int u,v,w;
}Edge;

void createUDN(MGraph *G){
  printf("G.vexnum:");
  scanf("%d",&G->vexnum);
  printf("G.acrnum:");
  scanf("%d",&G->acrnum);
  getchar();

  int i;
  for(i=0;i<G->vexnum;i++){
    printf("G.vexs[%d]:",i);
    scanf("%c",&G->vexs[i]);
    getchar();
  }

  int j;
  for(i=0;i<G->vexnum;i++)
    for(j=0;j<G->vexnum;j++)
      G->acrs[i][j]=INFINITY;

  int k,a,b,c;
  for(k=0;k<G->acrnum;k++){
    printf("[%d]i,j,v: ",k);
    scanf("%d,%d,%d",&a,&b,&c);
    G->acrs[a][b]=c;
    G->acrs[b][a]=c;
  }
}

void MiniSpanTree_KRUSKAL(MGraph G){
  int i,j,u,v,k;
  int vset[G.vexnum];
  Edge E[G.acrnum];
 
  //Store the Graph all edges;
  k=0;
  for(i=0;i<G.vexnum;i++)
    for(j=0;j<G.vexnum;j++)
      if(G.acrs[i][j] != INFINITY){
        E[k].u=i;
        E[k].v=j;
        E[k].w=G.acrs[i][j];
        k++;
      }

   //Sort the edges;
   //heapsort(E,k,sizeof(E[0]));
   
   //init Auxiliary          辅助数组初始化，每个结点都是一个连通分量
   for(i=0;i<G.vexnum;i++)
      vset[i]=i;

   //kernel algorithm        从权值的小到大顺序访问边，并判断两点是否为同个连通分量
   k=1;j=0;
   while(k<G.vexnum){        //遍历n-1次 n为结点数
     u = vset[E[j].u];
     v = vset[E[j].v];       
     if(u != v){               //如果不在同一个连通分量则选取该边，否则放弃选择
       printf("selection: %d --- %d :%d\n",E[j].u,E[j].v,E[j].w);
       k++;
       for(i=0;i<G.vexnum;i++) //将编号u的所有结点归并于编号v
         if(vset[i] == u)
           vset[i]=u;
     }
   }
}

int main(){
  MGraph G;
  createUDN(&G);
}
