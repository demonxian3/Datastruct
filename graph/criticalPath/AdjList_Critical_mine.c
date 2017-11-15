/********************************************
 *		Critical Path		    *
 * Author:demon				    *
 * Date:2017-11-15                          *
 * Description:This algorithm have a huge   *
 * issue that the program is extremely dep- *
 * endent on the order of  input vertex     *
 * and the order of input edges and the re- *
 * lationship between..			    *
 * *****************************************/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAXNUM 20
#define INFINITY 1000

typedef int Bool;
typedef char VertexType;
typedef int VRType;

typedef struct EdgeNode{
  int adjvex;
  int weight;
  struct EdgeNode *nextacr;
}EdgeNode;

typedef struct VNode{
  VertexType data;
  EdgeNode *firstedge;
}VNode,AdjList[MAXNUM];

typedef struct {
  AdjList vexs;
  int vexnum,acrnum;
} ALGraph;


/************************
 *          DN		*
 * *********************/

ALGraph createDN(){
  ALGraph G;
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

  int a,b,w;
  for(i=0;i<G.acrnum;i++){
    printf("[%d]i,j,w: ",i);
    scanf("%d,%d,%d",&a,&b,&w);
    EdgeNode *new = (EdgeNode*)malloc(sizeof(EdgeNode));
    new->adjvex = b;
    new->weight = w;
    new->nextacr = G.vexs[a].firstedge;
    G.vexs[a].firstedge = new;
  }
  return G;
}

//此算法可能会因为输入乱序顶点而出bug
void criticalPath(ALGraph G){
  int i;
  int Ve[G.vexnum];
  int Vl[G.vexnum];
  int Ae[G.acrnum];
  int Al[G.acrnum];
  
  EdgeNode *tmp = (EdgeNode*)malloc(sizeof(EdgeNode));

  for(i=0;i<G.vexnum;i++)
    Ve[i] = 0;

  for(i=0;i<G.vexnum;i++)
    Vl[i] = INFINITY;
 
  Ve[0] = 0;	  	    /*源点*/

  for(i=0;i<G.vexnum;i++){   //求Ve数组,
    tmp = G.vexs[i].firstedge;
    while(tmp){
      if( Ve[i]+tmp->weight > Ve[tmp->adjvex] )
        Ve[tmp->adjvex] = Ve[i]+tmp->weight;
      tmp=tmp->nextacr;
    }
  }
  
  Vl[G.vexnum-1] = Ve[G.vexnum-1];     /*汇点*/

  //倒推
  for(i=(G.vexnum-2);i>-1;i--){
    tmp = G.vexs[i].firstedge;
    while(tmp){
      if(Vl[tmp->adjvex]-tmp->weight < Vl[i])
        Vl[i] = Vl[tmp->adjvex] - tmp->weight;
      tmp = tmp->nextacr;
    }
  }

  //求Ae
  int j=0;
  for(i=0;i<G.vexnum;i++){
    tmp = G.vexs[i].firstedge;
    while(tmp){
      Ae[j++] = Ve[i];
      tmp=tmp->nextacr;
    }
  }
  
  //求Al
  j=G.acrnum-1;
  for(i=(G.vexnum-2);i>-1;i--){
    tmp = G.vexs[i].firstedge;
    while(tmp){
      Al[j--] = Vl[tmp->adjvex] - tmp->weight;
      tmp=tmp->nextacr;
    }
  }

  for(i=0;i<G.vexnum;i++)
    printf("Ve[%d] = %d\n",i,Ve[i]);
  printf("\n");

  for(i=0;i<G.vexnum;i++)
    printf("Vl[%d] = %d\n",i,Vl[i]);
  printf("\n");

  for(i=0;i<G.acrnum;i++)
    printf("Ae[%d] = %d\n",i,Ae[i]);
  printf("\n");

  for(i=0;i<G.acrnum;i++)
    printf("Al[%d] = %d\n",i,Al[i]);
  printf("\n");

  //判断是否为关键路径
  for(i=0;i<G.acrnum;i++)
    if( Al[i] == Ae[i] )
      printf("[%d] is critical\n",i);

}

void printDN( ALGraph G ){
  int i,j;
  EdgeNode *tmp = (EdgeNode*)malloc(sizeof(EdgeNode));
  for(i=0;i<G.vexnum;i++){
    printf("[%c]: ",G.vexs[i].data);
    tmp = G.vexs[i].firstedge;
    while(tmp){
      printf("--> %c(%d) ",G.vexs[tmp->adjvex].data,tmp->weight);
      tmp=tmp->nextacr;
    }
    printf("\n");
  }
}

int main(){
  ALGraph G = createDN();
  criticalPath(G);
  //printDN(G); 
}
